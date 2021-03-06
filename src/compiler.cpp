#include "compiler.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "nodes.hpp"
#include "llvm/ADT/APInt.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Type.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/ExecutionEngine/Orc/ThreadSafeModule.h"
#include "llvm/IR/LLVMContext.h"
#include <cstdio>
#include <cassert>
#include <cstring>

Node* verify_type_decl(Node* root, bool func_decl);
Node* verify_type_mismatch(Node* root, Node* current);
Node* verify_expr_types(Node* root, Node* current, char type);
std::string find_expr_type(Node* root);
Node* verify_type_arg(Node* root);
void find_nodes(Node* root, std::vector<Node*> &nodes, std::string node_name, bool deep_search);
Node* compare_args(Node* call, Node* decl, Node* root);
Node* verify_type_bool(Node* root);
Node* expr_is_bool(Node* expr, Node* root);
char get_decl_type(Node* root, std::string name);
char get_func_type(Node* root, std::string name);
Node* verify_type_return(Node* root);
void find_funcs(Node* root, std::vector<Node*> &decls, std::vector<Node*> &defns);
Node* verify_duplicate_decl(Node* root);
Node* check_if_duplicate(std::vector<Node*> decls);
bool change_expr(Node* root, std::string value);
void propagate(std::string name, std::string value, std::vector<Node*> &stmnts);
void recursive_print(Node* root, int indent);
Node* get_child(Node* root, std::string name);
bool should_print(Node* node);
llvm::Value *LogErrorV(const char *Str);

int lex(char const* path) {
	FILE* in = fopen(path, "r");
	if (in == nullptr) {
		printf("[error] unable to open file: %s\n", std::strerror(errno));
		return 1;
	}

	yyscan_t lexer;
	yylex_init_extra(1, &lexer);

	yyset_in(in, lexer);

	while (true) {
		yy::parser::symbol_type s;
		int x = yylex(&s, nullptr, lexer);
		assert(x == 1);
		printf("[output] lexer got symbol: %s (%d, %d).\n", s.name(), s.location.begin.line, s.location.begin.column);
		if (s.kind() == yy::parser::symbol_kind_type::S_YYEOF) {
			break;
		}
	}

	yylex_destroy(lexer);
	fclose(in);

	return 0;
}

int parse(char const* path, std::unique_ptr<Node>& root) {
	FILE* in = fopen(path, "r");
	if (in == nullptr) {
		printf("[error] unable to open file: %s\n", std::strerror(errno));
		return 1;
	}

	yyscan_t lexer;
	yylex_init_extra(1, &lexer);

	yyset_in(in, lexer);

	yy::parser p(lexer, root);
	int x = p.parse();

	yylex_destroy(lexer);
	fclose(in);

	return x;
}

bool verify_ast(Node* root) {
    Node* error;
    
    error = verify_type_decl(root, false);
    if (error) {
        std::cout << "[output] type_decl: " << error->location << std::endl;
        return false;    
    }

    error = verify_type_mismatch(root, root);
    if (error) {
        std::cout << "[output] type_mismatch: " << error->location << std::endl;
        return false;    
    }

    error = verify_type_arg(root);
    if (error) {
        std::cout << "[output] type_arg: " << error->location << std::endl;
        return false;    
    }

    error = verify_type_bool(root);
    if (error) {
        std::cout << "[output] type_bool: " << error->location << std::endl;
        return false;    
    }

    error = verify_type_return(root);
    if (error) {
        std::cout << "[output] type_return: " << error->location << std::endl;
        return false;    
    }

    char main_return_type = get_func_type(root, "main");
    if (main_return_type != 'I') {
        std::cout << "[output] main_function" << std::endl;
        return false;    
    }

    error = verify_duplicate_decl(root);
    if (error) {
        std::cout << "[output] duplicate_decl: " << error->location << std::endl;
        return false;    
    }

	return true;
}

Node* verify_type_decl(Node* root, bool func_decl) {
    Node* node = nullptr;
    bool root_decl = root->node_type == "function_decl" ? true : false;

    if (root->node_type == "type") {
        std::string type = root->children[0]->node_type;
        if (type == "bool" || type == "int" || type == "float")
            return nullptr;
        else if (func_decl && type == "void")
            return nullptr;
        else return root;
    }

    for (size_t i = 0; i < root->children.size(); i++) {
        node = verify_type_decl(root->children[i].get(), root_decl);
        if (node)
            break;
    }

    return node;
}

Node* verify_type_mismatch(Node* root, Node* current) {
    Node* node = nullptr;
    char Type;
    if ((current->node_type == "logical_expression" || current->node_type == "equality" || current->node_type == "comparison")
        && current->children.size() > 1) {
        std::string type = find_expr_type(current);
        if (std::isupper(type[0]))
            Type = type[0];
        else if (type.substr(0,4) == "name")
            Type = get_decl_type(root, type.substr(4, type.length() - 4));
        else
            Type = get_func_type(root, type.substr(4, type.length() - 4));
            
        node = verify_expr_types(root, current, Type);
        if (node)
            return node;    
    }
    
    for (size_t i = 0; i < current->children.size(); i++) {
        node = verify_type_mismatch(root, current->children[i].get());
        if (node)
            break;
    }

    return node;
}

std::string find_expr_type(Node* root) {
    std::string type = "";

    if (root->node_type == "primary") {
        if (std::isupper(root->children[0]->node_type[0]))
            return root->children[0]->node_type;
        else if (root->children[0]->node_type == "name")
            return "name" + root->children[0]->children[0]->node_type;
        else if (root->children[0]->node_type == "function_call") {
            for (size_t i = 0; i < root->children[0]->children.size(); i++)
                if (root->children[0]->children[i]->node_type == "name")
                    return "func" + root->children[0]->children[i]->children[0]->node_type;
        }
    }

    else if (root->node_type == "unary_expression" && root->children.size() == 4) {
        std::string Ty = get_child(root, "type")->children[0]->node_type;
        if (Ty == "int")
            return "Int";
        else if (Ty == "float")
            return "Float";
        else
            return "Bool";
    }

    for (size_t i = 0; i < root->children.size(); i++) {
        type = find_expr_type(root->children[i].get());
        if (!type.empty())
            break;
    }
    return type;
}

