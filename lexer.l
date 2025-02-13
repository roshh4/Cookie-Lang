%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
#include "ast.h"
%}

%option noyywrap

%%

"int"       { return INT; }
"print"     { return PRINT; }
"loop"      { return LOOP; }
"="         { return ASSIGN; }
";"         { return SEMICOLON; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"/"         { return DIVIDE; }
[0-9]+      { yylval.str = strdup(yytext); return NUMBER; }
[a-zA-Z]+   { yylval.str = strdup(yytext); return IDENTIFIER; }
[ \t\n]     ;  // Ignore whitespace

%%
