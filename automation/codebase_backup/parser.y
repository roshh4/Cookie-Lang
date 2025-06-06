COMPLETE CODE:
%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yylex();
extern char* yytext;
void yyerror(const char *s);

ASTNode* programNode;
%}

%union {
    int num;
    char* str;
    ASTNode* node;
}

%token <str> IDENTIFIER STRING
%token <num> INTEGER
%token PLUS MINUS TIMES DIVIDE ASSIGN
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token PRINT IF ELSE WHILE RETURN
%token EQ NEQ LT GT LTE GTE
%token <node> STATEMENT_LIST
%token COOKIE // New Token

%type <node> program statement_list statement assignment expression print_statement if_statement while_statement block function_def function_call return_statement
%type <node> bin_op condition

%%

program     : statement_list { programNode = createProgramNode($1, 1); }
            ;

statement_list
            : statement SEMICOLON statement_list { $$ = createStatementListNode($1, $3, yylineno); }
            | statement SEMICOLON { $$ = createStatementListNode($1, NULL, yylineno); }
            ;

statement   : assignment
            | print_statement
            | if_statement
            | while_statement
            | block
            | function_def
            | function_call SEMICOLON { $$ = $1; }
            | return_statement
            | COOKIE SEMICOLON { $$ = createCookieNode(yylineno); } // New Grammar Rule
            ;

assignment  : IDENTIFIER ASSIGN expression { $$ = createAssignmentNode($1, $3, yylineno); }
            ;

expression  : INTEGER { $$ = createIntegerNode($1, yylineno); }
            | IDENTIFIER { $$ = createIdentifierNode($1, yylineno); }
            | STRING { $$ = createStringNode($1, yylineno); }
            | LPAREN expression RPAREN { $$ = $2; }
            | expression PLUS  expression { $$ = createBinaryOpNode("+", $1, $3, yylineno); }
            | expression MINUS expression { $$ = createBinaryOpNode("-", $1, $3, yylineno); }
            | expression TIMES expression { $$ = createBinaryOpNode("*", $1, $3, yylineno); }
            | expression DIVIDE expression { $$ = createBinaryOpNode("/", $1, $3, yylineno); }
            | bin_op
            ;

bin_op      : expression EQ expression { $$ = createBinaryOpNode("==", $1, $3, yylineno); }
            | expression NEQ expression { $$ = createBinaryOpNode("!=", $1, $3, yylineno); }
            | expression LT expression  { $$ = createBinaryOpNode("<", $1, $3, yylineno); }
            | expression GT expression  { $$ = createBinaryOpNode(">", $1, $3, yylineno); }
            | expression LTE expression { $$ = createBinaryOpNode("<=", $1, $3, yylineno); }
            | expression GTE expression { $$ = createBinaryOpNode(">=", $1, $3, yylineno); }
            ;

print_statement
            : PRINT expression { $$ = createPrintNode($2, yylineno); }
            ;

if_statement
            : IF LPAREN condition RPAREN block { $$ = createIfNode($3, $5, NULL, yylineno); }
            | IF LPAREN condition RPAREN block ELSE block { $$ = createIfNode($3, $5, $7, yylineno); }
            ;

condition   : expression { $$ = $1; }
            ;

while_statement
            : WHILE LPAREN condition RPAREN block { $$ = createWhileNode($3, $5, yylineno); }
            ;

block       : LBRACE statement_list RBRACE { $$ = createBlockNode($2, yylineno); }
            ;

function_def: IDENTIFIER LPAREN RPAREN block { $$ = createFunctionDefNode($1, NULL, $4, yylineno); }
            ;

function_call
            : IDENTIFIER LPAREN RPAREN { $$ = createFunctionCallNode($1, NULL, yylineno); }
            ;

return_statement
            : RETURN expression { $$ = createReturnNode($2, yylineno); }
            ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d near '%s'\n", s, yylineno, yytext);
    exit(1);
}
