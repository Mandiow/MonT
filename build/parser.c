/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <math.h>
#include "main.h"
int Func_type;
int param = 0;
int chamada = 0;
int dimensions = 0;
int attDimensions = 0;
int globalOffset = 0;
int frameOffset = 0; // Deixando pra etapa 6... LEMBRA DE ZERAR ESSA JOÇA // EU ADORO LER DEPOIS DE ME FUDER =.=

#line 79 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_HOME_MANDIOW_REA_DE_TRABALHO_MONT_BUILD_PARSER_H_INCLUDED
# define YY_YY_HOME_MANDIOW_REA_DE_TRABALHO_MONT_BUILD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_STATIC = 271,
    TK_PR_CONST = 272,
    TK_OC_LE = 273,
    TK_OC_GE = 274,
    TK_OC_EQ = 275,
    TK_OC_NE = 276,
    TK_OC_AND = 277,
    TK_OC_OR = 278,
    TK_OC_NOT = 279,
    TK_LIT_INT = 280,
    TK_LIT_FLOAT = 281,
    TK_LIT_FALSE = 282,
    TK_LIT_TRUE = 283,
    TK_LIT_CHAR = 284,
    TK_LIT_STRING = 285,
    TK_IDENTIFICADOR = 286,
    TOKEN_ERRO = 287,
    LOWER_THAN_ELSE = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:355  */

	struct comp_tree_t *syntaxTree;
	struct stack_item *main_stack;
	struct stack_item *call_stack;
	struct stack_item *lazyStack;
	struct comp_dict_item_t *valor_simbolo_lexico;
	struct comp_list_t *list_dimensions;
	int type;