Node* verify_expr_types(Node* root, Node* current, char type) {
    Node* node = nullptr;

    if (current->node_type == "primary" && current->children[0]->node_type != "expression") {
        if (std::isupper(current->children[0]->node_type[0])) {
            if (type != current->children[0]->node_type[0])
                return current;
        }
        else if (current->children[0]->node_type == "name") {
            if (type != get_decl_type(root, current->children[0]->children[0]->node_type))
                return current;
        }
        else if (current->children[0]->node_type == "function_call") {
            for (size_t i = 0; i < current->children[0]->children.size(); i++)
                if (current->children[0]->children[i]->node_type == "name") {
                    if (type != get_func_type(root, current->children[0]->children[i]->children[0]->node_type))
                        return current;
                    break;
                }
        }
        return node;
    }

    size_t limit;
    if (current->node_type == "ternary_expression")
        limit = current->children.size() > 2 ? 2 : current->children.size();
    else
        limit = current->children.size();

    for (size_t i = 0; i < limit; i++) {
        node = verify_expr_types(root, current->children[i].get(), type);
        if (node)
            break;
    }

    return node;
}

Node* verify_type_arg(Node* root) {
    std::vector<Node*> decls, calls;
    find_nodes(root, decls, "function_decl", false);
    find_nodes(root, calls, "function_call", false);

    bool paired = false;
    Node* mismatch = nullptr;

    for (size_t i = 0; i < calls.size(); i++)
        for (size_t j = 0; j < decls.size(); j++) {
            if (paired) {
                paired = false;
                break;
            }
            for (size_t k = 0; k < calls[i]->children.size(); k++)
                if (calls[i]->children[k]->node_type == "name")
                    for (size_t l = 0; l < decls[j]->children.size(); l++)
                        if (decls[j]->children[l]->node_type == "name") {
                            if (calls[i]->children[k]->children[0]->node_type == decls[j]->children[l]->children[0]->node_type) {
                                mismatch = compare_args(calls[i], decls[j], root);
                                if (mismatch)
                                    return mismatch;
                                paired = true;
                            }
                            l = decls[j]->children.size();
                            k = calls[i]->children.size();

                        }
        }
    
    return nullptr;
}

void find_nodes(Node* root, std::vector<Node*> &nodes, std::string node_name, bool deep_search) {
    if (root->node_type == node_name) {
        nodes.push_back(root);
        if (!deep_search)
            return;
    }

    for (size_t i = 0; i < root->children.size(); i++)
        find_nodes(root->children[i].get(), nodes, node_name, deep_search);
 
    return;
}

Node* compare_args(Node* call, Node* decl, Node* root) {
    std::vector<Node*> call_args, decl_args;
    find_nodes(decl, decl_args, "declaration", true);

    Node* arg = get_child(call, "function_args");
    while ((arg = get_child(arg, "expression")))
        call_args.push_back(arg);

    if (call_args.size() != decl_args.size())
        return call;

    for (size_t i = 0; i < call_args.size(); i++) {
        std::string decl_type = get_child(decl_args[i], "type")->children[0]->node_type;
        std::string call_type = find_expr_type(call_args[i]);

        if (call_type.length() > 4) {       
            if (call_type.substr(0,4) == "name")
                call_type = get_decl_type(root, call_type.substr(4, call_type.length() - 4));        
            else if (call_type.substr(0,4) == "func")
                call_type = get_func_type(root, call_type.substr(4, call_type.length() - 4));
        }

        if (call_type[0] == 'B' && decl_type == "bool")
            continue;
        else if (call_type[0] == 'I' && decl_type == "int")
            continue;
        else if (call_type[0] == 'F' && decl_type == "float")
            continue;
        else
            return call_args[i];
    }

    return nullptr;
}

Node* verify_type_bool(Node* root) {
    std::vector<Node*> compound, ternary;
    Node* node = nullptr;
    find_nodes(root, compound, "compound_statement", true);
    find_nodes(root, ternary, "ternary_expression", true);

    for (size_t i = 0; i < compound.size(); i++)
        for (size_t j = 0; j < compound[i]->children.size(); j++) {
            std::string name = compound[i]->children[j]->node_type;
            if (name == "expression")
                node = expr_is_bool(compound[i]->children[j].get(), root);
            else if (name == "for_cond") {
                if (compound[i]->children[j]->children.size() == 1)
                    return nullptr;
                int expr_idx = compound[i]->children[j]->children[0]->node_type == "expression" ? 0 : 1;
                node = expr_is_bool(compound[i]->children[j]->children[expr_idx].get(), root);
            }
            if (node)
                return node;
        }

    for (size_t i = 0; i < ternary.size(); i++)
        if (ternary[i]->children.size() > 1) {
            node = expr_is_bool(ternary[i]->children[2].get(), root);
            if (node)
                return node;
        }

    return node;
}

