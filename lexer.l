%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
#include "ast.h"
%}

%option noyywrap

%%
"<="           { return LE; }
">="           { return GE; }
"var"          { return VAR; }
"type"         { return TYPE; }
"int"          { return INT; }
"float"        { return FLOAT; }
"bool"         { return BOOL; }
"char"         { return CHAR; }
"str"          { return STRING; }
"print"        { return PRINT; }
"loop"         { return LOOP; }
"if"           { return IF; }
"<"            { return LT; }
">"            { return GT; }
"true"         { yylval.str = strdup(yytext); return BOOLEAN; }
"false"        { yylval.str = strdup(yytext); return BOOLEAN; }
"="            { return ASSIGN; }
";"            { return SEMICOLON; }
"("            { return LPAREN; }
")"            { return RPAREN; }
"{"            { return LBRACE; }
"}"            { return RBRACE; }
"+"            { return PLUS; }
"-"            { return MINUS; }
"*"            { return MULTIPLY; }
"/"            { return DIVIDE; }
[0-9]+\.[0-9]+ { yylval.str = strdup(yytext); return FLOAT_NUMBER; }
[0-9]+         { yylval.str = strdup(yytext); return NUMBER; }
"'"[^\']"'"    { yylval.str = strdup(yytext); return CHAR_LITERAL; }
\"[^\"]*\"     { yylval.str = strdup(yytext); return STRING_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
[ \t\n]+      ;
.              { /* ignore any other character */ }
%%
