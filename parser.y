%{
#include <stdio.h>
#include "ast.h"
extern int yylex();
void yyerror(const char *s);
%}

/* Define union for semantic values */
%union {
  int num;
}

/* Token declarations */
%token <num> NUMBER
%token PLUS
%token INT PRINT
%token LPAREN RPAREN

/* Declare operator precedence to resolve shift/reduce conflicts */
%left PLUS

/* Declare nonterminal types */
%type <num> expr

%%

program:
    expr { 
         printf("Parsed expression result: %d\n", $1); 
         generateLLVM(); 
    }
    ;

expr:
    NUMBER             { $$ = $1; }
  | expr PLUS expr     { $$ = $1 + $3; }
  | LPAREN expr RPAREN { $$ = $2; }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/* Provide a main() function to start the parser */
int main(void) {
    return yyparse();
}
