%code requires {

// this will be added to your parser.hpp file

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

#include <memory>

class Node;

}

%code {

// this will be added to your parser.cpp file

#include "lexer.hpp"
#include "nodes.hpp"

static yy::parser::symbol_type yylex(yyscan_t);

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const&, Args&&...);

void grow_tree(std::unique_ptr<Node> &root, std::vector<std::string> claim);

}

/* see https://www.gnu.org/software/bison/manual/html_node/Declarations.html */

%require "3.6"
%language "c++"
%locations
%param { yyscan_t lexer }
%parse-param { std::unique_ptr<Node>& root }
%verbose
%define api.value.type variant
%define api.token.constructor
%define parse.trace
%define parse.assert

%token <std::string> TOK_IDENTIFIER
%token <std::string> TOK_TYPE
%token <int> TOK_INTEGER
%token <float> TOK_FLOAT
%token <bool> TOK_TRUE
%token <bool> TOK_FALSE
%precedence <char> TOK_LPAREN <char> TOK_RPAREN
%token <char> TOK_LBRACE
%token <char> TOK_RBRACE
%token <std::string> TOK_EQ
%token <std::string> TOK_NE
%token <char> TOK_LT
%token <char> TOK_GT
%token <std::string> TOK_LE
%token <std::string> TOK_GE
%token <char> TOK_PLUS
%token <char> TOK_MINUS
%token <char> TOK_STAR
%token <char> TOK_SLASH
%token <std::string> TOK_LOG_AND
%token <std::string> TOK_LOG_OR
%token <std::string> TOK_IF
%token <std::string> TOK_WHILE
%token <std::string> TOK_FOR
%token <std::string> TOK_BREAK
%token <std::string> TOK_CONTINUE
%token <std::string> TOK_RETURN
%token <std::string> TOK_PLUS_ASSIGN
%token <std::string> TOK_MINUS_ASSIGN
%token <std::string> TOK_STAR_ASSIGN
%token <std::string> TOK_SLASH_ASSIGN
%token <char> TOK_COMMA
%token <char> TOK_SEMICOLON
%token <char> TOK_COLON
%token <char> TOK_QUESTION_MARK
%token <char> TOK_ASSIGN

%left TOK_COMMA

%right TOK_ASSIGN
%right TOK_QUESTION_MARK TOK_COLON

%left TOK_LOG_OR 
%left TOK_LOG_AND
%left TOK_EQ TOK_NE
%left TOK_GT TOK_GE TOK_LT TOK_LE
%left TOK_PLUS TOK_MINUS
%left TOK_STAR TOK_SLASH

%type <Node*> root
%start root

%%

root
	: function_list {this->root->node_type = "root";}
	;

function_list
    : function function_list {
        std::vector<std::string> claim {"function", "function_list"};
        this->root->children.push_back(make_node<Node>(@$, "function_list"));
        grow_tree(root, claim);
    }
    | function {
        std::vector<std::string> claim {"function"};
        this->root->children.push_back(make_node<Node>(@$, "function_list"));
        grow_tree(root, claim);
    }
    ;

function
    : function_decl TOK_SEMICOLON {
        std::vector<std::string> claim {"function_decl"};
        this->root->children.push_back(make_node<Node>(@$, "function"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ";"));
    }
    | function_defn {
        std::vector<std::string> claim {"function_defn"};
        this->root->children.push_back(make_node<Node>(@$, "function"));
        grow_tree(root, claim);
    }
    ;

function_decl
    : type name TOK_LPAREN parameter_list TOK_RPAREN {
        std::vector<std::string> claim {"type", "name", "parameter_list"};
        this->root->children.push_back(make_node<Node>(@$, "function_decl"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    | type name TOK_LPAREN TOK_RPAREN {
        std::vector<std::string> claim {"type", "name"};
        this->root->children.push_back(make_node<Node>(@$, "function_decl"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    ;

function_defn
    : function_decl block {
        std::vector<std::string> claim {"function_decl", "block"};
        this->root->children.push_back(make_node<Node>(@$, "function_defn"));
        grow_tree(root, claim);
    }
    ;

type
    : TOK_TYPE { 
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "type"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));
    }
    ;

name
    : TOK_IDENTIFIER {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "name"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));
    }
    ;

parameter_list
    : declaration {
        std::vector<std::string> claim {"declaration"};
        this->root->children.push_back(make_node<Node>(@$, "parameter_list"));
        grow_tree(root, claim);
    }
    | declaration TOK_COMMA parameter_list {
        std::vector<std::string> claim {"declaration", "parameter_list"};
        this->root->children.push_back(make_node<Node>(@$, "parameter_list"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ","));
    }
    ;

block
    : TOK_LBRACE suite TOK_RBRACE {
        std::vector<std::string> claim {"suite"};
        this->root->children.push_back(make_node<Node>(@$, "block"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "{"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "}"));
    }
    | TOK_LBRACE TOK_RBRACE {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "block"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "{"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "}"));
    }
    ;

