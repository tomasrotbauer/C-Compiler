#ifndef ECE467_COMPILER_HPP_INCLUDED
#define ECE467_COMPILER_HPP_INCLUDED

#include "llvm/Support/Error.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include <string>
#include <memory>
#include <optional>
#include <functional>
#include <system_error>

class Node;
class CompilationUnit;

int lex(char const*);
int parse(char const*, std::unique_ptr<Node>&);
bool verify_ast(Node*);
std::unique_ptr<Node> optimize(std::unique_ptr<Node>);
void print_ast(Node*);
std::unique_ptr<CompilationUnit> compile(Node*);

class CompilationUnit {
public:
	static void initialize();

	CompilationUnit();
	bool process(Node*);
	std::optional<llvm::Error> build();
	std::error_code dump(std::string);
	int run(int, char**);
    void visitor_pattern(Node* root);
    void decls(Node* root);
    void defns(Node* root);
    llvm::AllocaInst* CreateEntryBlockAlloca(llvm::Function* function, std::string name, std::string type);
    llvm::Function* func_decl_codegen(Node* head);
    llvm::Function* func_defn_codegen(Node* head);
    llvm::Value* block_codegen(Node* head, llvm::Function* function);
    llvm::Value* single_stmt_codegen(Node* head, llvm::Function* function);
    llvm::Value* compound_stmt_codegen(Node* head, llvm::Function* function);
    llvm::Value* expression_codegen(Node* head, llvm::Function* function);
    llvm::Value* if_codegen(Node* Cond, Node* Then, Node* Else, llvm::Function* function);
    llvm::Value* ternary_codegen(Node* Cond, Node* Then, Node* Else, llvm::Function* function);
    llvm::Value* for_codegen(Node* head, llvm::Function* function);
    llvm::Value* while_codegen(Node* head, llvm::Function* function);

private:
	using MainFunction = std::function<int(int, char**)>;

    bool branched;
    llvm::BasicBlock *After;
    llvm::BasicBlock *Loop;

	std::unique_ptr<llvm::LLVMContext> context;
	llvm::IRBuilder<> builder;
	std::unique_ptr<llvm::Module> module;
    std::map<std::string, llvm::AllocaInst *> NamedValues;
	MainFunction main;
};

#endif // ECE467_COMPILER_HPP_INCLUDED
