/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
extern int yylex();
void yyerror(const char *s);
ASTNode *root;  // Global AST root.

#line 81 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_TYPE = 4,                       /* TYPE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_LOOP = 11,                      /* LOOP  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_UNTIL = 14,                     /* UNTIL  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_IS = 16,                        /* IS  */
  YYSYMBOL_SEMICOLON = 17,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 18,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 19,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_INPUT = 23,                     /* INPUT  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_PLUS = 33,                      /* PLUS  */
  YYSYMBOL_MINUS = 34,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 35,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 36,                    /* DIVIDE  */
  YYSYMBOL_NUMBER = 37,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 38,              /* FLOAT_NUMBER  */
  YYSYMBOL_CHAR_LITERAL = 39,              /* CHAR_LITERAL  */
  YYSYMBOL_IDENTIFIER = 40,                /* IDENTIFIER  */
  YYSYMBOL_BOOLEAN = 41,                   /* BOOLEAN  */
  YYSYMBOL_STRING_LITERAL = 42,            /* STRING_LITERAL  */
  YYSYMBOL_FUN = 43,                       /* FUN  */
  YYSYMBOL_RETURN = 44,                    /* RETURN  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_SWITCH = 46,                    /* SWITCH  */
  YYSYMBOL_CASE = 47,                      /* CASE  */
  YYSYMBOL_DEFAULT = 48,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 49,                     /* BREAK  */
  YYSYMBOL_LBRACKET = 50,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 51,                  /* RBRACKET  */
  YYSYMBOL_INLINE = 52,                    /* INLINE  */
  YYSYMBOL_SIZE = 53,                      /* SIZE  */
  YYSYMBOL_DOT = 54,                       /* DOT  */
  YYSYMBOL_INT_FROM_STRING = 55,           /* INT_FROM_STRING  */
  YYSYMBOL_FLOAT_FROM_STRING = 56,         /* FLOAT_FROM_STRING  */
  YYSYMBOL_BOOL_FROM_STRING = 57,          /* BOOL_FROM_STRING  */
  YYSYMBOL_CHAR_FROM_STRING = 58,          /* CHAR_FROM_STRING  */
  YYSYMBOL_COOKIE = 59,                    /* COOKIE  */
  YYSYMBOL_60_ = 60,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_global_declarations = 63,       /* global_declarations  */
  YYSYMBOL_global_declaration = 64,        /* global_declaration  */
  YYSYMBOL_function_definition = 65,       /* function_definition  */
  YYSYMBOL_parameter_list_opt = 66,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_parameter = 68,                 /* parameter  */
  YYSYMBOL_function_body = 69,             /* function_body  */
  YYSYMBOL_argument_list_opt = 70,         /* argument_list_opt  */
  YYSYMBOL_argument_list = 71,             /* argument_list  */
  YYSYMBOL_loop_header = 72,               /* loop_header  */
  YYSYMBOL_element_list = 73,              /* element_list  */
  YYSYMBOL_statements = 74,                /* statements  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_else_if_ladder_opt = 76,        /* else_if_ladder_opt  */
  YYSYMBOL_if_ladder = 77,                 /* if_ladder  */
  YYSYMBOL_case_list = 78,                 /* case_list  */
  YYSYMBOL_case_clause = 79,               /* case_clause  */
  YYSYMBOL_default_clause = 80,            /* default_clause  */
  YYSYMBOL_expression = 81,                /* expression  */
  YYSYMBOL_logical_or_expression = 82,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 83,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 84,       /* equality_expression  */
  YYSYMBOL_relational_expression = 85,     /* relational_expression  */
  YYSYMBOL_additive_expression = 86,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 87, /* multiplicative_expression  */
  YYSYMBOL_primary = 88                    /* primary  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   773

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    64,    65,    69,    70,    75,    81,    82,
      86,    87,    91,    92,    93,    94,    95,    99,   104,   105,
     109,   110,   120,   121,   122,   127,   128,   133,   134,   139,
     140,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   170,   172,   175,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   206,
     207,   208,   209,   210,   212,   213,   214,   215,   216,   217,
     220,   223,   226,   231,   232,   236,   238,   244,   245,   250,
     255,   256,   261,   265,   266,   270,   271,   275,   276,   277,
     281,   282,   283,   284,   285,   289,   290,   291,   295,   296,
     297,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "TYPE", "INT",
  "FLOAT", "BOOL", "CHAR", "STRING", "PRINT", "LOOP", "IF", "WHILE",
  "UNTIL", "ASSIGN", "IS", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "ELSE", "INPUT", "LT", "GT", "LE", "GE", "EQ", "NE", "AND",
  "OR", "NOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "NUMBER",
  "FLOAT_NUMBER", "CHAR_LITERAL", "IDENTIFIER", "BOOLEAN",
  "STRING_LITERAL", "FUN", "RETURN", "COMMA", "SWITCH", "CASE", "DEFAULT",
  "BREAK", "LBRACKET", "RBRACKET", "INLINE", "SIZE", "DOT",
  "INT_FROM_STRING", "FLOAT_FROM_STRING", "BOOL_FROM_STRING",
  "CHAR_FROM_STRING", "COOKIE", "':'", "$accept", "program",
  "global_declarations", "global_declaration", "function_definition",
  "parameter_list_opt", "parameter_list", "parameter", "function_body",
  "argument_list_opt", "argument_list", "loop_header", "element_list",
  "statements", "statement", "else_if_ladder_opt", "if_ladder",
  "case_list", "case_clause", "default_clause", "expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "primary", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,   -34,   -24,   -14,    -8,     9,    22,    24,   494,    48,
      63,    61,    21,    47,    73,    80,    83,   101,   112,   114,
     115,  -163,  -163,  -163,     7,   -13,     2,    14,    95,   119,
       6,   121,   125,   136,   138,   142,   148,   664,   664,   664,
    -163,  -163,  -163,    -9,  -163,  -163,   150,   127,   116,   141,
     160,    88,   162,   129,   135,   140,   664,   664,   664,   664,
     664,   664,   174,   664,   664,  -163,   664,   179,  -163,  -163,
     664,   664,   664,   664,  -163,   511,   664,   664,  -163,   550,
     159,   181,  -163,   568,   681,   184,  -163,   607,   664,   664,
    -163,   625,   203,    32,   194,   664,   664,   664,   664,   664,
     664,   210,   140,   140,   664,   664,   720,   664,   478,   664,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   190,   213,   214,   216,   220,   219,   188,  -163,
     192,   144,   225,   230,   231,   222,   234,   235,   236,   237,
     241,   206,   243,   253,   258,   207,   254,   261,   260,   229,
     264,   265,   266,   269,   238,   268,   270,   271,   239,  -163,
     274,   273,   276,   279,   280,   282,   284,  -163,   285,   242,
      15,  -163,   287,   172,  -163,  -163,   160,    88,   162,   162,
     129,   129,   129,   129,   135,   135,   140,   140,   289,   290,
     478,   294,  -163,   295,   664,   298,   277,   278,   286,   299,
     300,   297,   275,  -163,   305,   304,   308,  -163,  -163,  -163,
    -163,  -163,   318,   325,  -163,  -163,   321,   326,  -163,  -163,
     328,   327,  -163,  -163,  -163,   330,   329,  -163,  -163,   340,
     344,  -163,  -163,  -163,  -163,  -163,  -163,   342,  -163,  -163,
     478,  -163,  -163,  -163,   664,   478,   196,  -163,  -163,  -163,
     664,  -163,  -163,  -163,  -163,  -163,   343,   144,  -163,   267,
    -163,   664,  -163,   664,  -163,   664,  -163,   664,  -163,   664,
    -163,   478,   256,   347,   324,  -163,   348,   478,  -163,   664,
     149,  -163,    54,  -163,    84,    86,    87,    92,   346,  -163,
    -163,   349,  -163,   351,   478,   478,   314,  -163,   354,   360,
     664,   361,   362,   363,   364,  -163,     1,  -163,  -163,   478,
     478,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   366,   478,
    -163,   478,   664,   401,   368,  -163,   365,   478,   423,   349,
    -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   108,   116,   107,   109,     0,     0,    24,    82,
      84,    86,    89,    94,    97,   100,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    72,     0,     0,     1,     4,
       0,     0,     0,     0,    54,     0,     0,     0,    55,     0,
       0,     0,    56,     0,     0,     0,    57,     0,     0,     0,
      58,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,   117,     0,     0,
     116,    22,     0,     0,    27,    23,    83,    85,    87,    88,
      90,    91,    92,    93,    95,    96,    98,    99,     0,     0,
       0,     0,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    52,    46,    47,
      35,    36,     0,     0,    37,    38,     0,     0,    39,    40,
       0,     0,    41,    43,    42,     0,     0,    44,    45,     0,
       0,    50,   118,   110,   111,   113,   112,     0,   114,   115,
       0,   104,    32,    28,    18,     0,     0,    29,    70,    21,
       0,    12,    13,    14,    15,    16,     0,     0,    69,     0,
      53,     0,    59,     0,    60,     0,    61,     0,    62,     0,
      63,     0,     0,     0,     0,    34,     0,     0,    11,     0,
      80,    77,     0,    25,     0,     0,     0,     0,     0,    31,
     101,    73,    48,     0,    17,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,    33,     0,    30,     7,    79,
       0,    71,    64,    26,    65,    66,    67,    68,     0,     0,
      74,    81,     0,     0,     0,    76,     0,     0,     0,    73,
      75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   369,  -163,  -163,  -163,   131,  -163,  -103,
    -163,  -163,  -123,  -162,     0,    53,  -163,  -163,   113,  -163,
      -3,  -163,   281,   283,    98,   111,    96,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,   201,   202,   203,   293,   127,
     128,    47,   282,   173,   174,   307,   320,   280,   281,   298,
     283,    49,    50,    51,    52,    53,    54,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,   168,    72,    73,    74,    48,    24,   102,   103,   104,
      31,    32,    33,   318,    34,    35,    25,    76,    77,    78,
      23,   319,    70,    71,    37,    92,    26,    94,   246,    80,
      81,    82,    27,   104,   101,   240,    59,    75,    38,    60,
      39,   105,    30,    40,    41,    42,    93,    44,    45,    28,
     104,   106,    79,   123,   124,   125,   126,   129,   130,    46,
     132,   133,    29,   134,    83,   105,    56,   136,   137,   138,
     139,    61,   141,   142,   143,   299,   145,    57,   272,    58,
     149,   151,   105,   274,   154,   155,   156,    62,   158,   186,
     187,    63,   161,   162,   163,   164,   165,   166,    64,   300,
      65,   129,   169,   171,   172,   301,   175,   302,   303,   288,
      84,    85,    86,   304,    68,   294,   112,   113,     1,    66,
       2,     3,     4,     5,     6,     7,     8,     9,    10,   300,
      67,   300,   300,   309,    88,    89,    90,   300,    11,    95,
     284,   273,   285,    96,   286,    87,   287,   108,   321,   196,
     197,   198,   199,   200,    97,    12,    98,   323,    13,    14,
      99,    15,   118,   119,    16,   328,   100,    17,   107,    91,
     120,   121,   110,   243,    18,     1,   109,     2,     3,     4,
       5,     6,     7,     8,     9,    10,   114,   115,   116,   117,
     111,   249,   131,   242,   122,    11,   279,   296,   135,     1,
     146,     2,     3,     4,     5,     6,     7,     8,     9,    10,
     178,   179,    12,   160,   184,   185,    14,   275,    15,    11,
     159,    16,   147,   152,    17,   180,   181,   182,   183,   167,
     188,    18,   189,   194,   190,   191,    12,   192,   193,   207,
      14,   129,    15,   195,   204,    16,   243,   276,    17,   205,
     206,   208,   209,   210,   211,    18,   212,   213,   217,     1,
     214,     2,     3,     4,     5,     6,     7,     8,     9,    10,
     215,   218,   243,   216,   243,   220,   295,   289,   219,    11,
     221,   222,   223,   224,   225,   227,   229,   228,   243,   226,
     230,   231,   232,   239,   243,   233,    12,   313,   234,   235,
      14,   236,    15,   237,   238,    16,   241,   244,    17,   243,
     245,   247,   248,   250,   279,    18,   256,   251,   252,   324,
     257,   243,   258,   243,   259,   260,   253,     1,   243,     2,
       3,     4,     5,     6,     7,     8,     9,    10,   261,   254,
     255,   263,   262,   264,   266,   291,   268,    11,   265,     1,
     267,     2,     3,     4,     5,     6,     7,     8,     9,    10,
     269,   270,   271,   277,    12,   292,   290,   305,    14,    11,
      15,   306,   308,    16,   310,   311,    17,   312,   314,   315,
     316,   317,   330,    18,   322,   327,    12,   326,   278,    69,
      14,   176,    15,   297,   177,    16,     0,     0,    17,     0,
       0,     0,     0,     0,     1,    18,     2,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,   325,     0,    11,     0,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,    12,     0,     0,   329,    14,    11,    15,     0,     0,
      16,     0,     0,    17,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    12,     0,     0,     0,    14,     0,    15,
       0,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,     1,    18,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    11,    34,    35,     0,     0,     0,     0,    36,     0,
       0,     0,    37,     0,     0,    31,    32,    33,    12,    34,
      35,     0,    14,     0,    15,     0,    38,    16,    39,    37,
      17,    40,    41,    42,    43,    44,    45,    18,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    46,    40,    41,
      42,    93,    44,    45,    31,    32,    33,     0,    34,    35,
       0,     0,   140,     0,    46,     0,     0,     0,    37,     0,
       0,     0,    31,    32,    33,     0,    34,    35,     0,     0,
       0,     0,    38,     0,    39,     0,    37,    40,    41,    42,
      93,    44,    45,     0,     0,     0,     0,     0,     0,     0,
      38,   144,    39,    46,     0,    40,    41,    42,    93,    44,
      45,    31,    32,    33,     0,    34,    35,     0,     0,   148,
       0,    46,     0,     0,     0,    37,     0,     0,     0,    31,
      32,    33,     0,    34,    35,     0,     0,     0,     0,    38,
       0,    39,     0,    37,    40,    41,    42,    93,    44,    45,
       0,     0,     0,     0,     0,     0,     0,    38,   153,    39,
      46,     0,    40,    41,    42,    93,    44,    45,    31,    32,
      33,     0,    34,    35,     0,     0,   157,     0,    46,     0,
       0,     0,    37,     0,     0,    31,    32,    33,     0,    34,
      35,     0,     0,     0,     0,     0,    38,     0,    39,    37,
       0,    40,    41,    42,    93,    44,    45,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    46,    40,    41,
     150,    93,    44,    45,    31,    32,    33,     0,    34,    35,
       0,     0,     0,     0,    46,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    39,     0,     0,    40,    41,    42,
     170,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46
};

static const yytype_int16 yycheck[] =
{
       0,   104,    15,    16,    17,     8,    40,    38,    39,    18,
       4,     5,     6,    12,     8,     9,    40,    15,    16,    17,
      20,    20,    15,    16,    18,    19,    40,    30,   190,    15,
      16,    17,    40,    18,    37,    20,    15,    50,    32,    18,
      34,    50,    18,    37,    38,    39,    40,    41,    42,    40,
      18,    60,    50,    56,    57,    58,    59,    60,    61,    53,
      63,    64,    40,    66,    50,    50,    18,    70,    71,    72,
      73,    50,    75,    76,    77,    21,    79,    14,   240,    18,
      83,    84,    50,   245,    87,    88,    89,    40,    91,   120,
     121,    18,    95,    96,    97,    98,    99,   100,    18,    45,
      17,   104,   105,   106,   107,    21,   109,    21,    21,   271,
      15,    16,    17,    21,     0,   277,    28,    29,     3,    18,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    45,
      18,    45,    45,   295,    15,    16,    17,    45,    23,    18,
     263,   244,   265,    18,   267,    50,   269,    20,   310,     5,
       6,     7,     8,     9,    18,    40,    18,   319,    43,    44,
      18,    46,    33,    34,    49,   327,    18,    52,    18,    50,
      35,    36,    31,   173,    59,     3,    60,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    24,    25,    26,    27,
      30,   194,    18,    21,    54,    23,    47,    48,    19,     3,
      41,     5,     6,     7,     8,     9,    10,    11,    12,    13,
     112,   113,    40,    19,   118,   119,    44,    21,    46,    23,
      17,    49,    41,    39,    52,   114,   115,   116,   117,    19,
      40,    59,    19,    45,    20,    19,    40,    17,    19,    17,
      44,   244,    46,    51,    19,    49,   246,   250,    52,    19,
      19,    17,    17,    17,    17,    59,    15,    51,    51,     3,
      17,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      17,    17,   272,    15,   274,    15,   279,    21,    17,    23,
      51,    17,    17,    17,    15,    17,    15,    17,   288,    51,
      51,    17,    19,    51,   294,    19,    40,   300,    19,    19,
      44,    19,    46,    19,    19,    49,    19,    18,    52,   309,
      20,    17,    17,    15,    47,    59,    19,    40,    40,   322,
      45,   321,    17,   323,    20,    17,    40,     3,   328,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    20,    40,
      40,    20,    17,    17,    17,    21,    17,    23,    20,     3,
      20,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      20,    17,    20,    20,    40,    17,    19,    21,    44,    23,
      46,    22,    21,    49,    60,    21,    52,    17,    17,    17,
      17,    17,   329,    59,    18,    20,    40,    19,   257,    20,
      44,   110,    46,   280,   111,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,     3,    59,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    23,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    21,    44,    23,    46,    -1,    -1,
      49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    46,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,     3,    59,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,    23,     8,     9,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    -1,    -1,     4,     5,     6,    40,     8,
       9,    -1,    44,    -1,    46,    -1,    32,    49,    34,    18,
      52,    37,    38,    39,    40,    41,    42,    59,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,    53,    37,    38,
      39,    40,    41,    42,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    18,    -1,
      -1,    -1,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    18,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    51,    34,    53,    -1,    37,    38,    39,    40,    41,
      42,     4,     5,     6,    -1,     8,     9,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    18,    -1,    -1,    -1,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    18,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    51,    34,
      53,    -1,    37,    38,    39,    40,    41,    42,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    18,    -1,    -1,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    18,
      -1,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,    53,    37,    38,
      39,    40,    41,    42,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    23,    40,    43,    44,    46,    49,    52,    59,    62,
      63,    64,    65,    75,    40,    40,    40,    40,    40,    40,
      18,     4,     5,     6,     8,     9,    14,    18,    32,    34,
      37,    38,    39,    40,    41,    42,    53,    72,    81,    82,
      83,    84,    85,    86,    87,    88,    18,    14,    18,    15,
      18,    50,    40,    18,    18,    17,    18,    18,     0,    64,
      15,    16,    15,    16,    17,    50,    15,    16,    17,    50,
      15,    16,    17,    50,    15,    16,    17,    50,    15,    16,
      17,    50,    19,    40,    81,    18,    18,    18,    18,    18,
      18,    81,    88,    88,    18,    50,    60,    18,    20,    60,
      31,    30,    28,    29,    24,    25,    26,    27,    33,    34,
      35,    36,    54,    81,    81,    81,    81,    70,    71,    81,
      81,    18,    81,    81,    81,    19,    81,    81,    81,    81,
      51,    81,    81,    81,    51,    81,    41,    41,    51,    81,
      39,    81,    39,    51,    81,    81,    81,    51,    81,    17,
      19,    81,    81,    81,    81,    81,    81,    19,    70,    81,
      40,    81,    81,    74,    75,    81,    83,    84,    85,    85,
      86,    86,    86,    86,    87,    87,    88,    88,    40,    19,
      20,    19,    17,    19,    45,    51,     5,     6,     7,     8,
       9,    66,    67,    68,    19,    19,    19,    17,    17,    17,
      17,    17,    15,    51,    17,    17,    15,    51,    17,    17,
      15,    51,    17,    17,    17,    15,    51,    17,    17,    15,
      51,    17,    19,    19,    19,    19,    19,    19,    19,    51,
      20,    19,    21,    75,    18,    20,    74,    17,    17,    81,
      15,    40,    40,    40,    40,    40,    19,    45,    17,    20,
      17,    20,    17,    20,    17,    20,    17,    20,    17,    20,
      17,    20,    74,    70,    74,    21,    81,    20,    68,    47,
      78,    79,    73,    81,    73,    73,    73,    73,    74,    21,
      19,    21,    17,    69,    74,    81,    48,    79,    80,    21,
      45,    21,    21,    21,    21,    21,    22,    76,    21,    74,
      60,    21,    17,    81,    17,    17,    17,    17,    12,    20,
      77,    74,    18,    74,    81,    21,    19,    20,    74,    21,
      76
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    69,    70,    70,
      71,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      80,    80,    81,    82,    82,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     8,     0,     1,
       1,     3,     2,     2,     2,     2,     2,     1,     0,     1,
       1,     3,     3,     3,     1,     1,     3,     1,     2,     5,
       8,     7,     5,     8,     6,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     7,     4,
       5,     4,     4,     5,     3,     3,     3,     3,     3,     6,
       6,     6,     6,     6,     9,     9,     9,     9,     9,     5,
       5,     8,     2,     0,     2,     8,     3,     1,     2,     3,
       0,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     6,     2,     2,     4,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     1,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: global_declarations  */
