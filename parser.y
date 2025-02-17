%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
extern int yylex();
void yyerror(const char *s);
ASTNode *root;  // Global AST root
%}

%code requires {
  #include "ast.h"
}

%union {
    char* str;
    ASTNode* node;
}

%token VAR TYPE INT FLOAT BOOL CHAR STRING PRINT LOOP ASSIGN SEMICOLON LPAREN RPAREN LBRACE RBRACE
%token PLUS MINUS MULTIPLY DIVIDE
%token <str> NUMBER FLOAT_NUMBER CHAR_LITERAL IDENTIFIER BOOLEAN STRING_LITERAL

%type <node> expression primary statement statements

%left PLUS MINUS
%left MULTIPLY DIVIDE

%%

program:
    statements { root = $1; }
    ;

statements:
      statement { $$ = $1; }
    | statements statement { $$ = createASTNode("STATEMENT_LIST", NULL, $1, $2); }
    ;

statement:
      /* Explicit type declarations with initialization */
      INT IDENTIFIER ASSIGN expression SEMICOLON {
          $$ = createASTNode("ASSIGN_INT", $2, $4, NULL);
      }
    | FLOAT IDENTIFIER ASSIGN expression SEMICOLON {
          $$ = createASTNode("ASSIGN_FLOAT", $2, $4, NULL);
      }
    | BOOL IDENTIFIER ASSIGN BOOLEAN SEMICOLON {
          $$ = createASTNode("ASSIGN_BOOL", $2, createASTNode("BOOLEAN", $4, NULL, NULL), NULL);
      }
    | CHAR IDENTIFIER ASSIGN CHAR_LITERAL SEMICOLON {
          $$ = createASTNode("ASSIGN_CHAR", $2, createASTNode("CHAR", $4, NULL, NULL), NULL);
      }
    | STRING IDENTIFIER ASSIGN expression SEMICOLON {
          $$ = createASTNode("ASSIGN_STRING", $2, $4, NULL);
      }
      /* Automatic type declaration using var */
    | VAR IDENTIFIER ASSIGN expression SEMICOLON {
          $$ = createASTNode("VAR_DECL", $2, $4, NULL);
      }
      /* Type–query: type( expression ) */
    | TYPE LPAREN expression RPAREN {
          $$ = createASTNode("TYPE", NULL, $3, NULL);
      }
      /* Reassignment */
    | IDENTIFIER ASSIGN expression SEMICOLON {
          $$ = createASTNode("REASSIGN", $1, $3, NULL);
      }
      /* Print statement */
    | PRINT LPAREN expression RPAREN SEMICOLON {
          $$ = createASTNode("PRINT", NULL, $3, NULL);
      }
      /* Loop – using an expression as the loop count */
    | LOOP expression LBRACE statements RBRACE {
          $$ = createASTNode("LOOP", NULL, $2, $4);
      }
      /* Declarations without initialization (explicit type) */
    | INT IDENTIFIER SEMICOLON {
          $$ = createASTNode("DECL_INT", $2, NULL, NULL);
      }
    | FLOAT IDENTIFIER SEMICOLON {
          $$ = createASTNode("DECL_FLOAT", $2, NULL, NULL);
      }
    | BOOL IDENTIFIER SEMICOLON {
          $$ = createASTNode("DECL_BOOL", $2, NULL, NULL);
      }
    | CHAR IDENTIFIER SEMICOLON {
          $$ = createASTNode("DECL_CHAR", $2, NULL, NULL);
      }
    | STRING IDENTIFIER SEMICOLON {
          $$ = createASTNode("DECL_STRING", $2, NULL, NULL);
      }
    ;

expression:
      expression PLUS expression { $$ = createASTNode("ADD", "+", $1, $3); }
    | expression MINUS expression { $$ = createASTNode("SUB", "-", $1, $3); }
    | expression MULTIPLY expression { $$ = createASTNode("MUL", "*", $1, $3); }
    | expression DIVIDE expression { $$ = createASTNode("DIV", "/", $1, $3); }
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