#line 163 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_MANDIOW_REA_DE_TRABALHO_MONT_BUILD_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 178 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,     2,     2,     2,
      48,    49,    41,    39,    47,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      37,    33,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   113,   131,   132,   133,   137,   147,   148,
     152,   153,   158,   160,   157,   175,   175,   180,   184,   185,
     189,   190,   194,   200,   204,   205,   206,   207,   208,   209,
     213,   214,   215,   216,   217,   221,   222,   223,   224,   225,
     226,   230,   231,   235,   236,   255,   262,   266,   274,   275,
     279,   280,   281,   285,   286,   287,   288,   289,   289,   290,
     291,   292,   296,   300,   304,   305,   309,   324,   325,   329,
     330,   331,   332,   336,   347,   351,   352,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_STATIC", "TK_PR_CONST", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_OC_NOT", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_LIT_CHAR",
  "TK_LIT_STRING", "TK_IDENTIFICADOR", "TOKEN_ERRO", "'='", "'{'", "'}'",
  "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "LOWER_THAN_ELSE",
  "';'", "'['", "']'", "','", "'('", "')'", "$accept", "start", "$@1",
  "programa", "declaracao_global", "Array", "declarar_funcao", "$@2",
  "$@3", "$@4", "escopo", "parametros_vazio", "parametros",
  "lista_parametros", "literal", "especificador_tipo", "declaracao_local",
  "valor", "ID", "Exparray", "atribuicao", "retorno", "bloco_comando",
  "comando", "$@5", "entrada", "saida", "lista_vazia", "lista_expressoes",
  "mais_de_uma", "controle_fluxo", "chamada_funcao", "nome", "expressao", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    61,   123,   125,    33,    60,    62,    43,
      45,    42,    47,   288,    59,    91,    93,    44,    40,    41
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -144,     6,   306,  -144,  -144,  -144,  -144,  -144,  -144,   179,
    -144,   -41,   306,   -18,     5,     7,   306,  -144,    40,   -22,
     -11,  -144,   179,     0,  -144,     4,    25,    38,    38,    40,
      53,  -144,    40,  -144,    24,    39,    48,    54,  -144,    71,
    -144,    38,  -144,  -144,  -144,  -144,  -144,    73,    75,    75,
      60,    63,    75,   256,   256,   256,    93,   179,    16,  -144,
      81,  -144,    80,  -144,  -144,    90,    82,  -144,  -144,  -144,
    -144,    79,    94,   256,   256,   120,   256,  -144,  -144,  -144,
    -144,  -144,  -144,    56,   256,   256,  -144,  -144,   228,  -144,
     177,   253,   179,   113,   156,   256,    75,   194,   256,  -144,
      75,   256,  -144,   101,   114,   165,  -144,   256,   -24,   139,
     256,   256,   256,   256,   256,   256,   182,   256,   256,   256,
     256,   256,   256,   256,  -144,   190,   204,   205,   185,   188,
     197,   298,   253,  -144,   184,  -144,   225,   230,   256,   218,
    -144,   163,   163,   163,   163,   279,   127,   256,   163,   163,
     -24,   -24,  -144,  -144,  -144,   226,   298,   298,  -144,   256,
    -144,  -144,  -144,  -144,  -144,    75,    75,   152,  -144,   253,
     298,  -144,  -144,  -144,   233,  -144,  -144,  -144,    75,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,    30,    31,    32,    33,    34,     0,
       3,     0,     6,     0,     0,     0,     6,     5,    19,     8,
       0,     4,     0,     0,    18,    21,     0,     0,     0,    19,
       0,    12,     0,    22,    11,     0,     0,     0,    23,     0,
      20,     0,     7,     9,    15,    13,    10,     0,    52,    52,
       0,     0,     0,     0,     0,    49,     0,     0,    43,    57,
       0,    55,     0,    54,    53,     0,    51,    59,    61,    56,
      60,     0,     0,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,    75,     0,     0,    77,    93,     0,    63,
      68,    48,     0,     0,     0,     0,    52,    35,     0,    14,
      52,    65,    16,     0,     0,     0,    83,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,    37,     0,     0,    46,
       0,     0,    47,    50,     0,    64,     0,     0,     0,     0,
      92,    86,    87,    88,    89,    90,    91,     0,    84,    85,
      81,    80,    79,    78,    67,     0,     0,     0,    44,     0,
      58,    42,    41,    36,    73,     0,     0,     0,    76,    62,
       0,    38,    40,    45,    70,    71,    72,    39,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,     8,  -144,   -19,  -144,  -144,  -144,  -144,
    -144,   216,   220,  -144,  -115,     3,  -144,  -143,  -144,    95,
    -144,  -144,   -42,   -50,  -144,  -144,  -144,  -144,   -90,  -144,
    -144,   -48,  -144,   -45
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    11,    35,    12,    39,    48,    47,
      13,    23,    24,    25,    86,    60,    61,   163,    62,   128,
      63,    64,    65,    66,    96,    67,    68,   134,    89,   124,
      69,    87,    71,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    70,    75,    16,    70,    14,     3,    72,    88,    36,
      91,   135,    15,   171,   172,    14,   162,   121,   122,    14,
      17,    26,    46,    27,    21,    30,   -17,   177,   103,   104,
      18,   106,    26,   154,    28,    26,    19,    29,    20,   108,
     109,   162,   162,     4,     5,     6,     7,     8,    70,    31,
     129,    32,    70,   132,   130,   162,    33,    22,   133,    93,
      94,    95,   139,    34,   -74,   141,   142,   143,   144,   145,
     146,    41,   148,   149,   150,   151,   152,   153,     4,     5,
       6,     7,     8,    50,    38,    42,    51,    52,    53,    54,
      55,    56,    57,   167,    43,   125,     4,     5,     6,     7,
       8,   107,   169,    44,   -74,    45,    58,    49,    73,    59,
      92,    74,    97,    98,   129,   174,   175,    70,    70,   110,
     111,   112,   113,   114,   115,    99,   100,   101,   179,   102,
      70,   105,   110,   111,   112,   113,   114,   115,   117,   118,
     119,   120,   121,   122,   126,   110,   111,   112,   113,   114,
     136,   117,   118,   119,   120,   121,   122,   110,   111,   112,
     113,   114,   115,   137,   117,   118,   119,   120,   121,   122,
     110,   111,   112,   113,   114,   115,   117,   118,   119,   120,
     121,   122,     4,     5,     6,     7,     8,   127,   140,   117,
     118,   119,   120,   121,   122,   110,   111,   112,   113,   114,
     115,   176,   119,   120,   121,   122,   110,   111,   112,   113,
     114,   115,   131,   138,   117,   118,   119,   120,   121,   122,
     147,   155,   156,   157,   123,   117,   118,   119,   120,   121,
     122,   158,   160,   164,   165,   159,   110,   111,   112,   113,
     114,   115,   166,   178,   170,    37,   110,   111,   112,   113,
     114,   115,    40,     0,   173,   117,   118,   119,   120,   121,
     122,   116,     0,     0,   168,   117,   118,   119,   120,   121,
     122,   110,   111,   112,   113,   114,   115,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
     117,   118,   119,   120,   121,   122,    84,   110,   111,   112,
     113,     0,     0,     0,    85,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     0,     0,   117,   118,   119,   120,
     121,   122,     9,    77,    78,    79,    80,    81,    82,   161
};