Node* expr_is_bool(Node* expr, Node* root) {
    int size;
    std::string name;
    Node* node = nullptr;
    
    while (true) {
        size = expr->children.size();
        name = expr->node_type;

        if (name == "expression")
            expr = expr->children[0].get();
        else if (name == "ternary_expression" || name == "term" || name == "factor" || name == "unary_expression") {
            if (size > 1) {
                node = expr;
                break;
            }
            expr = expr->children[0].get();
        }
        else if (name == "logical_expression" || name == "equality" || name == "comparison") {
            if (size > 1)
                break;
            expr = expr->children[0].get();
        }
        else if (name == "primary") {
            if (expr->children[0]->node_type == "name") {
                char x = get_decl_type(root, expr->children[0]->children[0]->node_type);
                if (x != 'B')
                    node = expr;
                break;
            }
            else if (expr->children[0]->node_type == "function_call") {
                std::string name;
                for (size_t i = 0; i < expr->children[0]->children.size(); i++)
                    if (expr->children[0]->children[i]->node_type == "name")
                        name = expr->children[0]->children[i]->children[0]->node_type;
                
                char x = get_func_type(root, name);
                if (x != 'B')
                    node = expr;
                break;
            }
            else if (expr->children[0]->node_type == "expression") {
                expr = expr->children[0].get();
                continue;
            }
            else if (expr->children[0]->node_type[0] != 'B')
                node = expr;
            break;
        } 
    }
    return node;
}

char get_decl_type(Node* root, std::string name) {
    if (root->node_type == "declaration") {
        int idx = root->children[0]->node_type == "name" ? 0 : 1;
        if (root->children[idx]->children[0]->node_type == name) {
            if (root->children[!idx]->children[0]->node_type == "bool")
                return 'B';
            else if (root->children[!idx]->children[0]->node_type == "int")
                return 'I';
            else 
                return 'F';
        }
        return '\0';
    }
    
    char x = '\0';
    for (size_t i = 0; i < root->children.size(); i++) {
        x = get_decl_type(root->children[i].get(), name);
        if (x)
            break;
    } 
    return x;
}

char get_func_type(Node* root, std::string name) {
    if (root->node_type == "function_decl") {
        std::string this_name, type;
        for (size_t i = 0; i < root->children.size(); i++) {
            if (root->children[i]->node_type == "name")
                this_name = root->children[i]->children[0]->node_type;
            else if (root->children[i]->node_type == "type")
                type = root->children[i]->children[0]->node_type;
        }
        if (this_name == name) {
            if (type == "bool")
                return 'B';
            else if (type == "int")
                return 'I';
            else if (type == "float")
                return 'F';
            else 
                return 'V';
        }
        return '\0';
    }
    
    char x = '\0';
    for (size_t i = 0; i < root->children.size(); i++) {
        x = get_func_type(root->children[i].get(), name);
        if (x)
            break;
    } 
    return x;
}

Node* verify_type_return(Node* root) {
    std::vector<Node*> defns, ss;
    find_nodes(root, defns, "function_defn", false);

    int block_idx;
    std::string def_type, statement_type;
    char type;
    bool return_expr;

    for (size_t i = 0; i < defns.size(); i++) {
        block_idx = defns[i]->children[0]->node_type == "block" ? 0 : 1;
        for (size_t j = 0; j < defns[i]->children[!block_idx]->children.size(); j++)
            if (defns[i]->children[!block_idx]->children[j]->node_type == "type") {
                def_type = defns[i]->children[!block_idx]->children[j]->children[0]->node_type;
                break;
            }

        if (def_type == "int")
            def_type = "I";
        else if (def_type == "float")
            def_type = "F";
        else if (def_type == "bool")
            def_type = "B";

        find_nodes(defns[i]->children[block_idx].get(), ss, "single_statement", false);
        return_expr = false;
        for (size_t j = 0; j < ss.size(); j++) {
            if (ss[j]->children.size() == 2) {
                return_expr = true;
                if (def_type == "void") {
                    std::cout << "[output] return_statement: " << ss[j]->location << std::endl;
                    exit(1);
                }
                statement_type = find_expr_type(ss[j]->children[0].get());
                if (std::isupper(statement_type[0]))
                    type = statement_type[0];
                else if (statement_type.substr(0,4) == "name")
                    type = get_decl_type(root, statement_type.substr(4, statement_type.length() - 4));
                else
                    type = get_func_type(root, statement_type.substr(4, statement_type.length() - 4));
            
                if (type != def_type[0])
                    return ss[j];
            }
            else if (ss[j]->children[0]->node_type == "return" && def_type != "void") {
                std::cout << "[output] return_statement: " << ss[j]->location << std::endl;
                exit(1);
            }
        }
        if (!return_expr && def_type != "void") {
            std::cout << "[output] return_statement: " << defns[i]->location << std::endl;
            exit(1);
        }

        
    }
    return nullptr;
}

void find_funcs(Node* root, std::vector<Node*> &decls, std::vector<Node*> &defns) {
    if (root->node_type == "function_decl") {
        decls.push_back(root);
        return;
    }
    else if (root->node_type == "function_defn") {
        int idx = root->children[0]->node_type == "function_decl" ? 0 : 1;
        defns.push_back(root->children[idx].get());
        return;
    }

    for (size_t i = 0; i < root->children.size(); i++)
        find_funcs(root->children[i].get(), decls, defns);
 
    return;
}

Node* verify_duplicate_decl(Node* root) {
    std::vector<Node*> decls, defns, blocks;
    Node* error = nullptr;
    find_funcs(root, decls, defns);

    error = check_if_duplicate(decls);
    error = check_if_duplicate(defns);

    if (error)
        return error;

    find_nodes(root, blocks, "block", true);
    
    for (size_t i = 0; i < blocks.size(); i++) {
        decls.clear();
        find_nodes(blocks[i], decls, "declaration", false);
        error = check_if_duplicate(decls);
        if (error)
            return error;
    }

    return nullptr;
}

