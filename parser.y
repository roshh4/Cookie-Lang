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

/* Declare the union type used for semantic values */
%union {
    char* str;
    ASTNode* node;
}

/* Token declarations */
%token VAR TYPE INT FLOAT BOOL CHAR STRING PRINT LOOP IF WHILE UNTIL ASSIGN SEMICOLON LPAREN RPAREN LBRACE RBRACE ELSE
%token LT GT
%token LE GE
%token EQ
%token AND OR
%token PLUS MINUS MULTIPLY DIVIDE
%token <str> NUMBER FLOAT_NUMBER CHAR_LITERAL IDENTIFIER BOOLEAN STRING_LITERAL

/* Nonterminals (all ASTNode*) */
%type <node> program statements statement expression logical_or_expression logical_and_expression equality_expression relational_expression additive_expression multiplicative_expression primary

/* Set the start symbol */
%start program

%%
program:
    statements { root = $1; }
    ;

statements:
      statement { $$ = $1; }
    | statements statement { $$ = createASTNode("STATEMENT_LIST", NULL, $1, $2); }
    ;

/* Add if and if-else statements */
statement:
      LOOP UNTIL LPAREN expression RPAREN LBRACE statements RBRACE
          { $$ = createASTNode("LOOP_UNTIL", NULL, $4, $7); }
    | WHILE UNTIL expression LBRACE statements RBRACE
          { $$ = createASTNode("LOOP_UNTIL", NULL, $3, $5); }
    | INT IDENTIFIER ASSIGN expression SEMICOLON
          { $$ = createASTNode("ASSIGN_INT", $2, $4, NULL); }
    | FLOAT IDENTIFIER ASSIGN expression SEMICOLON
          { $$ = createASTNode("ASSIGN_FLOAT", $2, $4, NULL); }
    | BOOL IDENTIFIER ASSIGN BOOLEAN SEMICOLON
          { $$ = createASTNode("ASSIGN_BOOL", $2, createASTNode("BOOLEAN", $4, NULL, NULL), NULL); }
    | CHAR IDENTIFIER ASSIGN CHAR_LITERAL SEMICOLON
          { $$ = createASTNode("ASSIGN_CHAR", $2, createASTNode("CHAR", $4, NULL, NULL), NULL); }
    | STRING IDENTIFIER ASSIGN expression SEMICOLON
          { $$ = createASTNode("ASSIGN_STRING", $2, $4, NULL); }
    | VAR IDENTIFIER ASSIGN expression SEMICOLON
          { $$ = createASTNode("VAR_DECL", $2, $4, NULL); }
    | TYPE LPAREN expression RPAREN
          { $$ = createASTNode("TYPE", NULL, $3, NULL); }
    | IDENTIFIER ASSIGN expression SEMICOLON
          { $$ = createASTNode("REASSIGN", $1, $3, NULL); }
    | PRINT LPAREN expression RPAREN SEMICOLON
          { $$ = createASTNode("PRINT", NULL, $3, NULL); }
    | LOOP expression LBRACE statements RBRACE
          { $$ = createASTNode("LOOP", NULL, $2, $4); }
    /* if without else */
    | IF LPAREN expression RPAREN LBRACE statements RBRACE
          { $$ = createASTNode("IF", NULL, $3, $6); }
    /* if-else */
    | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE
          { $$ = createASTNode("IF_ELSE", NULL, $3, createASTNode("IF_ELSE_BODY", NULL, $6, $10)); }
    | INT IDENTIFIER SEMICOLON
          { $$ = createASTNode("DECL_INT", $2, NULL, NULL); }
    | FLOAT IDENTIFIER SEMICOLON
          { $$ = createASTNode("DECL_FLOAT", $2, NULL, NULL); }
    | BOOL IDENTIFIER SEMICOLON
          { $$ = createASTNode("DECL_BOOL", $2, NULL, NULL); }
    | CHAR IDENTIFIER SEMICOLON
          { $$ = createASTNode("DECL_CHAR", $2, NULL, NULL); }
    | STRING IDENTIFIER SEMICOLON
          { $$ = createASTNode("DECL_STRING", $2, NULL, NULL); }
    ;

expression:
    logical_or_expression { $$ = $1; }
    ;

logical_or_expression:
    logical_or_expression OR logical_and_expression { $$ = createASTNode("OR", "||", $1, $3); }
    | logical_and_expression { $$ = $1; }
    ;

logical_and_expression:
    logical_and_expression AND equality_expression { $$ = createASTNode("AND", "&&", $1, $3); }
    | equality_expression { $$ = $1; }
    ;

equality_expression:
    equality_expression EQ relational_expression { $$ = createASTNode("EQ", "==", $1, $3); }
    | relational_expression { $$ = $1; }
    ;

relational_expression:
    relational_expression LT additive_expression { $$ = createASTNode("LT", "<", $1, $3); }
    | relational_expression GT additive_expression { $$ = createASTNode("GT", ">", $1, $3); }
    | relational_expression LE additive_expression { $$ = createASTNode("LE", "<=", $1, $3); }
    | relational_expression GE additive_expression { $$ = createASTNode("GE", ">=", $1, $3); }
    | additive_expression { $$ = $1; }
    ;

additive_expression:
    additive_expression PLUS multiplicative_expression { $$ = createASTNode("ADD", "+", $1, $3); }
    | additive_expression MINUS multiplicative_expression { $$ = createASTNode("SUB", "-", $1, $3); }
    | multiplicative_expression { $$ = $1; }
    ;

multiplicative_expression:
    multiplicative_expression MULTIPLY primary { $$ = createASTNode("MUL", "*", $1, $3); }
    | multiplicative_expression DIVIDE primary { $$ = createASTNode("DIV", "/", $1, $3); }
    | primary { $$ = $1; }
    ;

primary:
    MINUS primary { $$ = createASTNode("NEG", "-", $2, NULL); }
    | NUMBER { $$ = createASTNode("NUMBER", $1, NULL, NULL); }
    | FLOAT_NUMBER { $$ = createASTNode("FLOAT", $1, NULL, NULL); }
    | BOOLEAN { $$ = createASTNode("BOOLEAN", $1, NULL, NULL); }
    | CHAR_LITERAL { $$ = createASTNode("CHAR", $1, NULL, NULL); }
    | STRING_LITERAL { $$ = createASTNode("STRING", $1, NULL, NULL); }
    | IDENTIFIER { $$ = createASTNode("IDENTIFIER", $1, NULL, NULL); }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
  fprintf(stderr, "Error: %s\n", s);
}