static const yytype_int16 yycheck[] =
{
      48,    49,    52,    44,    52,     2,     0,    49,    53,    28,
      55,   101,     9,   156,   157,    12,   131,    41,    42,    16,
      12,    18,    41,    45,    16,    22,    48,   170,    73,    74,
      48,    76,    29,   123,    45,    32,    31,    48,    31,    84,
      85,   156,   157,     3,     4,     5,     6,     7,    96,    49,
      95,    47,   100,    98,    96,   170,    31,    17,   100,    56,
      57,    45,   107,    25,    48,   110,   111,   112,   113,   114,
     115,    47,   117,   118,   119,   120,   121,   122,     3,     4,
       5,     6,     7,     8,    31,    46,    11,    12,    13,    14,
      15,    16,    17,   138,    46,    92,     3,     4,     5,     6,
       7,    45,   147,    49,    48,    34,    31,    34,    48,    34,
      17,    48,    31,    33,   159,   165,   166,   165,   166,    18,
      19,    20,    21,    22,    23,    35,    44,    48,   178,    35,
     178,    11,    18,    19,    20,    21,    22,    23,    37,    38,
      39,    40,    41,    42,    31,    18,    19,    20,    21,    22,
      49,    37,    38,    39,    40,    41,    42,    18,    19,    20,
      21,    22,    23,    49,    37,    38,    39,    40,    41,    42,
      18,    19,    20,    21,    22,    23,    37,    38,    39,    40,
      41,    42,     3,     4,     5,     6,     7,    31,    49,    37,
      38,    39,    40,    41,    42,    18,    19,    20,    21,    22,
      23,    49,    39,    40,    41,    42,    18,    19,    20,    21,
      22,    23,    18,    48,    37,    38,    39,    40,    41,    42,
      38,    31,    18,    18,    47,    37,    38,    39,    40,    41,
      42,    46,    35,    49,     9,    47,    18,    19,    20,    21,
      22,    23,    12,    10,    18,    29,    18,    19,    20,    21,
      22,    23,    32,    -1,   159,    37,    38,    39,    40,    41,
      42,    33,    -1,    -1,    46,    37,    38,    39,    40,    41,
      42,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      37,    38,    39,    40,    41,    42,    40,    18,    19,    20,
      21,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    37,    38,    39,    40,
      41,    42,    16,    25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,     3,     4,     5,     6,     7,    16,
      53,    54,    56,    60,    65,    65,    44,    53,    48,    31,
      31,    53,    17,    61,    62,    63,    65,    45,    45,    48,
      65,    49,    47,    31,    25,    55,    55,    61,    31,    57,
      62,    47,    46,    46,    49,    34,    55,    59,    58,    34,
       8,    11,    12,    13,    14,    15,    16,    17,    31,    34,
      65,    66,    68,    70,    71,    72,    73,    75,    76,    80,
      81,    82,    72,    48,    48,    73,    24,    25,    26,    27,
      28,    29,    30,    31,    40,    48,    64,    81,    83,    78,
      83,    83,    17,    65,    65,    45,    74,    31,    33,    35,
      44,    48,    35,    83,    83,    11,    83,    45,    83,    83,
      18,    19,    20,    21,    22,    23,    33,    37,    38,    39,
      40,    41,    42,    47,    79,    65,    31,    31,    69,    83,
      72,    18,    83,    72,    77,    78,    49,    49,    48,    83,
      49,    83,    83,    83,    83,    83,    83,    38,    83,    83,
      83,    83,    83,    83,    78,    31,    18,    18,    46,    47,
      35,    31,    64,    67,    49,     9,    12,    83,    46,    83,
      18,    67,    67,    69,    73,    73,    49,    67,    10,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    53,    53,    53,    54,    54,    54,
      55,    55,    57,    58,    56,    59,    56,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    73,    74,    73,    73,
      73,    73,    75,    76,    77,    77,    78,    79,    79,    80,
      80,    80,    80,    81,    82,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     0,     5,     2,     6,
       3,     1,     0,     0,     9,     0,    10,     2,     1,     0,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     3,     5,     6,
       5,     1,     1,     1,     4,     3,     1,     3,     2,     1,
       3,     1,     0,     1,     1,     1,     1,     0,     4,     1,
       1,     1,     5,     2,     1,     0,     2,     2,     0,     8,
       6,     6,     6,     4,     1,     1,     4,     1,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 113 "parser.y" /* yacc.c:1646  */
    {;initializeList(&list_dimensions);}
#line 1411 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 113 "parser.y" /* yacc.c:1646  */
    {
					(yyval.syntaxTree) = createNode(AST_PROGRAMA,NULL);
					if((yyvsp[0].syntaxTree) != NULL)appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));
					syntaxTree = (yyval.syntaxTree);
					//showTree($$);
					//gv_create_initial_tree($$); 
					shortCircuit((yyval.syntaxTree),NULL,NULL);
					}
