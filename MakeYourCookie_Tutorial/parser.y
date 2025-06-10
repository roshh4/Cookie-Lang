%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
extern int yylex();
void yyerror(const char *s);
ASTNode *root;  // Global AST root.
%}

%code requires {
  #include "ast.h"
}

/* Semantic value union */
%union {
    char* str;
    ASTNode* node;
}

/* Token declarations */
%token <str> NUMBER IDENTIFIER
%token PRINT PLUS ASSIGN SEMICOLON

/* Nonterminals */
%type <node> program statements statement expression

/* Start symbol */
%start program

%%

program:
    statements { root = $1; }
    ;

statements:
    statement { $$ = $1; }
    | statements statement { $$ = createASTNode("STATEMENT_LIST", NULL, $1, $2); }
    ;

statement:
    IDENTIFIER ASSIGN expression SEMICOLON { $$ = createASTNode("ASSIGN", $1, $3, NULL); }
    | PRINT expression SEMICOLON { $$ = createASTNode("PRINT", NULL, $2, NULL); }
    ;

expression:
    NUMBER { $$ = createASTNode("NUMBER", $1, NULL, NULL); }
    | IDENTIFIER { $$ = createASTNode("IDENTIFIER", $1, NULL, NULL); }
    | expression PLUS expression { $$ = createASTNode("PLUS", NULL, $1, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
} 