Node* check_if_duplicate(std::vector<Node*> decls) {
    std::string name1, name2;

    for (size_t i = 0; i < decls.size(); i++)
        for (size_t j = i+1; j < decls.size(); j++) {

            for (size_t k = 0; k < decls[i]->children.size(); k++)
                if (decls[i]->children[k]->node_type == "name") {
                    name1 = decls[i]->children[k]->children[0]->node_type;
                    break;
                }
            
            for (size_t k = 0; k < decls[j]->children.size(); k++)
                if (decls[j]->children[k]->node_type == "name") {
                    name2 = decls[j]->children[k]->children[0]->node_type;
                    break;
                }
        
            if (name1 == name2)
                return decls[j];
        }
    return nullptr;
}

std::unique_ptr<Node> optimize(std::unique_ptr<Node> root) {
    return root;
	std::vector<Node*> blocks, ss, const_decls;
    find_nodes(root.get(), blocks, "block", true);
    std::string name, value;
    
    for (size_t i = 0; i < blocks.size(); i++) {
        ss.clear();
        find_nodes(blocks[i], ss, "single_statement", true);
        for (size_t j = 0; j < ss.size(); j++) {
            for (size_t k = 0; k < ss[j]->children.size(); k++)
                if (ss[j]->children[k]->node_type == "declaration") {
                    value = find_expr_type(ss[j]);
                    name = ss[j]->children[k]->children[0]->node_type == "name" ? ss[j]->children[k]->children[0]->children[0]->node_type
                        : ss[j]->children[k]->children[1]->children[0]->node_type;
                    if (std::isupper(value[0]))
                        propagate(name, value, ss);
                }
        }
    }

    blocks.clear();
    ss.clear();
    find_nodes(root.get(), blocks, "compound_statement", true);
    for (size_t i = 0; i < blocks.size(); i++) {
        if (blocks[i]->children.back()->node_type == "for")
            continue;
        Node* expr;
        expr = blocks[i]->children[0]->node_type == "expression" ? blocks[i]->children[0].get() : blocks[i]->children[1].get();
        if (find_expr_type(expr) == "Btrue" && blocks[i]->children.back()->node_type == "if") {
            for (size_t j = 0; j < blocks[i]->children.size(); j++)
                if (blocks[i]->children[j]->node_type != "block")
                    blocks[i]->children.erase(blocks[i]->children.begin() + j);
        }
        else if (find_expr_type(expr) == "Bfalse")
            blocks[i]->children.clear();
    }

    blocks.clear();
    find_nodes(root.get(), blocks, "ternary_expression", true);
    for (size_t i = 0; i < blocks.size(); i++) {
        if (blocks[i]->children.size() == 1)
            continue;
        if (find_expr_type(blocks[i]->children[2].get()) == "Btrue") {
            for (size_t j = 0; j < blocks[i]->children.size(); j++)
                if (j != 1)
                    blocks[i]->children.erase(blocks[i]->children.begin() + j);
        }
        else if (find_expr_type(blocks[i]->children[2].get()) == "Bfalse") {
            for (size_t j = 1; j < blocks[i]->children.size(); j++)
                blocks[i]->children.erase(blocks[i]->children.begin() + j);
            blocks.push_back(blocks[i]->children[0].get());
        }
    }
    
    return root;
}

void propagate(std::string name, std::string value, std::vector<Node*> &stmnts) {
    for (size_t i = 0; i < stmnts.size(); i++) {
        for (size_t j = 0; j < stmnts[i]->children.size(); j++) {
            if (stmnts[i]->children[j]->node_type == "expression")
                if (find_expr_type(stmnts[i]->children[j].get()) == "name" + name)
                    change_expr(stmnts[i]->children[j].get(), value);
                    
        }
    }
}

bool change_expr(Node* root, std::string value) {
    std::string type = "";

    if (root->node_type == "primary") {
        root->children[0]->node_type = value;
        return true;    
    }

    for (size_t i = 0; i < root->children.size(); i++) {
        if (change_expr(root->children[i].get(), value))
            return true;
    }
    return false;
}

void print_ast(Node* root) {
    recursive_print(root, 0);
	return;
}

void recursive_print(Node* root, int indent) {
    int next_indent = indent;

    if (should_print(root)) {
        next_indent += 2;
        std::cout << root->node_type << " (" << root->location << ") ";

        if (!root->children.empty()) {
            std::cout << "{ ";
            if (root->children.size() > 1 || !root->children[0]->children.empty()) {
                std::cout << std::endl;
            
                for (int j = 0; j < next_indent; j++)
                    std::cout << ' '; 
            }
        }
        else return;
    }

    for (int i = root->children.size() - 1; i >= 0; i--)
        recursive_print(root->children[i].get(), next_indent);

    if (should_print(root)) {

        if (!root->children.empty())
            std::cout << '}' << std::endl;  

        for (int j = 0; j < indent-2; j++)
            std::cout << ' ';  

    }
}

bool should_print(Node* node) {
    std::string name = node->node_type;
    bool should = true;

    if (name == "expression" || name == ";" || name == ")" || name == "(" || name == "}" || name == "{"
        || name == ":" || name == "," || name == "function_list" || name == "function")
        should = false;
    else if (name == "ternary_expression" && node->children.size() == 1)
        should = false;
    else if (name == "logical_expression" && node->children.size() == 1)
        should = false;
    else if (name == "equality" && node->children.size() == 1)
        should = false;
    else if (name == "comparison" && node->children.size() == 1)
        should = false;
    else if (name == "term" && node->children.size() == 1)
        should = false;
    else if (name == "factor" && node->children.size() == 1)
        should = false;
    else if (name == "unary_expression" && node->children.size() == 1)
        should = false;

    return should;
}   

Node* get_child(Node* root, std::string name) {
    int i = 0, limit = root->children.size();

    for (; i < limit; i++)
        if (root->children[i]->node_type == name)
            return root->children[i].get();
    
    //fprintf(stderr, "Error: child not found\n");
    return nullptr;
}