#line 1424 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree)=(yyvsp[0].syntaxTree);}
#line 1430 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[-1].syntaxTree);if((yyvsp[0].syntaxTree) != NULL)appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));}
#line 1436 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;}
#line 1442 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 137 "parser.y" /* yacc.c:1646  */
    {
															(yyvsp[-3].valor_simbolo_lexico)->iks_type = (yyvsp[-4].type);
															copyList(list_dimensions,&(yyvsp[-3].valor_simbolo_lexico)->array);
															(yyvsp[-3].valor_simbolo_lexico)->array->dimensions = dimensions;
															stack_push(&main_stack,(yyvsp[-3].valor_simbolo_lexico),data_item, 1);
															dimensions = 0;
															setTypeSize((yyvsp[-3].valor_simbolo_lexico),(yyvsp[-3].valor_simbolo_lexico)->array,globalDeclaration);
															deleteList(&list_dimensions);
															//printList($2->array);
														}
#line 1457 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].valor_simbolo_lexico)->iks_type = (yyvsp[-1].type);(yyvsp[0].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR;setTypeSize((yyvsp[0].valor_simbolo_lexico),NULL,globalDeclaration); stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),data_item, 1);}
#line 1463 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 148 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-3].valor_simbolo_lexico)->iks_type = (yyvsp[-4].type);setTypeSize((yyvsp[-3].valor_simbolo_lexico),(yyvsp[-3].valor_simbolo_lexico)->array,globalDeclaration);stack_push(&main_stack,(yyvsp[-3].valor_simbolo_lexico),data_item, 1);dimensions = 0; deleteList(&list_dimensions);}
#line 1469 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 152 "parser.y" /* yacc.c:1646  */
    {dimensions++;listAppendElem(&list_dimensions,(yyvsp[-2].valor_simbolo_lexico)->token.integer);}
#line 1475 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 153 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].valor_simbolo_lexico)->token.integer > 0)(yyval.valor_simbolo_lexico) = (yyvsp[0].valor_simbolo_lexico);else exit(IKS_NULL_DIMENSION);listAppendElem(&list_dimensions,(yyvsp[0].valor_simbolo_lexico)->token.integer); dimensions ++;}
#line 1481 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "parser.y" /* yacc.c:1646  */
    {paramcounter(&main_stack,param);}
#line 1487 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "parser.y" /* yacc.c:1646  */
    {stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),block_item,0);}
#line 1493 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
										(yyval.syntaxTree)->tableItem->scopeType = 3;
										(yyvsp[-8].syntaxTree)->frame = frameOffset + localOffset;
										localOffset = 0;
										frameOffset = 0;
										(yyval.syntaxTree) = (yyvsp[-8].syntaxTree);
										if((yyvsp[-1].syntaxTree) !=NULL)
											appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));
										
										param = 0;
										stack_popBlock(&main_stack);
									}
#line 1510 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 175 "parser.y" /* yacc.c:1646  */
    {Func_type = (yyvsp[-4].type);}
#line 1516 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_FUNCAO,(yyvsp[-7].valor_simbolo_lexico));if((yyvsp[-1].syntaxTree) !=NULL)appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));}
#line 1522 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 180 "parser.y" /* yacc.c:1646  */
    {Func_type = (yyvsp[-1].type);(yyvsp[0].valor_simbolo_lexico)->iks_type = (yyvsp[-1].type); (yyval.syntaxTree) = createNode(AST_FUNCAO,(yyvsp[0].valor_simbolo_lexico));stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),func_item, 1);}