suite
    : statement {
        std::vector<std::string> claim {"statement"};
        this->root->children.push_back(make_node<Node>(@$, "suite"));
        grow_tree(root, claim);
    }
    | statement suite {
        std::vector<std::string> claim {"statement", "suite"};
        this->root->children.push_back(make_node<Node>(@$, "suite"));
        grow_tree(root, claim);
    }
    ;

declaration
    : type name {
        std::vector<std::string> claim {"type", "name"};
        this->root->children.push_back(make_node<Node>(@$, "declaration"));
        grow_tree(root, claim);
    }
    ;

statement
    : single_statement TOK_SEMICOLON {
        std::vector<std::string> claim {"single_statement"};
        this->root->children.push_back(make_node<Node>(@$, "statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ";"));
    }
    | compound_statement {
        std::vector<std::string> claim {"compound_statement"};
        this->root->children.push_back(make_node<Node>(@$, "statement"));
        grow_tree(root, claim);
    }
    ;

single_statement
    : declaration TOK_ASSIGN expression {
        std::vector<std::string> claim {"declaration", "expression"};
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "="));
    }
    | name TOK_ASSIGN expression {
        std::vector<std::string> claim {"name", "expression"};
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "="));
    }
    | name augmented_assign expression {
        std::vector<std::string> claim {"name", "augmented_assign", "expression"};
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        grow_tree(root, claim);
    }
    | TOK_BREAK {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));
    }
    | TOK_CONTINUE {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));
    }
    | TOK_RETURN {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));
    }
    | TOK_RETURN expression {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "return"));
    }
    | expression {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(@$, "single_statement"));
        grow_tree(root, claim);
    }
    ;

augmented_assign
    : TOK_PLUS_ASSIGN {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));
    }
    | TOK_MINUS_ASSIGN {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));    
    }
    | TOK_STAR_ASSIGN {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));    
    }
    | TOK_SLASH_ASSIGN {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "augmented_assign"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, $1));    
    }
    ;

expression
    : ternary_expression {
        std::vector<std::string> claim {"ternary_expression"};
        this->root->children.push_back(make_node<Node>(@$, "expression"));
        grow_tree(root, claim);
    }
    ;

ternary_expression
    : logical_expression {
        std::vector<std::string> claim {"logical_expression"};
        this->root->children.push_back(make_node<Node>(@$, "ternary_expression"));
        grow_tree(root, claim);
    }
    | logical_expression TOK_QUESTION_MARK logical_expression TOK_COLON ternary_expression {
        std::vector<std::string> claim {"logical_expression", "logical_expression", "ternary_expression"};
        this->root->children.push_back(make_node<Node>(@$, "ternary_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "?"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ":"));
    }
    ;

logical_expression
    : equality {
        std::vector<std::string> claim {"equality"};
        this->root->children.push_back(make_node<Node>(@$, "logical_expression"));
        grow_tree(root, claim);
    }
    | equality TOK_LOG_AND logical_expression {
        std::vector<std::string> claim {"equality", "logical_expression"};
        this->root->children.push_back(make_node<Node>(@$, "logical_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "&&"));
    }
    | equality TOK_LOG_OR logical_expression {
        std::vector<std::string> claim {"equality", "logical_expression"};
        this->root->children.push_back(make_node<Node>(@$, "logical_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "||"));
    }
    ;

equality
    : comparison {
        std::vector<std::string> claim {"comparison"};
        this->root->children.push_back(make_node<Node>(@$, "equality"));
        grow_tree(root, claim);
    }
    | comparison TOK_EQ equality {
        std::vector<std::string> claim {"comparison", "equality"};
        this->root->children.push_back(make_node<Node>(@$, "equality"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "=="));
    }
    | comparison TOK_NE equality {
        std::vector<std::string> claim {"comparison", "equality"};
        this->root->children.push_back(make_node<Node>(@$, "equality"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "!="));
    }
    ;

comparison
    : term {
        std::vector<std::string> claim {"term"};
        this->root->children.push_back(make_node<Node>(@$, "comparison"));
        grow_tree(root, claim);
    }
    | term TOK_LT comparison {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(@$, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "<"));
    }
    | term TOK_LE comparison {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(@$, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "<="));
    }
    | term TOK_GT comparison {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(@$, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ">"));
    }
    | term TOK_GE comparison {
        std::vector<std::string> claim {"term", "comparison"};
        this->root->children.push_back(make_node<Node>(@$, "comparison"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ">="));
    }
    ;

term
    : factor {
        std::vector<std::string> claim {"factor"};
        this->root->children.push_back(make_node<Node>(@$, "term"));
        grow_tree(root, claim);
    }
    | factor TOK_PLUS term {
        std::vector<std::string> claim {"factor", "term"};
        this->root->children.push_back(make_node<Node>(@$, "term"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "+"));
    }
    | factor TOK_MINUS term {
        std::vector<std::string> claim {"factor", "term"};
        this->root->children.push_back(make_node<Node>(@$, "term"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "-"));
    }
    ;

factor
    : unary_expression {
        std::vector<std::string> claim {"unary_expression"};
        this->root->children.push_back(make_node<Node>(@$, "factor"));
        grow_tree(root, claim);
    }
    | unary_expression TOK_STAR factor {
        std::vector<std::string> claim {"unary_expression", "factor"};
        this->root->children.push_back(make_node<Node>(@$, "factor"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "*"));
    }
    | unary_expression TOK_SLASH factor {
        std::vector<std::string> claim {"unary_expression", "factor"};
        this->root->children.push_back(make_node<Node>(@$, "factor"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "/"));
    }
    ;

unary_expression
    : primary {
        std::vector<std::string> claim {"primary"};
        this->root->children.push_back(make_node<Node>(@$, "unary_expression"));
        grow_tree(root, claim);
    }
    | TOK_MINUS primary {
        std::vector<std::string> claim {"primary"};
        this->root->children.push_back(make_node<Node>(@$, "unary_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "-"));
    }
    | TOK_LPAREN type TOK_RPAREN primary {
        std::vector<std::string> claim {"type", "primary"};
        this->root->children.push_back(make_node<Node>(@$, "unary_expression"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    ;

primary
    : TOK_TRUE {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "Btrue"));
    }
    | TOK_FALSE {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "Bfalse"));        
    }
    | TOK_INTEGER {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "I" + std::to_string($1)));    
    }
    | TOK_FLOAT {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "F" + std::to_string($1)));    
    }
    | TOK_LPAREN expression TOK_RPAREN {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    | name {
        std::vector<std::string> claim {"name"};
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        grow_tree(root, claim);
    }
    | function_call {
        std::vector<std::string> claim {"function_call"};
        this->root->children.push_back(make_node<Node>(@$, "primary"));
        grow_tree(root, claim);
    }
    ;

compound_statement
    : TOK_IF TOK_LPAREN expression TOK_RPAREN block {
        std::vector<std::string> claim {"expression", "block"};
        this->root->children.push_back(make_node<Node>(@$, "compound_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "if"));
    }
    | TOK_FOR for_init for_cond for_act block {
        std::vector<std::string> claim {"for_init", "for_cond", "for_act", "block"};
        this->root->children.push_back(make_node<Node>(@$, "compound_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "for"));
    }
    | TOK_WHILE TOK_LPAREN expression TOK_RPAREN block {
        std::vector<std::string> claim {"expression", "block"};
        this->root->children.push_back(make_node<Node>(@$, "compound_statement"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "while"));
    }
    ;

for_init
    : TOK_LPAREN single_statement TOK_SEMICOLON {
        std::vector<std::string> claim {"single_statement"};
        this->root->children.push_back(make_node<Node>(@$, "for_init"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ";"));
    }
    | TOK_LPAREN TOK_SEMICOLON {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "for_init"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));  
        this->root->children.back()->children.push_back(make_node<Node>(@$, ";"));       
    }
    ;

for_cond
    : expression TOK_SEMICOLON {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(@$, "for_cond"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ";"));
    }
    | TOK_SEMICOLON {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "for_cond"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ";")); 
    }
    ;