#line 60 "parser.y"
                        { root = (yyvsp[0].node); }
#line 1454 "parser.tab.c"
    break;

  case 3: /* global_declarations: global_declaration  */
#line 64 "parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1460 "parser.tab.c"
    break;

  case 4: /* global_declarations: global_declarations global_declaration  */
#line 65 "parser.y"
                                             { (yyval.node) = createASTNode("GLOBAL_LIST", NULL, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1466 "parser.tab.c"
    break;

  case 5: /* global_declaration: function_definition  */
#line 69 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1472 "parser.tab.c"
    break;

  case 6: /* global_declaration: statement  */
#line 70 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1478 "parser.tab.c"
    break;

  case 7: /* function_definition: FUN IDENTIFIER LPAREN parameter_list_opt RPAREN LBRACE function_body RBRACE  */
#line 76 "parser.y"
          { (yyval.node) = createASTNode("FUNC_DEF", (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1484 "parser.tab.c"
    break;

  case 8: /* parameter_list_opt: %empty  */
#line 81 "parser.y"
                  { (yyval.node) = NULL; }
#line 1490 "parser.tab.c"
    break;

  case 9: /* parameter_list_opt: parameter_list  */
#line 82 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1496 "parser.tab.c"
    break;

  case 10: /* parameter_list: parameter  */
#line 86 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1502 "parser.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA parameter  */
#line 87 "parser.y"
                                     { (yyval.node) = createASTNode("PARAM_LIST", NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1508 "parser.tab.c"
    break;

  case 12: /* parameter: INT IDENTIFIER  */
#line 91 "parser.y"
                     { (yyval.node) = createASTNode("PARAM", (yyvsp[0].str), createASTNode("TYPE_LITERAL", "int", NULL, NULL), NULL); }
#line 1514 "parser.tab.c"
    break;

  case 13: /* parameter: FLOAT IDENTIFIER  */
#line 92 "parser.y"
                       { (yyval.node) = createASTNode("PARAM", (yyvsp[0].str), createASTNode("TYPE_LITERAL", "float", NULL, NULL), NULL); }
#line 1520 "parser.tab.c"
    break;

  case 14: /* parameter: BOOL IDENTIFIER  */
#line 93 "parser.y"
                      { (yyval.node) = createASTNode("PARAM", (yyvsp[0].str), createASTNode("TYPE_LITERAL", "bool", NULL, NULL), NULL); }
#line 1526 "parser.tab.c"
    break;

  case 15: /* parameter: CHAR IDENTIFIER  */
#line 94 "parser.y"
                      { (yyval.node) = createASTNode("PARAM", (yyvsp[0].str), createASTNode("TYPE_LITERAL", "char", NULL, NULL), NULL); }
#line 1532 "parser.tab.c"
    break;

  case 16: /* parameter: STRING IDENTIFIER  */
#line 95 "parser.y"
                        { (yyval.node) = createASTNode("PARAM", (yyvsp[0].str), createASTNode("TYPE_LITERAL", "string", NULL, NULL), NULL); }
#line 1538 "parser.tab.c"
    break;

  case 17: /* function_body: statements  */
#line 99 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1544 "parser.tab.c"
    break;

  case 18: /* argument_list_opt: %empty  */
#line 104 "parser.y"
                  { (yyval.node) = NULL; }
#line 1550 "parser.tab.c"
    break;

  case 19: /* argument_list_opt: argument_list  */
#line 105 "parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1556 "parser.tab.c"
    break;

  case 20: /* argument_list: expression  */
#line 109 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1562 "parser.tab.c"
    break;

  case 21: /* argument_list: argument_list COMMA expression  */
#line 110 "parser.y"
                                     { (yyval.node) = createASTNode("ARG_LIST", NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1568 "parser.tab.c"
    break;

  case 22: /* loop_header: IDENTIFIER ':' expression  */
#line 120 "parser.y"
                                { (yyval.node) = createASTNode("FOR_LOOP", (yyvsp[-2].str), createASTNode("RANGE", NULL, NULL, (yyvsp[0].node)), NULL); }
#line 1574 "parser.tab.c"
    break;

  case 23: /* loop_header: expression ':' expression  */
#line 121 "parser.y"
                                { (yyval.node) = createASTNode("FOR_LOOP", NULL, createASTNode("RANGE", NULL, (yyvsp[-2].node), (yyvsp[0].node)), NULL); }
#line 1580 "parser.tab.c"
    break;

  case 24: /* loop_header: expression  */
#line 122 "parser.y"
                 { (yyval.node) = createASTNode("LOOP", NULL, (yyvsp[0].node), NULL); }
#line 1586 "parser.tab.c"
    break;

  case 25: /* element_list: expression  */
#line 127 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1592 "parser.tab.c"
    break;

  case 26: /* element_list: element_list COMMA expression  */
#line 128 "parser.y"
                                    { (yyval.node) = createASTNode("ARRAY_ELEM_LIST", NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1598 "parser.tab.c"
    break;

  case 27: /* statements: statement  */
#line 133 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1604 "parser.tab.c"
    break;

  case 28: /* statements: statements statement  */
#line 134 "parser.y"
                           { (yyval.node) = createASTNode("STATEMENT_LIST", NULL, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1610 "parser.tab.c"
    break;

  case 29: /* statement: INPUT LPAREN expression RPAREN SEMICOLON  */
#line 139 "parser.y"
                                             { (yyval.node) = createASTNode("INPUT_EXPR", NULL, (yyvsp[-2].node), NULL); }
#line 1616 "parser.tab.c"
    break;

  case 30: /* statement: IF LPAREN expression RPAREN LBRACE statements RBRACE else_if_ladder_opt  */
#line 141 "parser.y"
          {
            if ((yyvsp[0].node) == NULL)
              (yyval.node) = createASTNode("IF", NULL, (yyvsp[-5].node), (yyvsp[-2].node));
            else
              (yyval.node) = createASTNode("IF_CHAIN", NULL, createASTNode("IF", NULL, (yyvsp[-5].node), (yyvsp[-2].node)), (yyvsp[0].node));
          }
#line 1627 "parser.tab.c"
    break;

  case 31: /* statement: LOOP IDENTIFIER ':' IDENTIFIER LBRACE statements RBRACE  */
#line 149 "parser.y"
          { (yyval.node) = createASTNode("ARRAY_ITERATOR", (yyvsp[-5].str), createASTNode("IDENTIFIER", (yyvsp[-3].str), NULL, NULL), (yyvsp[-1].node)); }
#line 1633 "parser.tab.c"
    break;

  case 32: /* statement: LOOP loop_header LBRACE statements RBRACE  */
#line 151 "parser.y"
          { (yyvsp[-3].node)->right = (yyvsp[-1].node); (yyval.node) = (yyvsp[-3].node); }
#line 1639 "parser.tab.c"
    break;

  case 33: /* statement: LOOP UNTIL LPAREN expression RPAREN LBRACE statements RBRACE  */
#line 153 "parser.y"
          { (yyval.node) = createASTNode("LOOP_UNTIL", NULL, (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1645 "parser.tab.c"
    break;

  case 34: /* statement: WHILE UNTIL expression LBRACE statements RBRACE  */
#line 155 "parser.y"
          { (yyval.node) = createASTNode("LOOP_UNTIL", NULL, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1651 "parser.tab.c"
    break;

  case 35: /* statement: INT IDENTIFIER ASSIGN expression SEMICOLON  */
#line 157 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_INT", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1657 "parser.tab.c"
    break;

  case 36: /* statement: INT IDENTIFIER IS expression SEMICOLON  */
#line 159 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_INT", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1663 "parser.tab.c"
    break;

  case 37: /* statement: FLOAT IDENTIFIER ASSIGN expression SEMICOLON  */
#line 161 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_FLOAT", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1669 "parser.tab.c"
    break;

  case 38: /* statement: FLOAT IDENTIFIER IS expression SEMICOLON  */
#line 163 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_FLOAT", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1675 "parser.tab.c"
    break;

  case 39: /* statement: BOOL IDENTIFIER ASSIGN BOOLEAN SEMICOLON  */
#line 165 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_BOOL", (yyvsp[-3].str), createASTNode("BOOLEAN", (yyvsp[-1].str), NULL, NULL), NULL); }
#line 1681 "parser.tab.c"
    break;

  case 40: /* statement: BOOL IDENTIFIER IS BOOLEAN SEMICOLON  */
#line 167 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_BOOL", (yyvsp[-3].str), createASTNode("BOOLEAN", (yyvsp[-1].str), NULL, NULL), NULL); }
#line 1687 "parser.tab.c"
    break;

  case 41: /* statement: CHAR IDENTIFIER ASSIGN CHAR_LITERAL SEMICOLON  */
#line 169 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_CHAR", (yyvsp[-3].str), createASTNode("CHAR", (yyvsp[-1].str), NULL, NULL), NULL); }
#line 1693 "parser.tab.c"
    break;

  case 42: /* statement: CHAR IDENTIFIER IS CHAR_LITERAL SEMICOLON  */
#line 171 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_CHAR", (yyvsp[-3].str), createASTNode("CHAR", (yyvsp[-1].str), NULL, NULL), NULL); }
#line 1699 "parser.tab.c"
    break;

  case 43: /* statement: CHAR IDENTIFIER ASSIGN expression SEMICOLON  */
#line 173 "parser.y"
            { (yyval.node) = createASTNode("ASSIGN_CHAR", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1705 "parser.tab.c"
    break;

  case 44: /* statement: STRING IDENTIFIER ASSIGN expression SEMICOLON  */
#line 176 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_STRING", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1711 "parser.tab.c"
    break;

  case 45: /* statement: STRING IDENTIFIER IS expression SEMICOLON  */
#line 178 "parser.y"
          { (yyval.node) = createASTNode("ASSIGN_STRING", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1717 "parser.tab.c"
    break;

  case 46: /* statement: VAR IDENTIFIER ASSIGN expression SEMICOLON  */
#line 180 "parser.y"
          { (yyval.node) = createASTNode("VAR_DECL", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1723 "parser.tab.c"
    break;

  case 47: /* statement: VAR IDENTIFIER IS expression SEMICOLON  */
#line 182 "parser.y"
          { (yyval.node) = createASTNode("VAR_DECL", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1729 "parser.tab.c"
    break;

  case 48: /* statement: IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON  */
#line 183 "parser.y"
                                                                          { (yyval.node) = createASTNode("ARRAY_ASSIGN", (yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1735 "parser.tab.c"
    break;

  case 49: /* statement: IDENTIFIER ASSIGN expression SEMICOLON  */
#line 186 "parser.y"
            { (yyval.node) = createASTNode("REASSIGN", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 1741 "parser.tab.c"
    break;

  case 50: /* statement: PRINT LPAREN expression RPAREN SEMICOLON  */
#line 188 "parser.y"
            { (yyval.node) = createASTNode("PRINT", NULL, (yyvsp[-2].node), NULL); }
#line 1747 "parser.tab.c"
    break;

  case 51: /* statement: PRINT LPAREN RPAREN SEMICOLON  */
#line 190 "parser.y"
            { (yyval.node) = createASTNode("PRINT_NEWLINE", NULL, NULL, NULL); }
#line 1753 "parser.tab.c"
    break;

  case 52: /* statement: COOKIE LPAREN RPAREN SEMICOLON  */
#line 192 "parser.y"
            { (yyval.node) = createASTNode("COOKIE", NULL, NULL, NULL); }
#line 1759 "parser.tab.c"
    break;

  case 53: /* statement: INLINE LPAREN expression RPAREN SEMICOLON  */
#line 194 "parser.y"
          { (yyval.node) = createASTNode("INLINE", NULL, (yyvsp[-2].node), NULL); }
#line 1765 "parser.tab.c"
    break;

  case 54: /* statement: INT IDENTIFIER SEMICOLON  */
#line 196 "parser.y"
          { (yyval.node) = createASTNode("DECL_INT", (yyvsp[-1].str), NULL, NULL); }
#line 1771 "parser.tab.c"
    break;

  case 55: /* statement: FLOAT IDENTIFIER SEMICOLON  */
#line 198 "parser.y"
          { (yyval.node) = createASTNode("DECL_FLOAT", (yyvsp[-1].str), NULL, NULL); }
#line 1777 "parser.tab.c"
    break;

  case 56: /* statement: BOOL IDENTIFIER SEMICOLON  */
#line 200 "parser.y"
          { (yyval.node) = createASTNode("DECL_BOOL", (yyvsp[-1].str), NULL, NULL); }
#line 1783 "parser.tab.c"
    break;

  case 57: /* statement: CHAR IDENTIFIER SEMICOLON  */
#line 202 "parser.y"
          { (yyval.node) = createASTNode("DECL_CHAR", (yyvsp[-1].str), NULL, NULL); }
#line 1789 "parser.tab.c"
    break;

  case 58: /* statement: STRING IDENTIFIER SEMICOLON  */
#line 204 "parser.y"
          { (yyval.node) = createASTNode("DECL_STRING", (yyvsp[-1].str), NULL, NULL); }
#line 1795 "parser.tab.c"
    break;

  case 59: /* statement: INT IDENTIFIER LBRACKET expression RBRACKET SEMICOLON  */
#line 206 "parser.y"
                                                            { (yyval.node) = createASTNode("DECL_ARRAY", (yyvsp[-4].str), (yyvsp[-2].node), NULL); }
#line 1801 "parser.tab.c"
    break;

  case 60: /* statement: FLOAT IDENTIFIER LBRACKET expression RBRACKET SEMICOLON  */
#line 207 "parser.y"
                                                              { (yyval.node) = createASTNode("DECL_ARRAY_FLOAT", (yyvsp[-4].str), (yyvsp[-2].node), NULL); }
#line 1807 "parser.tab.c"
    break;

  case 61: /* statement: BOOL IDENTIFIER LBRACKET expression RBRACKET SEMICOLON  */
#line 208 "parser.y"
                                                             { (yyval.node) = createASTNode("DECL_ARRAY_BOOL", (yyvsp[-4].str), (yyvsp[-2].node), NULL); }
#line 1813 "parser.tab.c"
    break;

  case 62: /* statement: CHAR IDENTIFIER LBRACKET expression RBRACKET SEMICOLON  */
#line 209 "parser.y"
                                                             { (yyval.node) = createASTNode("DECL_ARRAY_CHAR", (yyvsp[-4].str), (yyvsp[-2].node), NULL); }
#line 1819 "parser.tab.c"
    break;

  case 63: /* statement: STRING IDENTIFIER LBRACKET expression RBRACKET SEMICOLON  */
#line 210 "parser.y"
                                                               { (yyval.node) = createASTNode("DECL_ARRAY_STRING", (yyvsp[-4].str), (yyvsp[-2].node), NULL); }
#line 1825 "parser.tab.c"
    break;

  case 64: /* statement: INT IDENTIFIER LBRACKET RBRACKET ASSIGN LBRACE element_list RBRACE SEMICOLON  */
#line 212 "parser.y"
                                                                                   { (yyval.node) = createASTNode("DECL_ARRAY_INIT", (yyvsp[-7].str), (yyvsp[-2].node), NULL); }
#line 1831 "parser.tab.c"
    break;

  case 65: /* statement: FLOAT IDENTIFIER LBRACKET RBRACKET ASSIGN LBRACE element_list RBRACE SEMICOLON  */
#line 213 "parser.y"
                                                                                     { (yyval.node) = createASTNode("DECL_ARRAY_INIT_FLOAT", (yyvsp[-7].str), (yyvsp[-2].node), NULL); }
#line 1837 "parser.tab.c"
    break;

  case 66: /* statement: BOOL IDENTIFIER LBRACKET RBRACKET ASSIGN LBRACE element_list RBRACE SEMICOLON  */
#line 214 "parser.y"
                                                                                    { (yyval.node) = createASTNode("DECL_ARRAY_INIT_BOOL", (yyvsp[-7].str), (yyvsp[-2].node), NULL); }
#line 1843 "parser.tab.c"
    break;

  case 67: /* statement: CHAR IDENTIFIER LBRACKET RBRACKET ASSIGN LBRACE element_list RBRACE SEMICOLON  */
#line 215 "parser.y"
                                                                                    { (yyval.node) = createASTNode("DECL_ARRAY_INIT_CHAR", (yyvsp[-7].str), (yyvsp[-2].node), NULL); }
#line 1849 "parser.tab.c"
    break;

  case 68: /* statement: STRING IDENTIFIER LBRACKET RBRACKET ASSIGN LBRACE element_list RBRACE SEMICOLON  */
#line 216 "parser.y"
                                                                                      { (yyval.node) = createASTNode("DECL_ARRAY_INIT_STRING", (yyvsp[-7].str), (yyvsp[-2].node), NULL); }
#line 1855 "parser.tab.c"
    break;

  case 69: /* statement: RETURN LPAREN expression RPAREN SEMICOLON  */
#line 218 "parser.y"
          { (yyval.node) = createASTNode("RETURN", NULL, (yyvsp[-2].node), NULL); }
#line 1861 "parser.tab.c"
    break;

  case 70: /* statement: IDENTIFIER LPAREN argument_list_opt RPAREN SEMICOLON  */
#line 221 "parser.y"
          { (yyval.node) = createASTNode("CALL", (yyvsp[-4].str), (yyvsp[-2].node), NULL); }
#line 1867 "parser.tab.c"
    break;

  case 71: /* statement: SWITCH LPAREN expression RPAREN LBRACE case_list default_clause RBRACE  */
#line 224 "parser.y"
          { (yyval.node) = createASTNode("SWITCH", NULL, (yyvsp[-5].node), createASTNode("SWITCH_BODY", NULL, (yyvsp[-2].node), (yyvsp[-1].node))); }
#line 1873 "parser.tab.c"
    break;

  case 72: /* statement: BREAK SEMICOLON  */
#line 226 "parser.y"
                      { (yyval.node) = createASTNode("BREAK", NULL, NULL, NULL); }
#line 1879 "parser.tab.c"
    break;

  case 73: /* else_if_ladder_opt: %empty  */
#line 231 "parser.y"
                  { (yyval.node) = NULL; }
#line 1885 "parser.tab.c"
    break;

  case 74: /* else_if_ladder_opt: ELSE if_ladder  */
#line 232 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1891 "parser.tab.c"
    break;

  case 75: /* if_ladder: IF LPAREN expression RPAREN LBRACE statements RBRACE else_if_ladder_opt  */
#line 237 "parser.y"
          { (yyval.node) = createASTNode("ELSE_IF", NULL, (yyvsp[-5].node), createASTNode("IF_ELSE_BODY", NULL, (yyvsp[-2].node), (yyvsp[0].node))); }
#line 1897 "parser.tab.c"
    break;

  case 76: /* if_ladder: LBRACE statements RBRACE  */
#line 239 "parser.y"
          { (yyval.node) = createASTNode("ELSE", NULL, (yyvsp[-1].node), NULL); }
#line 1903 "parser.tab.c"
    break;

  case 77: /* case_list: case_clause  */
#line 244 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1909 "parser.tab.c"
    break;

  case 78: /* case_list: case_list case_clause  */
#line 245 "parser.y"
                            { (yyval.node) = createASTNode("CASE_LIST", NULL, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1915 "parser.tab.c"
    break;

  case 79: /* case_clause: CASE expression statements  */
#line 250 "parser.y"
                                 { (yyval.node) = createASTNode("CASE", NULL, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1921 "parser.tab.c"
    break;

  case 80: /* default_clause: %empty  */
#line 255 "parser.y"
                  { (yyval.node) = NULL; }
#line 1927 "parser.tab.c"
    break;

  case 81: /* default_clause: DEFAULT ':' statements  */
#line 256 "parser.y"
                             { (yyval.node) = createASTNode("DEFAULT", NULL, (yyvsp[0].node), NULL); }
#line 1933 "parser.tab.c"
    break;

  case 82: /* expression: logical_or_expression  */
#line 261 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1939 "parser.tab.c"
    break;

  case 83: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 265 "parser.y"
                                                    { (yyval.node) = createASTNode("OR", "||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1945 "parser.tab.c"
    break;

  case 84: /* logical_or_expression: logical_and_expression  */
#line 266 "parser.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1951 "parser.tab.c"
    break;

  case 85: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 270 "parser.y"
                                                   { (yyval.node) = createASTNode("AND", "&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1957 "parser.tab.c"
    break;

  case 86: /* logical_and_expression: equality_expression  */
#line 271 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1963 "parser.tab.c"
    break;

  case 87: /* equality_expression: equality_expression EQ relational_expression  */
#line 275 "parser.y"
                                                 { (yyval.node) = createASTNode("EQ", "==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1969 "parser.tab.c"
    break;

  case 88: /* equality_expression: equality_expression NE relational_expression  */
#line 276 "parser.y"
                                                   { (yyval.node) = createASTNode("NE", "!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1975 "parser.tab.c"
    break;

  case 89: /* equality_expression: relational_expression  */
#line 277 "parser.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 1981 "parser.tab.c"
    break;

  case 90: /* relational_expression: relational_expression LT additive_expression  */
#line 281 "parser.y"
                                                 { (yyval.node) = createASTNode("LT", "<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1987 "parser.tab.c"
    break;

  case 91: /* relational_expression: relational_expression GT additive_expression  */
#line 282 "parser.y"
                                                   { (yyval.node) = createASTNode("GT", ">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1993 "parser.tab.c"
    break;

  case 92: /* relational_expression: relational_expression LE additive_expression  */
#line 283 "parser.y"
                                                   { (yyval.node) = createASTNode("LE", "<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1999 "parser.tab.c"
    break;

  case 93: /* relational_expression: relational_expression GE additive_expression  */
#line 284 "parser.y"
                                                   { (yyval.node) = createASTNode("GE", ">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2005 "parser.tab.c"
    break;

  case 94: /* relational_expression: additive_expression  */
#line 285 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2011 "parser.tab.c"
    break;

  case 95: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 289 "parser.y"
                                                       { (yyval.node) = createASTNode("ADD", "+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2017 "parser.tab.c"
    break;

  case 96: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 290 "parser.y"
                                                          { (yyval.node) = createASTNode("SUB", "-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2023 "parser.tab.c"
    break;

  case 97: /* additive_expression: multiplicative_expression  */
#line 291 "parser.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2029 "parser.tab.c"
    break;

  case 98: /* multiplicative_expression: multiplicative_expression MULTIPLY primary  */
#line 295 "parser.y"
                                               { (yyval.node) = createASTNode("MUL", "*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2035 "parser.tab.c"
    break;

  case 99: /* multiplicative_expression: multiplicative_expression DIVIDE primary  */
#line 296 "parser.y"
                                               { (yyval.node) = createASTNode("DIV", "/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2041 "parser.tab.c"
    break;

  case 100: /* multiplicative_expression: primary  */
#line 297 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2047 "parser.tab.c"
    break;

  case 101: /* primary: primary DOT IDENTIFIER LPAREN argument_list_opt RPAREN  */
#line 301 "parser.y"
                                                           { (yyval.node) = createASTNode("METHOD_CALL", (yyvsp[-3].str), (yyvsp[-5].node), (yyvsp[-1].node)); }
#line 2053 "parser.tab.c"
    break;

  case 102: /* primary: NOT primary  */
#line 302 "parser.y"
                  { (yyval.node) = createASTNode("NOT", "!", (yyvsp[0].node), NULL); }
#line 2059 "parser.tab.c"
    break;

  case 103: /* primary: MINUS primary  */
#line 303 "parser.y"
                    { (yyval.node) = createASTNode("NEG", "-", (yyvsp[0].node), NULL); }
#line 2065 "parser.tab.c"
    break;

  case 104: /* primary: SIZE LPAREN expression RPAREN  */
#line 304 "parser.y"
                                    { (yyval.node) = createASTNode("SIZE", NULL, (yyvsp[-1].node), NULL); }
#line 2071 "parser.tab.c"
    break;

  case 105: /* primary: NUMBER  */
#line 305 "parser.y"
             { (yyval.node) = createASTNode("NUMBER", (yyvsp[0].str), NULL, NULL); }
#line 2077 "parser.tab.c"
    break;

  case 106: /* primary: FLOAT_NUMBER  */
#line 306 "parser.y"
                   { (yyval.node) = createASTNode("FLOAT", (yyvsp[0].str), NULL, NULL); }
#line 2083 "parser.tab.c"
    break;

  case 107: /* primary: BOOLEAN  */
#line 307 "parser.y"
              { (yyval.node) = createASTNode("BOOLEAN", (yyvsp[0].str), NULL, NULL); }
#line 2089 "parser.tab.c"
    break;

  case 108: /* primary: CHAR_LITERAL  */
#line 308 "parser.y"
                   { (yyval.node) = createASTNode("CHAR", (yyvsp[0].str), NULL, NULL); }
#line 2095 "parser.tab.c"
    break;

  case 109: /* primary: STRING_LITERAL  */
#line 309 "parser.y"
                     { (yyval.node) = createASTNode("STRING", (yyvsp[0].str), NULL, NULL); }
#line 2101 "parser.tab.c"
    break;

  case 110: /* primary: INT LPAREN expression RPAREN  */
#line 310 "parser.y"
                                      { (yyval.node) = createASTNode("CAST_INT", NULL, (yyvsp[-1].node), NULL); }
#line 2107 "parser.tab.c"
    break;

  case 111: /* primary: FLOAT LPAREN expression RPAREN  */
#line 311 "parser.y"
                                      { (yyval.node) = createASTNode("CAST_FLOAT", NULL, (yyvsp[-1].node), NULL); }
#line 2113 "parser.tab.c"
    break;

  case 112: /* primary: STRING LPAREN expression RPAREN  */
#line 312 "parser.y"
                                      { (yyval.node) = createASTNode("CAST_STRING", NULL, (yyvsp[-1].node), NULL); }
#line 2119 "parser.tab.c"
    break;

  case 113: /* primary: CHAR LPAREN expression RPAREN  */
#line 313 "parser.y"
                                      { (yyval.node) = createASTNode("CAST_CHAR", NULL, (yyvsp[-1].node), NULL); }
#line 2125 "parser.tab.c"
    break;

  case 114: /* primary: IDENTIFIER LPAREN argument_list_opt RPAREN  */
#line 314 "parser.y"
                                                 { (yyval.node) = createASTNode("CALL", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 2131 "parser.tab.c"
    break;

  case 115: /* primary: IDENTIFIER LBRACKET expression RBRACKET  */
#line 315 "parser.y"
                                              { (yyval.node) = createASTNode("ARRAY_ACCESS", (yyvsp[-3].str), (yyvsp[-1].node), NULL); }
#line 2137 "parser.tab.c"
    break;

  case 116: /* primary: IDENTIFIER  */
#line 316 "parser.y"
                 { (yyval.node) = createASTNode("IDENTIFIER", (yyvsp[0].str), NULL, NULL); }
#line 2143 "parser.tab.c"
    break;

  case 117: /* primary: LPAREN expression RPAREN  */
#line 317 "parser.y"
                               { (yyval.node) = (yyvsp[-1].node); }
#line 2149 "parser.tab.c"
    break;

  case 118: /* primary: TYPE LPAREN expression RPAREN  */
#line 318 "parser.y"
                                    { (yyval.node) = createASTNode("TYPE", NULL, (yyvsp[-1].node), NULL); }
#line 2155 "parser.tab.c"
    break;


#line 2159 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 321 "parser.y"


void yyerror(const char *s) {
  fprintf(stderr, "Error: %s\n", s);
}