std::unique_ptr<CompilationUnit> compile(Node* root) {
	std::unique_ptr<CompilationUnit> unit = std::make_unique<CompilationUnit>();
	if (!unit->process(root)) {
		return nullptr;
	}
	return unit;
}

void CompilationUnit::initialize() {
	llvm::InitializeNativeTarget();
}

CompilationUnit::CompilationUnit() : context(std::make_unique<llvm::LLVMContext>()), builder(*this->context) {
	this->module = std::make_unique<llvm::Module>("ece467", *this->context);
    this->branched = false;
    this->After = nullptr;
    this->Loop = nullptr; 
}

llvm::Value *LogErrorV(const char *Str) {
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

bool CompilationUnit::process(Node* root) {

    visitor_pattern(root);

	llvm::verifyModule(*this->module, &llvm::errs());
	return true;
}

void CompilationUnit::visitor_pattern(Node* root) {
    if (!root)
        return;

    decls(root);
    defns(root);

    return;
}

void CompilationUnit::decls(Node* root) {
    if (!root)
        return;

    if (root->node_type == "function_decl") {
        func_decl_codegen(root);
        return;
    }

    for (unsigned i = 0; i < root->children.size(); i++)
        decls(root->children[i].get());

    return;
}

void CompilationUnit::defns(Node* root) {
    if (!root)
        return;

    if (root->node_type == "function_defn") {
        func_defn_codegen(root);
        return;    
    }

    for (unsigned i = 0; i < root->children.size(); i++)
        defns(root->children[i].get());

    return;
}

llvm::Function* CompilationUnit::func_decl_codegen(Node* head) {
    std::string type;
    std::vector<Node*> args;
    std::vector<llvm::Type*> Args;
    llvm::FunctionType *FT;

    find_nodes(head, args, "declaration", true);
    for (unsigned i = 0; i < args.size(); i++) {
        type = get_child(args[i], "type")->children[0]->node_type;
        
        if (type == "int")
            Args.push_back(llvm::Type::getInt32Ty(*context));
        else if (type == "float")
            Args.push_back(llvm::Type::getDoubleTy(*context));
        else if (type == "bool")
            Args.push_back(llvm::Type::getInt8Ty(*context));
    }

    type = get_child(head, "type")->children[0]->node_type;

    if (type == "int")
        FT = llvm::FunctionType::get(llvm::Type::getInt32Ty(*context), Args, false);
    else if (type == "float")
        FT = llvm::FunctionType::get(llvm::Type::getDoubleTy(*context), Args, false);
    else if (type == "bool")
        FT = llvm::FunctionType::get(llvm::Type::getInt8Ty(*context), Args, false);
    else
        FT = llvm::FunctionType::get(llvm::Type::getVoidTy(*context), Args, false);

    llvm::Function* F = llvm::Function::Create(FT, llvm::Function::ExternalLinkage, get_child(head, "name")->children[0]->node_type, module.get());

    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto &Arg : F->args())
        Arg.setName(get_child(args[Idx++], "name")->children[0]->node_type);

    return F;
}

llvm::AllocaInst* CompilationUnit::CreateEntryBlockAlloca(llvm::Function* function, std::string name, std::string type) {
    llvm::IRBuilder<> TmpB(&function->getEntryBlock(), function->getEntryBlock().begin());

    if (type == "int")
        return TmpB.CreateAlloca(llvm::Type::getInt32Ty(*context), nullptr, name);
    else if (type == "bool")
        return TmpB.CreateAlloca(llvm::Type::getInt8Ty(*context), nullptr, name);
    else if (type == "float")
        return TmpB.CreateAlloca(llvm::Type::getDoubleTy(*context), nullptr, name);
    
    return nullptr;
}

llvm::Function* CompilationUnit::func_defn_codegen(Node* head) {
    std::string funcName = get_child(get_child(head, "function_decl"), "name")->children[0]->node_type;
    std::vector<Node*> args;    
    llvm::Function *function = module->getFunction(funcName);

    find_nodes(get_child(head, "function_decl"), args, "declaration", true);

    if (!function)
        function = func_decl_codegen(get_child(head, "function_decl"));

    if (!function)
        return nullptr;

    // Create a new basic block to start insertion into.
    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*context, "entry", function);
    builder.SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    unsigned i = 0;
    for (auto &Arg : function->args()) {
        std::string type = get_child(args[i], "type")->children[0]->node_type;
        llvm::AllocaInst* Alloca = CreateEntryBlockAlloca(function, Arg.getName(), type);
        builder.CreateStore(&Arg, Alloca);
        NamedValues[std::string(Arg.getName())] = Alloca;
    }

    if (block_codegen(get_child(get_child(head, "block"), "suite"), function)) {
        llvm::verifyFunction(*function);
        return function;
    }

    // Error reading body, remove function.
    function->eraseFromParent();
    return nullptr;
}

llvm::Value* CompilationUnit::block_codegen(Node* head, llvm::Function* function) {
    if (!head)
        return nullptr;

    Node* stmt = nullptr;
    llvm::Value* RetVal = nullptr;

    if ((stmt = get_child(get_child(head, "statement"), "single_statement")))
        RetVal = single_stmt_codegen(stmt, function);
    else
        RetVal = compound_stmt_codegen(get_child(get_child(head, "statement"), "compound_statement"), function);

    if (get_child(head, "suite"))
        return block_codegen(get_child(head, "suite"), function);
    
    return RetVal;
}

