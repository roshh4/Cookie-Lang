COMPLETE CODE:
%{
#include "parser.tab.h"
#include <string.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+                  { yylval.num = atoi(yytext); return INTEGER; }
\"[^"]*\"              { 
                            yylval.str = strdup(yytext);
                            /* Remove quotes */
                            memmove(yylval.str, yylval.str + 1, strlen(yylval.str) - 2);
                            yylval.str[strlen(yylval.str) - 2] = '\0';
                            return STRING; 
                        }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return TIMES; }
"/"                     { return DIVIDE; }
"="                     { return ASSIGN; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
";"                     { return SEMICOLON; }
"print"                 { return PRINT; }
"if"                    { return IF; }
"else"                  { return ELSE; }
"while"                 { return WHILE; }
"return"                { return RETURN; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
"<"                     { return LT; }
">"                     { return GT; }
"<="                    { return LTE; }
">="                    { return GTE; }
[ \t\n]                 ; /* Ignore whitespace */
.                       { printf("Illegal character: %s\n", yytext); }
"cookie"                { return COOKIE; } // New Token
%%

int yywrap() {
    return 1;
}
