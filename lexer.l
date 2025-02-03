%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap

%%
"int"       { return INT; }
"print"     { return PRINT; }
"loop"      { return LOOP; }  // New: recognize "loop" keyword
"="         { return ASSIGN; }
";"         { return SEMICOLON; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }  // New: recognize "{"
"}"         { return RBRACE; }  // New: recognize "}"
"\+"       { return PLUS; }
"-"        { return MINUS; }
[0-9]+      { yylval.str = strdup(yytext); return NUMBER; }
[a-zA-Z]+   { yylval.str = strdup(yytext); return IDENTIFIER; }
[ \t\n]     ;  // Ignore whitespace
%%