llvm::Value* CompilationUnit::single_stmt_codegen(Node* head, llvm::Function* function) {
    size_t num_child = head->children.size();
    
    if (num_child == 3) {
        if (get_child(head, "declaration")) {
            std::string name = get_child(get_child(head, "declaration"), "name")->children[0]->node_type;
            std::string type = get_child(get_child(head, "declaration"), "type")->children[0]->node_type;
            llvm::AllocaInst* Alloca = CreateEntryBlockAlloca(function, name, type);
            NamedValues[name] = Alloca;
            llvm::Value* exprVal = expression_codegen(get_child(head, "expression"), function);
            return builder.CreateStore(exprVal, Alloca);
        }
        else if (get_child(head, "augmented_assign")) {
            std::string op = get_child(head, "augmented_assign")->children[0]->node_type;
            llvm::Value* RHS = expression_codegen(get_child(head, "expression"), function);
            std::string name = get_child(head, "name")->children[0]->node_type;
            llvm::AllocaInst* LHS = NamedValues[name];
            llvm::Value* load = builder.CreateLoad(LHS, name.c_str());
            if (!LHS)
                return LogErrorV("Unknown variable referenced");

            if (op == "+=") {
                if (LHS->getType()->isDoubleTy())
                    return builder.CreateStore(builder.CreateFAdd(load, RHS, "addtmp"), LHS);
                else return builder.CreateStore(builder.CreateAdd(load, RHS, "addtmp"), LHS);
            }
            else if (op == "-=") {
                if (LHS->getType()->isDoubleTy())
                    return builder.CreateStore(builder.CreateFSub(load, RHS, "subtmp"), LHS);
                else return builder.CreateStore(builder.CreateSub(load, RHS, "subtmp"), LHS);
            }
            else if (op == "*=") {
                if (LHS->getType()->isDoubleTy())
                    return builder.CreateStore(builder.CreateFMul(load, RHS, "multmp"), LHS);
                else return builder.CreateStore(builder.CreateMul(load, RHS, "multmp"), LHS);
            }
            else {
                if (LHS->getType()->isDoubleTy())
                    return builder.CreateStore(builder.CreateFDiv(load, RHS, "divtmp"), LHS);
                else return builder.CreateStore(builder.CreateSDiv(load, RHS, "divtmp"), LHS);
            }
        }
        else {
            llvm::Value* exprVal = expression_codegen(get_child(head, "expression"), function);
            llvm::AllocaInst* var = NamedValues[get_child(head, "name")->children[0]->node_type];
            if (!var)
                return LogErrorV("Unknown variable referenced");
            return builder.CreateStore(exprVal, var);
        }     
    }
        
    else if (num_child == 2) {
        branched = true;
        llvm::Value* ret = expression_codegen(get_child(head, "expression"), function);
        return builder.CreateRet(ret);
    }
    else if (num_child == 1) {
        if (head->children[0]->node_type == "expression")
            return expression_codegen(head->children[0].get(), function);
        else if (head->children[0]->node_type == "return") {
            branched = true;
            return builder.CreateRetVoid();
        }
        else if (head->children[0]->node_type == "continue") {
            if (!Loop)
                LogErrorV("Continue statement not within loop body");                
            return builder.CreateBr(Loop);
        }
        else {
            if (!After)
                LogErrorV("Break statement not within loop body"); 
            branched = true;
            Loop = llvm::BasicBlock::Create(*context, "break", function);
            return builder.CreateBr(After);
        }
    }

    return nullptr;
}

llvm::Value* CompilationUnit::compound_stmt_codegen(Node* head, llvm::Function* function) {
    if (get_child(head, "if"))
        return if_codegen(get_child(head, "expression"), get_child(head, "block"), nullptr, function);
    else if (get_child(head, "for"))
        return for_codegen(head, function);
    else
        return while_codegen(head, function);

    return nullptr;
}