for_act
    : single_statement TOK_RPAREN {
        std::vector<std::string> claim {"single_statement"};
        this->root->children.push_back(make_node<Node>(@$, "for_act"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    | TOK_RPAREN {
        if (!this->root) 
            this->root = make_node<Node>(@$, "");
        this->root->children.push_back(make_node<Node>(@$, "for_act"));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")")); 
    }
    ;

function_call
    : name TOK_LPAREN function_args TOK_RPAREN {
        std::vector<std::string> claim {"name", "function_args"};
        this->root->children.push_back(make_node<Node>(@$, "function_call"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    | name TOK_LPAREN TOK_RPAREN {
        std::vector<std::string> claim {"name"};
        this->root->children.push_back(make_node<Node>(@$, "function_call"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, "("));
        this->root->children.back()->children.push_back(make_node<Node>(@$, ")"));
    }
    ;

function_args
    : expression {
        std::vector<std::string> claim {"expression"};
        this->root->children.push_back(make_node<Node>(@$, "function_args"));
        grow_tree(root, claim);
    }
    | expression TOK_COMMA function_args {
        std::vector<std::string> claim {"expression", "function_args"};
        this->root->children.push_back(make_node<Node>(@$, "function_args"));
        grow_tree(root, claim);
        this->root->children.back()->children.push_back(make_node<Node>(@$, ","));
    }
    ;

%%

yy::parser::symbol_type yylex(yyscan_t lexer) {
	yy::parser::symbol_type s;
	int x = yylex(&s, nullptr, lexer);
	assert(x == 1);
	return s;
}

void yy::parser::error(location_type const& loc, std::string const& msg) {
	std::cout << "[error] parser error at " << loc << ": " << msg << ".\n";
}

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const& loc, Args&&... args) {
	std::unique_ptr<T> n = std::make_unique<T>(std::forward<Args>(args)...);
	n->location = loc;
	return n;
}

void grow_tree(std::unique_ptr<Node> &root, std::vector<std::string> claim) {
    for (int i = claim.size() - 1; i >= 0; i--)    
        for (int j = root->children.size() - 2; j >= 0; j--)
            if(root->children[j]->node_type == claim[i]) {
                root->children.back()->children.push_back(std::move(root->children[j]));
                root->children.erase(root->children.begin() + j);
                break;
            }   
    return;
}
