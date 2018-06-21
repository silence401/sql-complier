/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sql.y" /* yacc.c:339  */

    #include "main.h"
    char database[64]={0};
    char rootdir[1024]={0};
void yyerror(const char *msg)
{
    printf("error %s\n",msg);
    printf(">>");
    yyparse();
}
int yywrap(){
    return 1;
}
int main()
{
    printf("***********************\n");
    printf("  Welcome to MYSQL!  \n");
    printf("***********************\n\n");
    getcwd(rootdir, sizeof(rootdir));
    strcat(rootdir, "/sql");
    printf(">>");
    yyparse();	
	return 0;
}

#line 92 "y.tab.c" /* yacc.c:339  */

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
    CREATE = 258,
    DROP = 259,
    DATABASES = 260,
    TABLE = 261,
    TABLES = 262,
    USE = 263,
    DATABASE = 264,
    SHOW = 265,
    DELETE = 266,
    INSERT = 267,
    INTO = 268,
    VALUES = 269,
    SELECT = 270,
    FROM = 271,
    WHERE = 272,
    UPDATE = 273,
    SET = 274,
    ID = 275,
    NUMBER = 276,
    INT = 277,
    CHAR = 278,
    OR = 279,
    AND = 280
  };
#endif
/* Tokens.  */
#define CREATE 258
#define DROP 259
#define DATABASES 260
#define TABLE 261
#define TABLES 262
#define USE 263
#define DATABASE 264
#define SHOW 265
#define DELETE 266
#define INSERT 267
#define INTO 268
#define VALUES 269
#define SELECT 270
#define FROM 271
#define WHERE 272
#define UPDATE 273
#define SET 274
#define ID 275
#define NUMBER 276
#define INT 277
#define CHAR 278
#define OR 279
#define AND 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "sql.y" /* yacc.c:355  */

    char * yych;
    struct TableItems  *item_type;
    struct Table       *table_type;
    struct Condition   *con_type;

#line 186 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 203 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   280

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,     2,     2,     2,
      27,    28,    30,     2,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      33,    32,    31,     2,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    42,    44,    44,    44,    44,    44,    44,
      44,    44,    46,    47,    56,    63,    71,    79,    86,    87,
      88,    93,    94,    96,   100,   104,   110,   117,   124,   130,
     134,   138,   142,   146,   153,   160,   165,   169,   177,   185,
     193,   201,   209,   217,   222,   228,   232,   238,   244
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CREATE", "DROP", "DATABASES", "TABLE",
  "TABLES", "USE", "DATABASE", "SHOW", "DELETE", "INSERT", "INTO",
  "VALUES", "SELECT", "FROM", "WHERE", "UPDATE", "SET", "ID", "NUMBER",
  "INT", "CHAR", "OR", "AND", "';'", "'('", "')'", "','", "'*'", "'>'",
  "'='", "'<'", "'!'", "$accept", "start", "statement", "createfunc",
  "items", "item", "showfunc", "usedatabase", "dropfunc", "insertfunc",
  "values", "value", "selectfunc", "conditions", "condition",
  "updataefunc", "upvalues", "upvalue", "deletefunc", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    59,    40,    41,    44,
      42,    62,    61,    60,    33
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      22,    37,    43,    -2,     1,    28,    18,    15,     8,     9,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,    19,
      30,    33,    68,    65,    67,    69,    72,    74,   -67,   -67,
      32,   -14,   -67,    77,   -67,   -67,    70,    73,    75,    76,
     -67,   -67,   -67,    81,   -11,    80,    83,    41,    84,    85,
     -67,   -67,   -67,   -16,    79,    41,    21,    25,   -67,    35,
      12,   -67,    52,    48,   -67,    23,   -16,    34,   -67,    41,
      50,   -16,   -67,   -16,   -67,    60,   -16,    84,   -67,    82,
      86,    85,    87,    62,    89,    88,    90,   -16,   -16,   -67,
      56,    93,    40,    44,   -67,   -67,    47,   -67,    92,   -67,
     -67,   -67,   -67,   -67,   -67,    66,   -67,   -67,   -67,    91,
      94,   -67,   -67,   -67,    95,   -67,   -67,   -67,    41,   -67,
      61,    96,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     7,     6,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,     0,    26,     0,     1,     2,     0,     0,     0,     0,
      20,    18,    19,     0,     0,     0,     0,     0,     0,     0,
      12,    22,    21,     0,     0,     0,     0,     0,    25,     0,
       0,    45,     0,     0,    15,     0,     0,     0,    35,     0,
       0,     0,    29,     0,    30,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,    47,    46,     0,    44,     0,    13,
      14,    37,    41,    38,    39,     0,    36,    34,    33,     0,
       0,    31,    32,    43,     0,    42,    40,    23,     0,    16,
       0,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   102,   -67,   -67,    38,   -67,   -67,   -67,   -67,
     -55,    78,   -67,   -66,   -65,   -67,   -67,    39,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    63,    64,    12,    13,    14,    15,
      31,    32,    16,    67,    68,    17,    60,    61,    18
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    86,    46,    54,    65,    92,    24,    93,    25,    34,
      96,    66,     1,     2,    90,    47,    55,     3,    23,     4,
       5,     6,   107,   108,     7,     1,     2,     8,    33,    76,
       3,    27,     4,     5,     6,    28,    29,     7,    71,    36,
       8,    77,    73,    19,    26,    30,    20,    72,    45,    21,
      37,    74,    22,    38,    82,    83,    84,    85,    87,    88,
      89,    28,    29,   120,    87,    88,   111,    75,    87,    88,
     112,    87,    88,   113,    78,    79,    80,    81,    91,    47,
      94,    95,   102,   103,   109,    47,   115,   116,    39,   121,
      47,    40,    43,    41,    44,    42,    48,    49,    53,    50,
      56,    51,    52,    57,    59,    62,    69,   110,   101,    98,
     104,    35,    99,   114,     0,     0,    97,   117,   106,   100,
     105,   118,   122,   119,     0,    58
};