llvm::Value* CompilationUnit::expression_codegen(Node* head, llvm::Function* function) {
    if (!head)
        return nullptr;

    if (head->node_type == "primary") {
        if (head->children.size() == 3)
            return expression_codegen(get_child(head, "expression"), function);
        else if (head->children[0]->node_type == "name") {
            std::string name = head->children[0]->children[0]->node_type;
            return builder.CreateLoad(NamedValues[name], name.c_str());
        }
        else if (head->children[0]->node_type == "function_call") {
            llvm::Function* CalleeF = module->getFunction(get_child(head->children[0].get(), "name")->children[0]->node_type);
            if (!CalleeF)
                return LogErrorV("Unknown function referenced");
            
            std::vector<Node*> Args;
            Node* arg;
            if ((arg = get_child(head->children[0].get(), "function_args"))) {
                while(arg) {
                    Args.push_back(get_child(arg, "expression"));
                    arg = get_child(arg, "function_args");
                }
            }
            std::vector<llvm::Value*> ArgsV;
            for (unsigned i = 0, e = Args.size(); i != e; ++i) {
                ArgsV.push_back(expression_codegen(Args[i], function));
                if (!ArgsV.back())
                    return nullptr;
            }
            if (CalleeF->getReturnType()->isVoidTy())
                return builder.CreateCall(CalleeF, ArgsV);
            return builder.CreateCall(CalleeF, ArgsV, "calltmp");
        }
        else if (head->children[0]->node_type == "Btrue")
            return llvm::ConstantInt::get(llvm::Type::getInt8Ty(*context), 1, false);
        else if (head->children[0]->node_type == "Bfalse")
            return llvm::ConstantInt::get(llvm::Type::getInt8Ty(*context), 0, false);
        else if (head->children[0]->node_type[0] == 'I') {
            int val = std::stoi(head->children[0]->node_type.substr(1, head->children[0]->node_type.length() - 1));
            return llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context), val, true);
        }
        else {
            float val = std::stof(head->children[0]->node_type.substr(1, head->children[0]->node_type.length() - 1));
            return llvm::ConstantFP::get(llvm::Type::getDoubleTy(*context), val);
        }
    }

    else if (head->node_type == "ternary_expression" && head->children.size() > 1) {
        return ternary_codegen(head->children[2].get(), head->children[1].get(), head->children[0].get(), function);
    }
    else if (head->node_type == "logical_expression" && head->children.size() > 1) {
        if (head->children[2]->node_type == "&&")
            return builder.CreateAnd(expression_codegen(head->children[0].get(), function), expression_codegen(head->children[1].get(), function));
        else
            return builder.CreateOr(expression_codegen(head->children[0].get(), function), expression_codegen(head->children[1].get(), function));
    }
    else if (head->node_type == "equality" && head->children.size() > 1) {
        llvm::Value* LHS = expression_codegen(head->children[0].get(), function);
        llvm::Value* RHS = expression_codegen(head->children[1].get(), function);
        if (head->children[2]->node_type == "==") {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFCmpUEQ(LHS, RHS);
            else return builder.CreateICmpEQ(LHS, RHS);
        }
        else {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFCmpUNE(LHS, RHS);
            else return builder.CreateICmpNE(LHS, RHS);
        }
    }
    else if (head->node_type == "comparison" && head->children.size() > 1) {
        llvm::Value* LHS = expression_codegen(head->children[0].get(), function);
        llvm::Value* RHS = expression_codegen(head->children[1].get(), function);
        if (head->children[2]->node_type == "<") {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFCmpULT(RHS, LHS);
            else return builder.CreateICmpSLT(RHS, LHS);
        }
        else if (head->children[2]->node_type == "<=") {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFCmpULE(RHS, LHS);
            else return builder.CreateICmpSLE(RHS, LHS);
        }
        else if (head->children[2]->node_type == ">") {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFCmpUGT(RHS, LHS);
            else return builder.CreateICmpSGT(RHS, LHS);
        }
        else {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFCmpUGE(RHS, LHS);
            else return builder.CreateICmpSGE(RHS, LHS);
        }
    }
    else if (head->node_type == "term" && head->children.size() > 1) {
        llvm::Value* LHS = expression_codegen(head->children[0].get(), function);
        llvm::Value* RHS = expression_codegen(head->children[1].get(), function);
        if (head->children[2]->node_type == "+") {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFAdd(LHS, RHS, "addtmp");
            else return builder.CreateAdd(LHS, RHS, "addtmp");
        }
        else {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFSub(RHS, LHS, "subtmp");
            else return builder.CreateSub(RHS, LHS, "subtmp");
        }
    }
    else if (head->node_type == "factor" && head->children.size() > 1) {
        llvm::Value* LHS = expression_codegen(head->children[0].get(), function);
        llvm::Value* RHS = expression_codegen(head->children[1].get(), function);
        if (head->children[2]->node_type == "*") {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFMul(LHS, RHS, "multmp");
            else return builder.CreateMul(LHS, RHS, "multmp");
        }
        else {
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFDiv(RHS, LHS, "divtmp");
            else return builder.CreateSDiv(RHS, LHS, "divtmp");
        }
    }
    else if (head->node_type == "unary_expression" && head->children.size() > 1) {
        if (head->children[1]->node_type == "-") {
            llvm::Value* LHS = expression_codegen(head->children[0].get(), function);
            if (LHS->getType()->isDoubleTy())
                return builder.CreateFNeg(LHS, "negtmp");
            else return builder.CreateNeg(LHS,"negtmp");
        }
        else {
            std::string ty = get_child(head, "type")->children[0]->node_type;
            llvm::Value* LHS = expression_codegen(get_child(head, "primary"), function);
            if (ty == "float" && (LHS->getType()->isIntegerTy()))
                return builder.CreateSIToFP(LHS, llvm::Type::getDoubleTy(*context), "fcasttmp");
            else if (ty == "int" && (LHS->getType()->isDoubleTy()))
                return builder.CreateFPToSI(LHS, llvm::Type::getInt32Ty(*context), "icasttmp");
        }
    }
        
    return expression_codegen(head->children[0].get(), function);

}

llvm::Value* CompilationUnit::if_codegen(Node* Cond, Node* Then, Node* Else, llvm::Function* function) {
    llvm::Value* CondV = expression_codegen(Cond, function);
    if (!CondV)
        return nullptr;

    llvm::BasicBlock *ThenBB = llvm::BasicBlock::Create(*context, "then", function);
    llvm::BasicBlock *ElseBB = llvm::BasicBlock::Create(*context, "else");
    llvm::BasicBlock *MergeBB = llvm::BasicBlock::Create(*context, "ifcont");

    builder.CreateCondBr(CondV, ThenBB, ElseBB);
    builder.SetInsertPoint(ThenBB);

    llvm::Value* ThenV;
    this->branched = false;

    if (Then->node_type == "expression")
        ThenV = expression_codegen(Then, function);
    else if (Then->node_type == "block")
        ThenV = block_codegen(get_child(Then, "suite"), function);

    if (!ThenV)
        return nullptr;

    if (!this->branched)
        builder.CreateBr(MergeBB);
    else
        this->branched = false;

    ThenBB = builder.GetInsertBlock();

    function->getBasicBlockList().push_back(ElseBB);
    builder.SetInsertPoint(ElseBB);

    llvm::Value* ElseV;

    if (!Else)
        ElseV = nullptr;
    else if (Else->node_type == "expression")
        ElseV = expression_codegen(Else, function);
    else if (Else->node_type == "block")
        ElseV = block_codegen(get_child(Else, "suite"), function);

    if (!this->branched)
        builder.CreateBr(MergeBB);
    else
        this->branched = false;

    ElseBB = builder.GetInsertBlock();

    function->getBasicBlockList().push_back(MergeBB);
    builder.SetInsertPoint(MergeBB);

    return ElseV;
}

