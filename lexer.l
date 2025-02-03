%{
#include "parser.tab.hh"
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap

// Token Rules
%%
"var"        { return VAR; }
"int"        { return INT; }
"float"      { return FLOAT; }
"bool"       { return BOOL; }
"true"       { yylval.bool_val = true; return TRUE; }
"false"      { yylval.bool_val = false; return FALSE; }
"print"      { return PRINT; }
"println"    { return PRINTLN; }
"loop"       { return LOOP; }
"if"         { return IF; }
"else"       { return ELSE; }
"equals"     { return EQUALS; }
"!equals"    { return NOTEQUALS; }
"less than"  { return LESSTHAN; }
"greater than" { return GREATERTHAN; }
"and"        { return AND; }
"or"         { return OR; }
"="          { return ASSIGN; }
";"          { return SEMICOLON; }
"("          { return LPAREN; }
")"          { return RPAREN; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }
":"          { return COLON; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return IDENTIFIER; }
[0-9]+       { yylval.num = atoi(yytext); return NUMBER; }
[0-9]+\.[0-9]+ { yylval.float_num = atof(yytext); return FLOATNUM; }
[ \t\n]      ;  // Ignore whitespace
.            { /* catch-all for any other character */ }
%%