static const yytype_int8 yycheck[] =
{
      55,    66,    16,    14,    20,    71,     5,    73,     7,     0,
      76,    27,     3,     4,    69,    29,    27,     8,    20,    10,
      11,    12,    87,    88,    15,     3,     4,    18,    20,    17,
       8,    13,    10,    11,    12,    20,    21,    15,    17,    20,
      18,    29,    17,     6,    16,    30,     9,    26,    16,     6,
      20,    26,     9,    20,    31,    32,    33,    34,    24,    25,
      26,    20,    21,   118,    24,    25,    26,    32,    24,    25,
      26,    24,    25,    26,    22,    23,    28,    29,    28,    29,
      20,    21,    20,    21,    28,    29,    20,    21,    20,    28,
      29,    26,    20,    26,    20,    26,    19,    27,    17,    26,
      20,    26,    26,    20,    20,    20,    27,    14,    21,    27,
      21,     9,    26,    21,    -1,    -1,    77,    26,    28,    81,
      32,    27,    26,    28,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,    10,    11,    12,    15,    18,    36,
      37,    38,    41,    42,    43,    44,    47,    50,    53,     6,
       9,     6,     9,    20,     5,     7,    16,    13,    20,    21,
      30,    45,    46,    20,     0,    37,    20,    20,    20,    20,
      26,    26,    26,    20,    20,    16,    16,    29,    19,    27,
      26,    26,    26,    17,    14,    27,    20,    20,    46,    20,
      51,    52,    20,    39,    40,    20,    27,    48,    49,    27,
      45,    17,    26,    17,    26,    32,    17,    29,    22,    23,
      28,    29,    31,    32,    33,    34,    49,    24,    25,    26,
      45,    28,    48,    48,    20,    21,    48,    52,    27,    26,
      40,    21,    20,    21,    21,    32,    28,    49,    49,    28,
      14,    26,    26,    26,    21,    20,    21,    26,    27,    28,
      45,    28,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    37,    37,
      37,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    43,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    50,    51,    51,    52,    52,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     7,     3,     1,     5,     2,     3,     3,
       3,     4,     4,     8,    11,     3,     1,     1,     1,     5,
       5,     7,     7,     3,     3,     1,     3,     3,     3,     3,
       4,     3,     4,     7,     3,     1,     3,     3,     6
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
        case 12:
#line 46 "sql.y" /* yacc.c:1646  */
    {strcpy(database,(yyvsp[-1].yych)); CreateDB();}
#line 1354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 48 "sql.y" /* yacc.c:1646  */
    {
                (yyval.table_type)=(struct Table *)malloc(sizeof(struct Table));
                (yyval.table_type)->table_name=(yyvsp[-4].yych);
                (yyval.table_type)->items=(yyvsp[-2].item_type);
                CreateTable((yyval.table_type));
                
            }
#line 1366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "sql.y" /* yacc.c:1646  */
    {
                (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                (yyval.item_type)->next_item =(yyvsp[-2].item_type);
                (yyval.item_type)->content=(yyvsp[0].item_type)->content;
                (yyval.item_type)->type=(yyvsp[0].item_type)->type;
            }
#line 1377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 64 "sql.y" /* yacc.c:1646  */
    {
                 (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                 (yyval.item_type)->next_item=NULL;
                 (yyval.item_type)->type=(yyvsp[0].item_type)->type;
                 (yyval.item_type)->content=(yyvsp[0].item_type)->content;
            }
#line 1388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 72 "sql.y" /* yacc.c:1646  */
    {
                
                (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                (yyval.item_type)->content=(yyvsp[-4].yych);
                (yyval.item_type)->type=(yyvsp[-3].yych);

            }
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "sql.y" /* yacc.c:1646  */
    {
                (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                (yyval.item_type)->content=(yyvsp[-1].yych);
                (yyval.item_type)->type=(yyvsp[0].yych);
            }
#line 1410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 86 "sql.y" /* yacc.c:1646  */
    {ShowDB();}
#line 1416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 87 "sql.y" /* yacc.c:1646  */
    {ShowTables();}
#line 1422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 89 "sql.y" /* yacc.c:1646  */
    {
                  strcpy(database,(yyvsp[-1].yych));
                  UseDB();
              }
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 93 "sql.y" /* yacc.c:1646  */
    {strcpy(database,(yyvsp[-1].yych)); DropDB();}
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 94 "sql.y" /* yacc.c:1646  */
    {DropTable((yyvsp[-1].yych));}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 97 "sql.y" /* yacc.c:1646  */
    {
                  InsertValue((yyvsp[-5].yych),(yyvsp[-2].item_type));
              }
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 101 "sql.y" /* yacc.c:1646  */
    {
                 InsertByRow((yyvsp[-8].yych),(yyvsp[-6].item_type),(yyvsp[-2].item_type));
             }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 105 "sql.y" /* yacc.c:1646  */
    {
                  (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                  (yyval.item_type)->content=(yyvsp[0].item_type)->content;
                  (yyval.item_type)->next_item=(yyvsp[-2].item_type);
              }
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 111 "sql.y" /* yacc.c:1646  */
    {
                    (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                    (yyval.item_type)->content=(yyvsp[0].item_type)->content;
                    (yyval.item_type)->next_item=NULL;
              }
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 118 "sql.y" /* yacc.c:1646  */
    {
                        (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                        (yyval.item_type)->content=(yyvsp[0].yych);
                        (yyval.item_type)->next_item=NULL;

                     }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 125 "sql.y" /* yacc.c:1646  */
    {
                          (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                         (yyval.item_type)->content=(yyvsp[0].yych);
                         (yyval.item_type)->next_item=NULL;
                     }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 131 "sql.y" /* yacc.c:1646  */
    {
                     SelectAll((yyvsp[-1].yych));
                }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 135 "sql.y" /* yacc.c:1646  */
    {
                SelectByCol((yyvsp[-1].yych),(yyvsp[-3].item_type));
            }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 139 "sql.y" /* yacc.c:1646  */
    {
                SelectWhere2((yyvsp[-3].yych),(yyvsp[-1].con_type));
            }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 143 "sql.y" /* yacc.c:1646  */
    {
                SelectWhere1((yyvsp[-3].yych),(yyvsp[-1].con_type),(yyvsp[-5].item_type));
            }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 147 "sql.y" /* yacc.c:1646  */
    {
                              (yyval.con_type)=(yyvsp[0].con_type);
                              (yyval.con_type)->next_con=(yyvsp[-2].con_type);
                              (yyval.con_type)->op='a';
                              
                        }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 154 "sql.y" /* yacc.c:1646  */
    {

                              (yyval.con_type)=(yyvsp[0].con_type);
                              (yyval.con_type)->next_con=(yyvsp[-2].con_type);
                              (yyval.con_type)->op='o';
                         }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 161 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(yyvsp[0].con_type);
                        }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 166 "sql.y" /* yacc.c:1646  */
    {
                             (yyval.con_type)=(yyvsp[-1].con_type);
                         }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 170 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(struct Condition*)malloc(sizeof(struct Condition));
                            (yyval.con_type)->left=(yyvsp[-2].yych);
                            (yyval.con_type)->right=(yyvsp[0].yych);
                            (yyval.con_type)->cmp='>';
                            (yyval.con_type)->next_con=NULL;
                        }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 178 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(struct Condition*)malloc(sizeof(struct Condition));
                            (yyval.con_type)->left=(yyvsp[-2].yych);
                            (yyval.con_type)->cmp='=';
                            (yyval.con_type)->right=(yyvsp[0].yych);
                            (yyval.con_type)->next_con=NULL;
                        }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(struct Condition*)malloc(sizeof(struct Condition));
                            (yyval.con_type)->left=(yyvsp[-2].yych);
                            (yyval.con_type)->cmp='<';
                            (yyval.con_type)->right=(yyvsp[0].yych);
                            (yyval.con_type)->next_con=NULL;
                        }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 194 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(struct Condition*)malloc(sizeof(struct Condition));
                            (yyval.con_type)->left=(yyvsp[-3].yych);
                            (yyval.con_type)->cmp='!';
                            (yyval.con_type)->right=(yyvsp[0].yych);
                            (yyval.con_type)->next_con=NULL;
                        }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 202 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(struct Condition*)malloc(sizeof(struct Condition));
                            (yyval.con_type)->left=(yyvsp[-2].yych);
                            (yyval.con_type)->cmp='=';
                            (yyval.con_type)->right=(yyvsp[0].yych);
                            (yyval.con_type)->next_con=NULL;
                        }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 210 "sql.y" /* yacc.c:1646  */
    {
                            (yyval.con_type)=(struct Condition*)malloc(sizeof(struct Condition));
                            (yyval.con_type)->left=(yyvsp[-3].yych);
                            (yyval.con_type)->cmp='!';
                            (yyval.con_type)->right=(yyvsp[0].yych);
                            (yyval.con_type)->next_con=NULL;
                        }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 218 "sql.y" /* yacc.c:1646  */
    {
                UpdateTable((yyvsp[-5].yych),(yyvsp[-3].item_type),(yyvsp[-1].con_type));

            }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 223 "sql.y" /* yacc.c:1646  */
    {
                          (yyval.item_type)=(yyvsp[0].item_type);
                          (yyval.item_type)->next_item=(yyvsp[-2].item_type);

                      }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 229 "sql.y" /* yacc.c:1646  */
    {
                          (yyval.item_type)=(yyvsp[0].item_type);
                      }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 233 "sql.y" /* yacc.c:1646  */
    {  
                        (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems)); 
                        (yyval.item_type)->content=(yyvsp[0].yych);
                        (yyval.item_type)->type=(yyvsp[-2].yych);
                     }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 239 "sql.y" /* yacc.c:1646  */
    {
                         (yyval.item_type)=(struct TableItems*)malloc(sizeof(struct TableItems));
                         (yyval.item_type)->content=(yyvsp[0].yych);
                         (yyval.item_type)->type=(yyvsp[-2].yych);
                     }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 245 "sql.y" /* yacc.c:1646  */
    {
                 Delete((yyvsp[-3].yych),(yyvsp[-1].con_type));
            }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1701 "y.tab.c" /* yacc.c:1646  */
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