#line 1528 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_simbolo_lexico)->iks_type = (yyvsp[-1].type); 
										    stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),param_item, 1); 
										    param++;
										    setTypeSize((yyvsp[0].valor_simbolo_lexico),NULL,4);
										    frameOffset+=(yyvsp[0].valor_simbolo_lexico)->size;
										  }
#line 1539 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].valor_simbolo_lexico)->iks_type = (yyvsp[-1].type);stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),param_item, 1); param++;}
#line 1545 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LITERAL, (yyvsp[0].valor_simbolo_lexico)); }
#line 1551 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LITERAL, (yyvsp[0].valor_simbolo_lexico));}
#line 1557 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LITERAL, (yyvsp[0].valor_simbolo_lexico));}
#line 1563 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LITERAL, (yyvsp[0].valor_simbolo_lexico));}
#line 1569 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LITERAL, (yyvsp[0].valor_simbolo_lexico));}
#line 1575 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LITERAL, (yyvsp[0].valor_simbolo_lexico));}
#line 1581 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = IKS_INT;}
#line 1587 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = IKS_FLOAT;}
#line 1593 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = IKS_BOOL;}
#line 1599 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = IKS_CHAR;}
#line 1605 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.type) = IKS_STRING;}
#line 1611 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;(yyvsp[0].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR; (yyvsp[0].valor_simbolo_lexico)->iks_type = (yyvsp[-1].type);setTypeSize((yyvsp[0].valor_simbolo_lexico),NULL,localDeclaration);stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),data_item, 1);}
#line 1617 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;(yyvsp[-2].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR; (yyvsp[-2].valor_simbolo_lexico)->iks_type = (yyvsp[-3].type);setTypeSize((yyvsp[-2].valor_simbolo_lexico),NULL,localDeclaration);stack_push(&main_stack,(yyvsp[-2].valor_simbolo_lexico),data_item, 1);typeCoercion((yyvsp[-2].valor_simbolo_lexico),(yyvsp[0].syntaxTree)->tableItem,0);}
#line 1623 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;(yyvsp[0].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR; (yyvsp[0].valor_simbolo_lexico)->iks_type = (yyvsp[-1].type);setTypeSize((yyvsp[0].valor_simbolo_lexico),NULL,localDeclaration);stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),data_item, 1);}
#line 1629 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 224 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;(yyvsp[-2].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR; (yyvsp[-2].valor_simbolo_lexico)->iks_type = (yyvsp[-3].type);setTypeSize((yyvsp[-2].valor_simbolo_lexico),NULL,localDeclaration);stack_push(&main_stack,(yyvsp[-2].valor_simbolo_lexico),data_item, 1);typeCoercion((yyvsp[-2].valor_simbolo_lexico),(yyvsp[0].syntaxTree)->tableItem,0);}
#line 1635 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 225 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;(yyvsp[-2].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR; (yyvsp[-2].valor_simbolo_lexico)->iks_type = (yyvsp[-3].type);setTypeSize((yyvsp[-2].valor_simbolo_lexico),NULL,localDeclaration);stack_push(&main_stack,(yyvsp[-2].valor_simbolo_lexico),data_item, 1);typeCoercion((yyvsp[-2].valor_simbolo_lexico),(yyvsp[0].syntaxTree)->tableItem,0);}
#line 1641 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 226 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;(yyvsp[-2].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR; (yyvsp[-2].valor_simbolo_lexico)->iks_type = (yyvsp[-3].type);setTypeSize((yyvsp[-2].valor_simbolo_lexico),NULL,localDeclaration);stack_push(&main_stack,(yyvsp[-2].valor_simbolo_lexico),data_item, 1);typeCoercion((yyvsp[-2].valor_simbolo_lexico),(yyvsp[0].syntaxTree)->tableItem,0);}
#line 1647 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1653 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 231 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_IDENTIFICADOR,(yyvsp[0].valor_simbolo_lexico));}
#line 1659 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 235 "parser.y" /* yacc.c:1646  */
    { stack_isDeclared(main_stack,(yyvsp[0].valor_simbolo_lexico),AST_IDENTIFICADOR);(yyval.syntaxTree) = createNode(AST_IDENTIFICADOR,(yyvsp[0].valor_simbolo_lexico));(yyval.syntaxTree)->iks_type = (yyvsp[0].valor_simbolo_lexico)->iks_type;}
