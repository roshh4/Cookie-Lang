%{
#include "parser.tab.h"
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
[a-z]+   { yylval.id = strdup(yytext); return IDENTIFIER; }
[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
[ \t\n]     ;  // Ignore whitespace
%%