llvm::Value* CompilationUnit::ternary_codegen(Node* Cond, Node* Then, Node* Else, llvm::Function* function) {
    llvm::Value* CondV = expression_codegen(Cond, function);
    if (!CondV)
        return nullptr;

    llvm::BasicBlock *ThenBB = llvm::BasicBlock::Create(*context, "then", function);
    llvm::BasicBlock *ElseBB = llvm::BasicBlock::Create(*context, "else");
    llvm::BasicBlock *MergeBB = llvm::BasicBlock::Create(*context, "ifcont");

    builder.CreateCondBr(CondV, ThenBB, ElseBB);
    builder.SetInsertPoint(ThenBB);

    llvm::Value* ThenV;
    branched = false;

    ThenV = expression_codegen(Then, function);

    if (!ThenV)
        return nullptr;

    if (!branched)
        builder.CreateBr(MergeBB);
    else
        branched = false;

    ThenBB = builder.GetInsertBlock();

    function->getBasicBlockList().push_back(ElseBB);
    builder.SetInsertPoint(ElseBB);

    llvm::Value* ElseV;

    ElseV = expression_codegen(Else, function);

    if (!branched)
        builder.CreateBr(MergeBB);
    else
        branched = false;

    ElseBB = builder.GetInsertBlock();

    function->getBasicBlockList().push_back(MergeBB);
    builder.SetInsertPoint(MergeBB);
    llvm::PHINode *PN = builder.CreatePHI(llvm::Type::getInt32Ty(*context), 2, "iftmp");

    PN->addIncoming(ThenV, ThenBB);
    PN->addIncoming(ElseV, ElseBB);

    return PN;
}

llvm::Value* CompilationUnit::for_codegen(Node* head, llvm::Function* function) {
    this->branched = false;
    single_stmt_codegen(get_child(get_child(head, "for_init"), "single_statement"), function);

    // Make the new basic block for the loop header, inserting after current
    // block.
    llvm::BasicBlock *LoopBB = llvm::BasicBlock::Create(*context, "loop", function);
    llvm::Value* InitCond = expression_codegen(get_child(get_child(head, "for_cond"), "expression"), function);
    llvm::BasicBlock *AfterBB = llvm::BasicBlock::Create(*context, "afterloop", function);

    Loop = LoopBB;
    After = AfterBB;

    if (!this->branched)
        builder.CreateCondBr(InitCond, LoopBB, AfterBB);
    else
        this->branched = false;

    // Start insertion in LoopBB.
    builder.SetInsertPoint(LoopBB);

    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    if (!block_codegen(get_child(get_child(head, "block"), "suite"), function))
        return nullptr;

    // Emit the step value.
    single_stmt_codegen(get_child(get_child(head, "for_act"), "single_statement"), function);
    llvm::Value* EndCond = expression_codegen(get_child(get_child(head, "for_cond"), "expression"), function);

    // Insert the conditional branch into the end of LoopEndBB.
    if (!this->branched)
        builder.CreateCondBr(EndCond, LoopBB, AfterBB);
    else
        this->branched = false;

    // Any new code will be inserted in AfterBB.
    builder.SetInsertPoint(AfterBB);
    
    Loop = nullptr;
    After = nullptr;

    // for expr always returns 0.0.
    return llvm::Constant::getNullValue(llvm::Type::getInt32Ty(*context));
}

llvm::Value* CompilationUnit::while_codegen(Node* head, llvm::Function* function) {
    llvm::BasicBlock *LoopBB = llvm::BasicBlock::Create(*context, "loop", function);
    llvm::BasicBlock *AfterBB = llvm::BasicBlock::Create(*context, "afterloop", function);
    Loop = LoopBB;
    After = AfterBB;

    llvm::Value* InitCond = expression_codegen(get_child(head, "expression"), function);

    builder.CreateCondBr(InitCond, LoopBB, AfterBB);
    // Start insertion in LoopBB.
    builder.SetInsertPoint(LoopBB);

    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    if (!block_codegen(get_child(get_child(head, "block"), "suite"), function))
        return nullptr;

    if (LoopBB != Loop)
        builder.SetInsertPoint(Loop);

    llvm::Value* EndCond = expression_codegen(get_child(head, "expression"), function);
    // Insert the conditional branch into the end of LoopEndBB.
    builder.CreateCondBr(EndCond, LoopBB, AfterBB);

    // Any new code will be inserted in AfterBB.
    builder.SetInsertPoint(AfterBB);

    Loop = nullptr;
    After = nullptr;
    
    return llvm::Constant::getNullValue(llvm::Type::getInt32Ty(*context));
}

std::error_code CompilationUnit::dump(std::string path) {
	std::error_code ec;
	llvm::raw_fd_ostream out(path, ec, llvm::sys::fs::OpenFlags::F_None);
	this->module->print(out, nullptr);
	return ec;
}

int CompilationUnit::run(int argc, char** argv) {
	if (this->main == nullptr) {
		return -1;
	}
	return this->main(argc, argv);
}

std::optional<llvm::Error> CompilationUnit::build() {
	llvm::Expected<std::unique_ptr<llvm::orc::LLJIT>> jit = llvm::orc::LLJITBuilder{}.create();
	if (!jit) {
		return jit.takeError();
	}
	llvm::Error e = (*jit)->addIRModule(llvm::orc::ThreadSafeModule { std::move(this->module), std::move(this->context) });
	if (e) {
		return e;
	}
	llvm::Expected<llvm::JITEvaluatedSymbol> entry = (*jit)->lookup("main");
	if (!entry) {
		return entry.takeError();
	}
	this->main = reinterpret_cast<int(*)(int, char**)>(entry->getAddress());
	return std::nullopt;
}
