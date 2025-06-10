%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern FILE *yyin;

void yyerror(const char *s);
extern int yylex();

ASTNode *root = NULL;
%}

%union {
    int ival;
    char *sval;
    ASTNode *node;
};

%token <ival> NUMBER
%token <sval> IDENTIFIER
%token INT RETURN LPAREN RPAREN LBRACE RBRACE SEMICOLON EQUAL PLUS MINUS MULTIPLY DIVIDE EQUALS NOTEQUALS LESSTHAN GREATERTHAN LESSEQUAL GREATEREQUAL IF ELSE WHILE PRINT
%token COOKIE

%type <node> program statement statements expression assignment if_statement while_statement print_statement

%%

program : statements { root = $1; }
        ;

statements: statement { $$ = $1; }
          | statements statement {
                ASTNode *newNode = createASTNode(AST_STATEMENTS);
                newNode->children[0] = $1;
                newNode->children[1] = $2;
                $$ = newNode;
            }
          ;

statement: expression SEMICOLON { $$ = $1; }
         | assignment SEMICOLON { $$ = $1; }
         | if_statement
         | while_statement
         | print_statement
         | COOKIE LPAREN RPAREN SEMICOLON {
                ASTNode *newNode = createASTNode(AST_COOKIE);
                $$ = newNode;
            }
         | RETURN expression SEMICOLON {
              ASTNode *newNode = createASTNode(AST_RETURN);
              newNode->children[0] = $2;
              $$ = newNode;
          }
         | LBRACE statements RBRACE { $$ = $2; }
         ;

assignment: IDENTIFIER EQUAL expression {
              ASTNode *newNode = createASTNode(AST_ASSIGN);
              newNode->name = $1;
              newNode->children[0] = $3;
              $$ = newNode;
          }
          ;

if_statement: IF LPAREN expression RPAREN statement %prec ELSE {
                  ASTNode *newNode = createASTNode(AST_IF);
                  newNode->children[0] = $3;
                  newNode->children[1] = $5;
                  $$ = newNode;
              }
              | IF LPAREN expression RPAREN statement ELSE statement {
                  ASTNode *newNode = createASTNode(AST_IF_ELSE);
                  newNode->children[0] = $3;
                  newNode->children[1] = $5;
                  newNode->children[2] = $7;
                  $$ = newNode;
              }
              ;

while_statement: WHILE LPAREN expression RPAREN statement {
                   ASTNode *newNode = createASTNode(AST_WHILE);
                   newNode->children[0] = $3;
                   newNode->children[1] = $5;
                   $$ = newNode;
               }
               ;

print_statement: PRINT LPAREN expression RPAREN SEMICOLON {
                     ASTNode *newNode = createASTNode(AST_PRINT);
                     newNode->children[0] = $3;
                     $$ = newNode;
                 }
                 ;

expression: NUMBER {
              ASTNode *newNode = createASTNode(AST_NUMBER);
              newNode->value = $1;
              $$ = newNode;
          }
          | IDENTIFIER {
              ASTNode *newNode = createASTNode(AST_IDENTIFIER);
              newNode->name = $1;
              $$ = newNode;
          }
          | expression PLUS expression {
              ASTNode *newNode = createASTNode(AST_ADD);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression MINUS expression {
              ASTNode *newNode = createASTNode(AST_SUBTRACT);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression MULTIPLY expression {
              ASTNode *newNode = createASTNode(AST_MULTIPLY);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression DIVIDE expression {
              ASTNode *newNode = createASTNode(AST_DIVIDE);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression EQUALS expression {
              ASTNode *newNode = createASTNode(AST_EQUALS);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression NOTEQUALS expression {
              ASTNode *newNode = createASTNode(AST_NOTEQUALS);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression LESSTHAN expression {
              ASTNode *newNode = createASTNode(AST_LESSTHAN);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression GREATERTHAN expression {
              ASTNode *newNode = createASTNode(AST_GREATERTHAN);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
          $$ = newNode;
          }
          | expression LESSEQUAL expression {
              ASTNode *newNode = createASTNode(AST_LESSEQUAL);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | expression GREATEREQUAL expression {
              ASTNode *newNode = createASTNode(AST_GREATEREQUAL);
              newNode->children[0] = $1;
              newNode->children[1] = $3;
              $$ = newNode;
          }
          | LPAREN expression RPAREN { $$ = $2; }
          ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
    exit(1);
}