#line 1665 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 236 "parser.y" /* yacc.c:1646  */
    {	
											if (attDimensions != (yyvsp[-3].valor_simbolo_lexico)->array->dimensions)
											{
												exit(IKS_VECTOR_INVALID_ACCESS);
											}
											(yyval.syntaxTree) = createNode(AST_VETOR_INDEXADO,NULL);
											(yyvsp[-3].valor_simbolo_lexico)->nodeType = AST_VETOR_INDEXADO;
											stack_isDeclared(main_stack,(yyvsp[-3].valor_simbolo_lexico),AST_VETOR_INDEXADO);
											(yyvsp[-3].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR;
											if ((yyvsp[-1].syntaxTree)->iks_type == IKS_STRING) exit(IKS_ERROR_STRING_TO_X);
											if ((yyvsp[-1].syntaxTree)->iks_type == IKS_CHAR) exit(IKS_ERROR_CHAR_TO_X);
											appendChildNode((yyval.syntaxTree),createNode(AST_IDENTIFICADOR,(yyvsp[-3].valor_simbolo_lexico)));
											appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));
											attDimensions = 0;
											
										   }
#line 1686 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 255 "parser.y" /* yacc.c:1646  */
    {	(yyval.syntaxTree) = (yyvsp[-2].syntaxTree); 
								if((yyvsp[0].syntaxTree) != NULL)
								{
									appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));
								}
								attDimensions++;
							}
#line 1698 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);attDimensions++;}
#line 1704 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 266 "parser.y" /* yacc.c:1646  */
    {
							(yyval.syntaxTree) = createNode(AST_ATRIBUICAO,(yyvsp[-1].valor_simbolo_lexico)); 
							appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));
							appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));
							typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1714 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 274 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_RETURN,NULL); (yyval.syntaxTree)->iks_type = Func_type;appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));returnCoercion(Func_type,(yyvsp[0].syntaxTree));(yyval.syntaxTree)->frame = frameOffset + localOffset;}
#line 1720 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_RETURN,NULL);(yyval.syntaxTree)->frame = frameOffset + localOffset; }
#line 1726 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[-2].syntaxTree); if((yyvsp[-2].syntaxTree) != NULL)appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));else (yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1732 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 280 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0].syntaxTree) != NULL)(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1738 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;}
#line 1744 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1750 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1756 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1762 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1768 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 289 "parser.y" /* yacc.c:1646  */
    {stack_push(&main_stack,(yyvsp[0].valor_simbolo_lexico),block_item, 0);}
#line 1774 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 289 "parser.y" /* yacc.c:1646  */
    {stack_popBlock(&main_stack); (yyval.syntaxTree) = createNode(AST_BLOCO, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));}
#line 1780 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1786 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1792 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1798 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_INPUT, NULL); appendChildNode((yyval.syntaxTree),(yyvsp[-3].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeCoercion((yyvsp[-3].syntaxTree)->tableItem,(yyvsp[0].syntaxTree)->tableItem,2);}
#line 1804 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_OUTPUT,NULL);appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree)); if((yyvsp[0].syntaxTree)->iks_type == IKS_CHAR)exit(IKS_WRONG_PAR_OUTPUT);}
#line 1810 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);(yyval.syntaxTree)->iks_type = (yyvsp[0].syntaxTree)->iks_type;}
#line 1816 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL;}
#line 1822 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 309 "parser.y" /* yacc.c:1646  */
    {	(yyval.syntaxTree) = (yyvsp[-1].syntaxTree);
								(yyval.syntaxTree)->iks_type = (yyvsp[-1].syntaxTree)->iks_type; 

								stack_push(&call_stack, (yyvsp[-1].syntaxTree)->tableItem,param_item, 0);
								(yyvsp[-1].syntaxTree)->IWANNAABOOLEAN = 1;
								if((yyvsp[0].syntaxTree) != NULL)
								{
									appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));
									(yyvsp[0].syntaxTree)->IWANNAABOOLEAN = 1;
								}
								
							}
