/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 11 "parser.y"

  #include "ast.h"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    TYPE = 259,                    /* TYPE  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    BOOL = 262,                    /* BOOL  */
    CHAR = 263,                    /* CHAR  */
    STRING = 264,                  /* STRING  */
    PRINT = 265,                   /* PRINT  */
    LOOP = 266,                    /* LOOP  */
    IF = 267,                      /* IF  */
    WHILE = 268,                   /* WHILE  */
    UNTIL = 269,                   /* UNTIL  */
    ASSIGN = 270,                  /* ASSIGN  */
    IS = 271,                      /* IS  */
    SEMICOLON = 272,               /* SEMICOLON  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    ELSE = 277,                    /* ELSE  */
    INPUT = 278,                   /* INPUT  */
    LT = 279,                      /* LT  */
    GT = 280,                      /* GT  */
    LE = 281,                      /* LE  */
    GE = 282,                      /* GE  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    NOT = 287,                     /* NOT  */
    PLUS = 288,                    /* PLUS  */
    MINUS = 289,                   /* MINUS  */
    MULTIPLY = 290,                /* MULTIPLY  */
    DIVIDE = 291,                  /* DIVIDE  */
    NUMBER = 292,                  /* NUMBER  */
    FLOAT_NUMBER = 293,            /* FLOAT_NUMBER  */
    CHAR_LITERAL = 294,            /* CHAR_LITERAL  */
    IDENTIFIER = 295,              /* IDENTIFIER  */
    BOOLEAN = 296,                 /* BOOLEAN  */
    STRING_LITERAL = 297,          /* STRING_LITERAL  */
    FUN = 298,                     /* FUN  */
    RETURN = 299,                  /* RETURN  */
    COMMA = 300,                   /* COMMA  */
    SWITCH = 301,                  /* SWITCH  */
    CASE = 302,                    /* CASE  */
    DEFAULT = 303,                 /* DEFAULT  */
    BREAK = 304,                   /* BREAK  */
    LBRACKET = 305,                /* LBRACKET  */
    RBRACKET = 306,                /* RBRACKET  */
    INLINE = 307,                  /* INLINE  */
    SIZE = 308,                    /* SIZE  */
    DOT = 309,                     /* DOT  */
    INT_FROM_STRING = 310,         /* INT_FROM_STRING  */
    FLOAT_FROM_STRING = 311,       /* FLOAT_FROM_STRING  */
    BOOL_FROM_STRING = 312,        /* BOOL_FROM_STRING  */
    CHAR_FROM_STRING = 313,        /* CHAR_FROM_STRING  */
    COOKIE = 314                   /* COOKIE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

    char* str;
    ASTNode* node;

#line 134 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
