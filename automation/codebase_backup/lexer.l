%{
#include "parser.tab.h"
#include <string.h>
%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9]*

%%

[ \t\n]                 ;
"int"                   return INT;
"return"                return RETURN;
{DIGIT}+                yylval.ival = atoi(yytext); return NUMBER;
{ID}                    yylval.sval = strdup(yytext); return IDENTIFIER;
"("                     return LPAREN;
")"                     return RPAREN;
"{"                     return LBRACE;
"}"                     return RBRACE;
";"                     return SEMICOLON;
"="                     return EQUAL;
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return MULTIPLY;
"/"                     return DIVIDE;
"=="                    return EQUALS;
"!="                    return NOTEQUALS;
"<"                     return LESSTHAN;
">"                     return GREATERTHAN;
"<="                    return LESSEQUAL;
">="                    return GREATEREQUAL;
"if"                    return IF;
"else"                  return ELSE;
"while"                 return WHILE;
"print"                 return PRINT;
"cookie"                return COOKIE;
.                       return yytext[0];

%%

int yywrap() {
    return 1;
}