#line 1839 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree); chamada++;}
#line 1845 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = NULL; chamada++;}
#line 1851 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 329 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_IF_ELSE,NULL); appendChildNode((yyval.syntaxTree),(yyvsp[-5].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));(yyval.syntaxTree)->ifThenElse = 1;}
#line 1857 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 330 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_IF_ELSE,NULL); appendChildNode((yyval.syntaxTree),(yyvsp[-3].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));(yyval.syntaxTree)->ifThenElse = 0;}
#line 1863 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 331 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_WHILE_DO,NULL); appendChildNode((yyval.syntaxTree),(yyvsp[-3].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));}
#line 1869 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 332 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_DO_WHILE,NULL); appendChildNode((yyval.syntaxTree),(yyvsp[-4].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));}
#line 1875 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 336 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_CHAMADA_DE_FUNCAO,NULL);Function_Comparsion(chamada,main_stack,call_stack,(yyval.syntaxTree)); (yyval.syntaxTree)->iks_type = (yyvsp[-3].syntaxTree)->iks_type; appendChildNode((yyval.syntaxTree),(yyvsp[-3].syntaxTree));if((yyvsp[-1].syntaxTree) != NULL) {appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));}(yyval.syntaxTree)->iks_type = getFunctionType(main_stack,call_stack);
									copyStack(call_stack,&lazyStack);

									while(call_stack != NULL)
										stack_pop(&call_stack);
									copyStack(lazyStack,&(yyval.syntaxTree)->functionStack);
									while(lazyStack != NULL)
										stack_pop(&lazyStack);
									 chamada = 0;}
#line 1889 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].valor_simbolo_lexico)->scopeType = 3; stack_isDeclared(main_stack,(yyvsp[0].valor_simbolo_lexico),AST_FUNCAO);(yyval.syntaxTree) = createNode(AST_IDENTIFICADOR,(yyvsp[0].valor_simbolo_lexico));stack_push(&call_stack,(yyvsp[0].valor_simbolo_lexico),func_item, 0);}
#line 1895 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 351 "parser.y" /* yacc.c:1646  */
    {stack_isDeclared(main_stack,(yyvsp[0].valor_simbolo_lexico),AST_IDENTIFICADOR);(yyval.syntaxTree) = createNode(AST_IDENTIFICADOR,(yyvsp[0].valor_simbolo_lexico));}
#line 1901 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 352 "parser.y" /* yacc.c:1646  */
    {	(yyval.syntaxTree) = createNode(AST_VETOR_INDEXADO,NULL);
											(yyval.syntaxTree)->iks_type = (yyvsp[-3].valor_simbolo_lexico)->iks_type;
											(yyvsp[-3].valor_simbolo_lexico)->nodeType = AST_VETOR_INDEXADO;
											stack_isDeclared(main_stack,(yyvsp[-3].valor_simbolo_lexico),AST_VETOR_INDEXADO);
											(yyvsp[-3].valor_simbolo_lexico)->nodeType = AST_IDENTIFICADOR;
											if ((yyvsp[-1].syntaxTree)->iks_type == IKS_STRING) exit(IKS_ERROR_STRING_TO_X);
											if ((yyvsp[-1].syntaxTree)->iks_type == IKS_CHAR) exit(IKS_ERROR_CHAR_TO_X);
											appendChildNode((yyval.syntaxTree),createNode(AST_IDENTIFICADOR,(yyvsp[-3].valor_simbolo_lexico)));
											appendChildNode((yyval.syntaxTree),(yyvsp[-1].syntaxTree));
											
										   }
#line 1917 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 1923 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 364 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_ARIM_DIVISAO, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1929 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 365 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_ARIM_MULTIPLICACAO, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1935 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 366 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_ARIM_SUBTRACAO, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1941 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 367 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_ARIM_SOMA, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1947 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 368 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_ARIM_INVERSAO, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));}
#line 1953 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_NEGACAO, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));}
#line 1959 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_L, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1965 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 371 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_G, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1971 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 372 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_LE, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1977 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 373 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_GE, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1983 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 374 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_IGUAL, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1989 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 375 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_COMP_DIF, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 1995 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 376 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_E, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 2001 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 377 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = createNode(AST_LOGICO_OU, NULL);appendChildNode((yyval.syntaxTree),(yyvsp[-2].syntaxTree));appendChildNode((yyval.syntaxTree),(yyvsp[0].syntaxTree));typeInference((yyvsp[-2].syntaxTree),(yyvsp[0].syntaxTree));}
#line 2007 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[-1].syntaxTree);}
#line 2013 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.syntaxTree) = (yyvsp[0].syntaxTree);}
#line 2019 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
    break;


#line 2023 "/home/mandiow/Área de Trabalho/MonT/build/parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 382 "parser.y" /* yacc.c:1906  */

