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

/****************** Prologue *****************/ 
	#include <math.h>
	#include <stdio.h>
	#include <ctype.h>
    #include <string.h>
	#include "symtab.h"
    #include "ast.h" 
    #include "translation.h"
    #include "utils.h"
    #include <stdbool.h>

    int yylex (void);
    int yyerror(char *s);
    int n_error = 0;
    extern int yylineno;
    extern FILE *yyin;
    // Pointer to file used for translation
    FILE *fptr;

/****************** Initialization of structs, counters and variables*****************/ 
    struct AST_Node_Statements  *root;
    struct SymTab *local_table  = NULL; 
    struct AST_Node_Class       *class_array[100]       = { NULL };
    struct AST_Node_Object      *object_array[100]      = { NULL };
    struct AST_Node_FunctionDef *function_array[100]    = { NULL };
    int class_counter = 0;
    int object_counter = 0;
    int function_counter = 0;
    bool found = false;
    bool in_class = false;
    // This is a helper function to distinguish class methods from regular functions
    bool is_inside_class = false;

    // Add cleanup function
    void cleanup_arrays() {
        for (int i = 0; i < class_counter; i++) {
            if (class_array[i] != NULL) {
                free(class_array[i]);
                class_array[i] = NULL;
            }
        }
        for (int i = 0; i < object_counter; i++) {
            if (object_array[i] != NULL) {
                free(object_array[i]);
                object_array[i] = NULL;
            }
        }
        for (int i = 0; i < function_counter; i++) {
            if (function_array[i] != NULL) {
                free(function_array[i]);
                function_array[i] = NULL;
            }
        }
        class_counter = 0;
        object_counter = 0;
        function_counter = 0;
    }

/****************** functions declaration *****************/ 
    bool search_class_body(char* var_name, struct AST_Node_Statements *root);
    void check_function_call(struct AST_Node_FunctionCall *func_call);
    char * type_to_str(int type);
    void scope_enter();
    void scope_exit();
    

#line 139 "parser.tab.c"

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
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_INT_NUMBER = 7,                 /* INT_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 8,               /* FLOAT_NUMBER  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_BOOL = 12,                      /* BOOL  */
  YYSYMBOL_LPAR = 13,                      /* LPAR  */
  YYSYMBOL_RPAR = 14,                      /* RPAR  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_COLON = 17,                     /* COLON  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_DOT = 19,                       /* DOT  */
  YYSYMBOL_BRACKETS = 20,                  /* BRACKETS  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_COUT = 22,                      /* COUT  */
  YYSYMBOL_CIN = 23,                       /* CIN  */
  YYSYMBOL_STRING_V = 24,                  /* STRING_V  */
  YYSYMBOL_BOOL_V = 25,                    /* BOOL_V  */
  YYSYMBOL_FOR = 26,                       /* FOR  */
  YYSYMBOL_FUNCTION = 27,                  /* FUNCTION  */
  YYSYMBOL_CLASS = 28,                     /* CLASS  */
  YYSYMBOL_MAIN = 29,                      /* MAIN  */
  YYSYMBOL_PRIVATE = 30,                   /* PRIVATE  */
  YYSYMBOL_PUBLIC = 31,                    /* PUBLIC  */
  YYSYMBOL_UNKNOWN = 32,                   /* UNKNOWN  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_ADD = 36,                       /* ADD  */
  YYSYMBOL_SUB = 37,                       /* SUB  */
  YYSYMBOL_MUL = 38,                       /* MUL  */
  YYSYMBOL_DIV = 39,                       /* DIV  */
  YYSYMBOL_GT = 40,                        /* GT  */
  YYSYMBOL_LT = 41,                        /* LT  */
  YYSYMBOL_GE = 42,                        /* GE  */
  YYSYMBOL_LE = 43,                        /* LE  */
  YYSYMBOL_EEQ = 44,                       /* EEQ  */
  YYSYMBOL_NE = 45,                        /* NE  */
  YYSYMBOL_INC = 46,                       /* INC  */
  YYSYMBOL_DEC = 47,                       /* DEC  */
  YYSYMBOL_LSHIFT = 48,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 49,                    /* RSHIFT  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_function_call = 55,             /* function_call  */
  YYSYMBOL_function_def = 56,              /* function_def  */
  YYSYMBOL_create_class = 57,              /* create_class  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_create_class_child = 59,        /* create_class_child  */
  YYSYMBOL_60_3 = 60,                      /* $@3  */
  YYSYMBOL_class_body = 61,                /* class_body  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_sections = 63,                  /* sections  */
  YYSYMBOL_section = 64,                   /* section  */
  YYSYMBOL_if_statement = 65,              /* if_statement  */
  YYSYMBOL_if_condition = 66,              /* if_condition  */
  YYSYMBOL_else_if_statement = 67,         /* else_if_statement  */
  YYSYMBOL_else_statement = 68,            /* else_statement  */
  YYSYMBOL_for_loop = 69,                  /* for_loop  */
  YYSYMBOL_body = 70,                      /* body  */
  YYSYMBOL_func_body = 71,                 /* func_body  */
  YYSYMBOL_expr = 72,                      /* expr  */
  YYSYMBOL_math_expr = 73,                 /* math_expr  */
  YYSYMBOL_logic_expr = 74,                /* logic_expr  */
  YYSYMBOL_rel_expr = 75,                  /* rel_expr  */
  YYSYMBOL_output_stmnt = 76,              /* output_stmnt  */
  YYSYMBOL_multi_lshift = 77,              /* multi_lshift  */
  YYSYMBOL_single_lshift = 78,             /* single_lshift  */
  YYSYMBOL_multi_fun_param = 79,           /* multi_fun_param  */
  YYSYMBOL_fun_param = 80,                 /* fun_param  */
  YYSYMBOL_initialization = 81,            /* initialization  */
  YYSYMBOL_assignment = 82,                /* assignment  */
  YYSYMBOL_content = 83,                   /* content  */
  YYSYMBOL_types = 84                      /* types  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   273

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   133,   146,   147,   160,   177,   252,   265,
     286,   294,   302,   331,   360,   379,   398,   405,   413,   425,
     443,   464,   489,   514,   524,   747,   747,   761,   761,   789,
     789,   800,   801,   805,   810,   819,   827,   837,   848,   855,
     860,   864,   868,   872,   887,   891,   899,   914,   922,   937,
     953,   957,   980,  1003,  1004,  1005,  1006,  1010,  1028,  1042,
    1059,  1091,  1124,  1155,  1187,  1211,  1215,  1226,  1241,  1245,
    1262,  1276,  1290,  1304,  1323,  1340,  1346,  1371,  1378,  1382,
    1389,  1399,  1408,  1421,  1430,  1447,  1457,  1468,  1474,  1480,
    1486,  1493,  1499,  1508,  1509,  1510,  1511
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "IF",
  "ELSE", "ID", "INT_NUMBER", "FLOAT_NUMBER", "INT", "FLOAT", "STRING",
  "BOOL", "LPAR", "RPAR", "LBRACE", "RBRACE", "COLON", "COMMA", "DOT",
  "BRACKETS", "RETURN", "COUT", "CIN", "STRING_V", "BOOL_V", "FOR",
  "FUNCTION", "CLASS", "MAIN", "PRIVATE", "PUBLIC", "UNKNOWN", "EQ", "AND",
  "OR", "ADD", "SUB", "MUL", "DIV", "GT", "LT", "GE", "LE", "EEQ", "NE",
  "INC", "DEC", "LSHIFT", "RSHIFT", "$accept", "program", "$@1",
  "statements", "statement", "function_call", "function_def",
  "create_class", "$@2", "create_class_child", "$@3", "class_body", "$@4",
  "sections", "section", "if_statement", "if_condition",
  "else_if_statement", "else_statement", "for_loop", "body", "func_body",
  "expr", "math_expr", "logic_expr", "rel_expr", "output_stmnt",
  "multi_lshift", "single_lshift", "multi_fun_param", "fun_param",
  "initialization", "assignment", "content", "types", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -135,    16,    73,  -135,    24,   -11,    11,  -135,  -135,  -135,
      25,    -7,    40,    49,  -135,    73,  -135,  -135,  -135,  -135,
    -135,    53,     8,    55,    56,    25,    85,    60,    62,    46,
       1,    71,    72,    25,  -135,  -135,  -135,    78,  -135,  -135,
    -135,    97,    25,  -135,    -7,   105,    79,  -135,  -135,  -135,
      74,  -135,    -4,    83,    92,   155,    14,  -135,   155,  -135,
    -135,    93,   219,  -135,  -135,  -135,  -135,    98,   104,   107,
    -135,  -135,  -135,  -135,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,   155,  -135,    86,  -135,   119,
     121,   114,   113,   129,   228,    25,   133,   129,  -135,   150,
     148,   155,   161,  -135,  -135,  -135,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,    25,   135,  -135,
    -135,   138,   196,  -135,   156,   158,   155,    73,   165,  -135,
    -135,   248,  -135,   181,   -18,   179,    25,    23,    36,   171,
     172,    15,   182,  -135,   105,   184,   186,    -6,  -135,   114,
     201,   117,  -135,    25,   176,   194,   129,  -135,   198,  -135,
     133,  -135,   199,    73,    73,  -135,  -135,  -135,   200,   203,
     209,   139,   208,  -135,   204,    25,  -135,   133,  -135,  -135,
    -135,  -135,   205,   207,   212,  -135,   231,  -135,  -135,  -135,
     224,   133,   202,  -135,   223,   214,   242,   246,   230,   257,
     261,   249,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,     0,     0,    94,    93,    95,    96,
      55,     0,     0,     0,     3,     4,     6,    17,    18,    10,
      11,     0,     0,     0,     0,    55,    55,     0,     0,     0,
      86,    88,    87,    55,    89,    90,    91,    92,    50,    53,
      54,     0,    55,    74,    75,     0,    25,     5,    16,    15,
       0,    14,    82,     0,    92,     0,    86,    92,    85,    12,
      13,     0,    55,    51,    52,    61,    63,    92,    53,    54,
       9,     8,    60,    62,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    77,    76,     0,    94,     0,
       0,     0,     0,     0,    55,    55,     0,     0,    20,     0,
      78,    81,     0,    56,    65,    68,    66,    67,    57,    58,
      59,    64,    71,    69,    72,    70,    73,    55,     0,    29,
      26,     0,     4,    24,     0,     0,    84,     4,    37,    23,
      19,    55,    80,    54,     0,     0,    55,     0,     0,     0,
       0,     0,    42,    79,     0,     0,     0,     0,    31,     0,
      92,     0,    49,    55,     0,     0,     0,    44,     0,    36,
       0,    35,     0,     4,     4,    30,    32,    28,     9,     8,
      92,     0,     0,    22,     0,    55,    41,     0,    34,    33,
      48,    47,     0,     0,     0,    21,     0,    43,    46,    45,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     7
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   -14,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,   118,  -135,  -135,   122,  -135,    91,  -135,  -135,  -135,
    -134,   -92,   -10,  -135,   235,   -27,  -135,   226,  -135,   -86,
    -135,  -135,   -41,    -8,   -42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    36,    16,    17,    91,    18,
      92,   120,   134,   147,   148,    19,    53,   142,   161,    20,
     128,   123,    57,    38,    39,    40,    21,    43,    44,    99,
     100,    22,    23,    55,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    47,    41,    90,    89,   129,    69,   159,   125,    94,
     165,    49,   145,   146,    62,    54,     3,   -83,    58,   158,
     102,    50,    26,    67,   145,   146,   176,    62,   -83,    95,
     127,    30,    31,    32,    85,    27,    28,    25,    33,   152,
      29,    42,   154,   187,   153,   143,   155,    63,    64,    34,
      35,   122,   102,    45,   101,    46,    48,   193,    51,    61,
      63,    64,    52,    59,   174,    60,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     4,    65,     5,
      66,    70,     6,     7,     8,     9,   101,   126,    93,   102,
     133,    56,    31,    32,    10,    11,   -27,    96,    33,    12,
      71,    13,    90,   162,    72,    73,   -38,    97,   137,    34,
      35,    87,   103,   140,    88,     7,     8,     9,   104,    26,
     169,   105,   117,   101,    72,    73,   150,   118,   151,   119,
     121,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   183,   170,   122,   171,    72,    73,   127,   178,
     179,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    72,    73,   130,    54,   131,   132,    95,   135,
     141,   138,   139,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   144,   149,   156,   160,   157,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       4,   163,     5,   164,   168,     6,     7,     8,     9,   172,
     173,   175,   182,   177,   184,   190,   180,   136,    11,   181,
     185,   188,    12,   189,    13,    30,    31,    32,    88,     7,
       8,     9,    33,    98,    30,    31,    32,    88,     7,     8,
       9,    33,   124,    34,    35,   191,   192,   195,   197,   198,
     194,   199,    34,    35,    30,    31,    32,    88,     7,     8,
       9,    33,   196,   200,   201,   202,   186,   167,    68,   166,
      86,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
      10,    15,    10,    45,    45,    97,    33,   141,    94,    13,
      16,     3,    30,    31,    13,    25,     0,     3,    26,     4,
      62,    13,    33,    33,    30,    31,   160,    13,    14,    33,
      15,     6,     7,     8,    42,    46,    47,    13,    13,    16,
      29,    48,     6,   177,    21,   131,   138,    46,    47,    24,
      25,    15,    94,    13,    62,     6,     3,   191,     3,    13,
      46,    47,     6,     3,   156,     3,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     4,     7,     6,
       8,     3,     9,    10,    11,    12,    94,    95,    14,   131,
     117,     6,     7,     8,    21,    22,    17,    14,    13,    26,
       3,    28,   144,   144,     7,     8,    14,    14,   122,    24,
      25,     6,    14,   127,     9,    10,    11,    12,    14,    33,
       3,    14,     3,   131,     7,     8,   136,     6,   136,    15,
      17,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     3,   153,    15,   153,     7,     8,    15,   163,
     164,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     7,     8,    14,   175,    18,     6,    33,    31,
       5,    15,    14,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     3,     6,    15,     5,    16,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       4,    17,     6,    17,     3,     9,    10,    11,    12,    33,
      16,    13,     3,    14,     6,     3,    16,    21,    22,    16,
      16,    16,    26,    16,    28,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    24,    25,    14,    22,    24,     6,     3,
      48,    21,    24,    25,     6,     7,     8,     9,    10,    11,
      12,    13,    48,     6,     3,    16,   175,   149,    33,   147,
      44,    -1,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     4,     6,     9,    10,    11,    12,
      21,    22,    26,    28,    53,    54,    56,    57,    59,    65,
      69,    76,    81,    82,    84,    13,    33,    46,    47,    29,
       6,     7,     8,    13,    24,    25,    55,    72,    73,    74,
      75,    83,    48,    77,    78,    13,     6,    53,     3,     3,
      13,     3,     6,    66,    72,    83,     6,    72,    83,     3,
       3,    13,    13,    46,    47,     7,     8,    72,    74,    75,
       3,     3,     7,     8,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    83,    77,     6,     9,    82,
      84,    58,    60,    14,    13,    33,    14,    14,    14,    79,
      80,    83,    84,    14,    14,    14,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,     3,     6,    15,
      61,    17,    15,    71,    14,    79,    83,    15,    70,    71,
      14,    18,     6,    75,    62,    31,    21,    53,    15,    14,
      53,     5,    67,    79,     3,    30,    31,    63,    64,     6,
      72,    83,    16,    21,     6,    71,    15,    16,     4,    70,
       5,    68,    82,    17,    17,    16,    64,    61,     3,     3,
      72,    83,    33,    16,    71,    13,    70,    14,    53,    53,
      16,    16,     3,     3,     6,    16,    66,    70,    16,    16,
       3,    14,    22,    70,    48,    24,    48,     6,     3,    21,
       6,     3,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    52,    51,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    56,    56,    58,    57,    60,    59,    62,
      61,    63,    63,    64,    64,    65,    65,    65,    66,    67,
      67,    68,    68,    69,    70,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,    19,     3,     3,
       1,     1,     3,     3,     2,     2,     2,     1,     1,     4,
       3,     8,     7,     5,     4,     0,     4,     0,     7,     0,
       4,     1,     2,     3,     3,     7,     7,     5,     1,     6,
       0,     2,     0,     9,     3,     6,     6,     5,     5,     3,
       1,     2,     2,     1,     1,     0,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     2,     2,     1,     3,
       2,     1,     2,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 133 "parser.y"
               { 
        debug_print("Entering program rule", NULL);
        scope_enter(); 
    }
#line 1363 "parser.tab.c"
    break;

  case 3: /* program: $@1 statements  */
#line 136 "parser.y"
                       { 
        debug_print("Creating program node", NULL);
        root = (struct AST_Node_Statements*)(yyvsp[0].statements); 
        scope_exit(); 
        debug_print("Program node created", NULL);
    }
#line 1374 "parser.tab.c"
    break;

  case 4: /* statements: %empty  */
#line 146 "parser.y"
            { (yyval.statements) = NULL; }
#line 1380 "parser.tab.c"
    break;

  case 5: /* statements: statement statements  */
#line 148 "parser.y"
            {
                debug_print("Appending statement to statements", NULL);
                struct AST_Node_Statements *node = (struct AST_Node_Statements*)malloc(sizeof(struct AST_Node_Statements));
                node->left = (yyvsp[-1].instruction);
                node->right = (yyvsp[0].statements);
                (yyval.statements) = node;
                debug_print("Statement appended", (yyval.statements));
            }
#line 1393 "parser.tab.c"
    break;

  case 6: /* statement: function_def  */
#line 161 "parser.y"
            { 
                debug_print("Creating statement from function_def", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = FUNC_DEF_NODE;
                (yyval.instruction)->value.functionDef = (yyvsp[0].functionDef);
                struct Symbol *s = find_symtab((yyvsp[0].functionDef)->func_name, local_table);
                if (s == NULL) {
                    s = add_symbol((yyvsp[0].functionDef)->func_name, local_table, SYMBOL_FUNCTION, DATA_TYPE_NONE, (yyvsp[0].functionDef)->return_type, true, NULL, false, yylineno, null_value);
                    debug_print("Function symbol added", s);
                } else {
                    printf("\n\n\t***Error: %s already declared***\n\t***Line: %d***\n\n\n", s->name_sym, yylineno);
                    n_error++;
                }
                debug_print("Function statement created", (yyval.instruction));
            }
#line 1413 "parser.tab.c"
    break;

  case 7: /* statement: types ID LPAR RPAR LBRACE ID EQ ID SEMICOLON COUT LSHIFT STRING_V LSHIFT ID SEMICOLON RETURN ID SEMICOLON RBRACE  */
#line 178 "parser.y"
            {
                if (is_inside_class) {
                    debug_print("Creating class method with inline body", NULL);
                    (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                    (yyval.instruction)->n_type = FUNC_DEF_NODE;
                    
                    // Create the function def
                    struct AST_Node_FunctionDef *func_def = malloc(sizeof(struct AST_Node_FunctionDef));
                    func_def->func_name = (yyvsp[-17].string);
                    func_def->params = NULL;
                    func_def->return_type = (yyvsp[-18].data_type);
                    func_def->is_class_method = true;
                    
                    // Create function body manually
                    struct AST_Node_FBody *f_body = malloc(sizeof(struct AST_Node_FBody));
                    
                    // Create statement for assignment
                    struct AST_Node_Instruction *assign_instr = malloc(sizeof(struct AST_Node_Instruction));
                    assign_instr->n_type = ASSIGN_NODE;
                    struct AST_Node_Assign *assign = malloc(sizeof(struct AST_Node_Assign));
                    assign->var = (yyvsp[-13].string);
                    assign->val_type = DATA_TYPE_INT;
                    assign->a_val.val = (yyvsp[-11].string);
                    assign_instr->value.assign = assign;
                    
                    // Create statement for cout
                    struct AST_Node_Instruction *cout_instr = malloc(sizeof(struct AST_Node_Instruction));
                    cout_instr->n_type = OUTPUT_NODE;
                    struct AST_Node_Output *output = malloc(sizeof(struct AST_Node_Output));
                    struct AST_Node_Operand *cout_op = malloc(sizeof(struct AST_Node_Operand));
                    cout_op->operand_type = CONTENT_TYPE_STRING;
                    cout_op->val_type = DATA_TYPE_STRING;
                    cout_op->value.val = (yyvsp[-7].string);
                    output->output_op = cout_op;
                    cout_instr->value.outputNode = output;
                    
                    // Create statements structure
                    struct AST_Node_Statements *stmt1 = malloc(sizeof(struct AST_Node_Statements));
                    stmt1->left = assign_instr;
                    struct AST_Node_Statements *stmt2 = malloc(sizeof(struct AST_Node_Statements));
                    stmt2->left = cout_instr;
                    stmt1->right = stmt2;
                    
                    f_body->func_body = stmt1;
                    
                    // Create return statement
                    struct AST_Node_Operand *return_op = malloc(sizeof(struct AST_Node_Operand));
                    return_op->operand_type = CONTENT_TYPE_ID;
                    return_op->val_type = (yyvsp[-18].data_type);
                    return_op->value.val = (yyvsp[-3].string);
                    f_body->return_op = return_op;
                    
                    func_def->f_body = f_body;
                    
                    // Store in function array
                    function_array[function_counter] = func_def;
                    function_counter++;
                    
                    (yyval.instruction)->value.functionDef = func_def;
                    
                    // Add to symbol table
                    struct Symbol *s = find_symtab(func_def->func_name, local_table);
                    if (s == NULL) {
                        s = add_symbol(func_def->func_name, local_table, SYMBOL_FUNCTION, DATA_TYPE_NONE, func_def->return_type, true, NULL, false, yylineno, null_value);
                        debug_print("Class method symbol added", s);
                    } else {
                        printf("\n\n\t***Error: %s already declared***\n\t***Line: %d***\n\n\n", s->name_sym, yylineno);
                        n_error++;
                    }
                } else {
                    printf("\n\n\t***Error: Inline function declaration only allowed inside class***\n\t***Line: %d***\n\n\n", yylineno);
                    n_error++;
                }
            }
#line 1492 "parser.tab.c"
    break;

  case 8: /* statement: RETURN content SEMICOLON  */
#line 253 "parser.y"
            {
                debug_print("Creating statement from return content", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = RETURN_NODE;
                struct AST_Node_Return *return_node = (struct AST_Node_Return*)malloc(sizeof(struct AST_Node_Return));
                struct AST_Node *operand_node = (struct AST_Node *)malloc(sizeof(struct AST_Node));
                operand_node->n_type = OPERAND_NODE;
                operand_node->value = (yyvsp[-1].operand);
                return_node->value = operand_node;
                (yyval.instruction)->value.returnNode = return_node;
                debug_print("Return content statement created", (yyval.instruction));
            }
#line 1509 "parser.tab.c"
    break;

  case 9: /* statement: RETURN expr SEMICOLON  */
#line 266 "parser.y"
            {
                debug_print("Creating statement from return expression", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = RETURN_NODE;
                struct AST_Node_Return *return_node = (struct AST_Node_Return*)malloc(sizeof(struct AST_Node_Return));
                
                // Create an operand for the expression
                struct AST_Node_Operand *expr_operand = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                expr_operand->value.expr = (yyvsp[-1].expression);
                expr_operand->val_type = (yyvsp[-1].expression)->expr_type;
                expr_operand->operand_type = CONTENT_TYPE_EXPRESSION;
                
                struct AST_Node *operand_node = (struct AST_Node *)malloc(sizeof(struct AST_Node));
                operand_node->n_type = OPERAND_NODE;
                operand_node->value = expr_operand;
                
                return_node->value = operand_node;
                (yyval.instruction)->value.returnNode = return_node;
                debug_print("Return expression statement created", (yyval.instruction));
            }
#line 1534 "parser.tab.c"
    break;

  case 10: /* statement: if_statement  */
#line 287 "parser.y"
            {
                debug_print("Creating statement from if_statement", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = IF_NODE;
                (yyval.instruction)->value.ifNode = (yyvsp[0].ifNode);
                debug_print("If statement created", (yyval.instruction));
            }
#line 1546 "parser.tab.c"
    break;

  case 11: /* statement: for_loop  */
#line 295 "parser.y"
            {
                debug_print("Creating statement from for_loop", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = FOR_NODE;
                (yyval.instruction)->value.forNode = (yyvsp[0].forNode);
                debug_print("For loop created", (yyval.instruction));
            }
#line 1558 "parser.tab.c"
    break;

  case 12: /* statement: ID INC SEMICOLON  */
#line 303 "parser.y"
            {
                debug_print("Creating increment statement", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = ASSIGN_NODE;
                struct AST_Node_Assign *assign = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                assign->var = (yyvsp[-2].string);
                assign->val_type = DATA_TYPE_INT;
                assign->a_type = CONTENT_TYPE_EXPRESSION;
                
                struct AST_Node_Expression *expr = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                expr->op = "+";
                
                struct AST_Node_Operand *left = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                left->operand_type = CONTENT_TYPE_ID;
                left->value.val = (yyvsp[-2].string);
                left->val_type = DATA_TYPE_INT;
                expr->left_op = left;
                
                struct AST_Node_Operand *right = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                right->operand_type = CONTENT_TYPE_INT_NUMBER;
                right->value.val = "1";
                right->val_type = DATA_TYPE_INT;
                expr->right_op = right;
                
                expr->expr_type = DATA_TYPE_INT;
                assign->a_val.expr = expr;
                (yyval.instruction)->value.assign = assign;
            }
#line 1591 "parser.tab.c"
    break;

  case 13: /* statement: ID DEC SEMICOLON  */
#line 332 "parser.y"
            {
                debug_print("Creating decrement statement", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = ASSIGN_NODE;
                struct AST_Node_Assign *assign = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                assign->var = (yyvsp[-2].string);
                assign->val_type = DATA_TYPE_INT;
                assign->a_type = CONTENT_TYPE_EXPRESSION;
                
                struct AST_Node_Expression *expr = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                expr->op = "-";
                
                struct AST_Node_Operand *left = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                left->operand_type = CONTENT_TYPE_ID;
                left->value.val = (yyvsp[-2].string);
                left->val_type = DATA_TYPE_INT;
                expr->left_op = left;
                
                struct AST_Node_Operand *right = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                right->operand_type = CONTENT_TYPE_INT_NUMBER;
                right->value.val = "1";
                right->val_type = DATA_TYPE_INT;
                expr->right_op = right;
                
                expr->expr_type = DATA_TYPE_INT;
                assign->a_val.expr = expr;
                (yyval.instruction)->value.assign = assign;
            }
#line 1624 "parser.tab.c"
    break;

  case 14: /* statement: assignment SEMICOLON  */
#line 361 "parser.y"
            {
                debug_print("Creating statement from assignment", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = ASSIGN_NODE;
                struct Symbol *s = find_symbol((yyvsp[-1].assign)->var, local_table);
                if (s == NULL) {
                    printf("\n\n\t***Error: Variable '%s' not declared***\n\t***Line: %d***\n\n\n", (yyvsp[-1].assign)->var, yylineno);
                    n_error++;
                } else if (s->data_type != (yyvsp[-1].assign)->val_type) {
                    printf("\n\n\t***Error: Variable '%s' has been declared as a '%s' but type '%s' is assigned***\n\t***Line: %d***\n\n\n", 
                        (yyvsp[-1].assign)->var, type_to_str(s->data_type), type_to_str((yyvsp[-1].assign)->val_type), yylineno);
                    n_error++;
                } else {
                    (yyval.instruction)->value.assign = (yyvsp[-1].assign);
                    s->value_sym = (yyvsp[-1].assign)->a_val;
                    debug_print("Assignment statement created", (yyval.instruction));
                }
            }
#line 1647 "parser.tab.c"
    break;

  case 15: /* statement: initialization SEMICOLON  */
#line 380 "parser.y"
            {
                debug_print("Creating statement from initialization", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = INIT_NODE;
                (yyval.instruction)->value.init = (yyvsp[-1].init);
                struct Symbol *s = NULL;
                for(struct AST_Node_Init *init = (yyvsp[-1].init); init != NULL; init = init->next_init) {
                    s = find_symbol(init->assign->var, local_table);
                    if (s == NULL) {
                        s = add_symbol(init->assign->var, local_table, SYMBOL_VARIABLE, (yyvsp[-1].init)->data_type, DATA_TYPE_NONE, false, NULL, false, yylineno, null_value);
                        debug_print("Variable symbol added", s);
                    } else {
                        printf("\n\n\t***Error: Variable %s already declared***\n\t***Line: %d***\n\n\n", init->assign->var, yylineno);
                        n_error++;
                    }
                }
                debug_print("Initialization statement created", (yyval.instruction));
            }
#line 1670 "parser.tab.c"
    break;

  case 16: /* statement: output_stmnt SEMICOLON  */
#line 398 "parser.y"
                                   {
            debug_print("Creating statement from output", NULL);
            (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
            (yyval.instruction)->n_type = OUTPUT_NODE;
            (yyval.instruction)->value.outputNode = (yyvsp[-1].outputNode);
            debug_print("Output statement created", (yyval.instruction));
        }
#line 1682 "parser.tab.c"
    break;

  case 17: /* statement: create_class  */
#line 406 "parser.y"
            { 
                debug_print("Creating statement from class definition", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = CLASS_NODE;
                (yyval.instruction)->value.classNode = (yyvsp[0].classNode);
                debug_print("Class statement created", (yyval.instruction));
            }
#line 1694 "parser.tab.c"
    break;

  case 18: /* statement: create_class_child  */
#line 414 "parser.y"
            { 
                debug_print("Creating statement from class inheritance definition", NULL);
                (yyval.instruction) = (struct AST_Node_Instruction*)malloc(sizeof(struct AST_Node_Instruction));
                (yyval.instruction)->n_type = CLASS_CHILD_NODE;
                (yyval.instruction)->value.classNode = (yyvsp[0].classNode);
                debug_print("Class inheritance statement created", (yyval.instruction));
            }
#line 1706 "parser.tab.c"
    break;

  case 19: /* function_call: ID LPAR multi_fun_param RPAR  */
#line 425 "parser.y"
                                                { 
                                                (yyval.functionCall) = (struct AST_Node_FunctionCall*)malloc(sizeof(struct AST_Node_FunctionCall));
                                                struct Symbol *s = find_symtab((yyvsp[-3].string), local_table);
                                                if (s!=NULL) 
                                                    {
                                                    if (s->is_function) {
                                                        (yyval.functionCall)->func_name = (yyvsp[-3].string);
                                                        (yyval.functionCall)->return_type = s->ret_type;
                                                        (yyval.functionCall)->params = (yyvsp[-1].params);
                                                        /* Check if the function exists and if parameters are legit */
                                                        check_function_call((yyval.functionCall));                                                    
                                                        }
                                                    else {
                                                        printf("\n\n\t***Error: %s is not a function***\n\t***Line: %d***\n\n\n",(yyvsp[-3].string),yylineno);n_error++;
                                                        }
                                                    }
                                                else { printf("\n\n\t***Error: %s is not declared***\n\t***Line: %d***\n\n\n",(yyvsp[-3].string),yylineno); n_error++;}
                                                }
#line 1729 "parser.tab.c"
    break;

  case 20: /* function_call: ID LPAR RPAR  */
#line 443 "parser.y"
                                               { 
                                                (yyval.functionCall) = (struct AST_Node_FunctionCall*)malloc(sizeof(struct AST_Node_FunctionCall));
                                                struct Symbol *s = find_symtab((yyvsp[-2].string), local_table);
                                                if (s!=NULL) 
                                                    {
                                                    if (s->is_function) {
                                                        (yyval.functionCall)->func_name = (yyvsp[-2].string);
                                                        (yyval.functionCall)->return_type = s->ret_type;
                                                        (yyval.functionCall)->params = NULL;
                                                        /* Check if the function exists and if parameters are legit */
                                                        check_function_call((yyval.functionCall));                                                    
                                                        }
                                                    else {
                                                        printf("\n\n\t***Error: %s is not a function***\n\t***Line: %d***\n\n\n",(yyvsp[-2].string),yylineno);n_error++;
                                                        }
                                                    }
                                                else { printf("\n\n\t***Error: %s is not declared***\n\t***Line: %d***\n\n\n",(yyvsp[-2].string),yylineno); n_error++;}
                                                }
#line 1752 "parser.tab.c"
    break;

  case 21: /* function_def: types ID LPAR multi_fun_param RPAR LBRACE func_body RBRACE  */
#line 465 "parser.y"
                                        { scope_enter();
                    (yyval.functionDef) = (struct AST_Node_FunctionDef*)malloc(sizeof(struct AST_Node_FunctionDef));
                    (yyval.functionDef)->func_name = (yyvsp[-6].string);
                    (yyval.functionDef)->params = (yyvsp[-4].params);
                    (yyval.functionDef)->f_body = (yyvsp[-1].FBodyNode);
                    (yyval.functionDef)->return_type = (yyvsp[-7].data_type);
                    (yyval.functionDef)->is_class_method = is_inside_class;  // Flag if this is a class method
                    
                    // Check return type only if a return value exists
                    if ((yyval.functionDef)->f_body && (yyval.functionDef)->f_body->return_op) {
                        if ((yyvsp[-7].data_type) != (yyval.functionDef)->f_body->return_op->val_type) {
                            printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                (yyval.functionDef)->func_name, type_to_str((yyvsp[-7].data_type)), type_to_str((yyval.functionDef)->f_body->return_op->val_type));
                            n_error++;
                        }
                    }
                    
                    // add function to function array
                    function_array[function_counter] = (yyval.functionDef);
                    function_counter++;
                    
                    scope_exit();
                    printf("[DEBUG] Defined function %s with return type %s\n", (yyval.functionDef)->func_name, type_to_str((yyval.functionDef)->return_type));
                                        }
#line 1781 "parser.tab.c"
    break;

  case 22: /* function_def: types ID LPAR RPAR LBRACE func_body RBRACE  */
#line 490 "parser.y"
                                        { scope_enter();
                                        (yyval.functionDef) = (struct AST_Node_FunctionDef*)malloc(sizeof(struct AST_Node_FunctionDef));
                                        (yyval.functionDef)->func_name = (yyvsp[-5].string);
                                        (yyval.functionDef)->params = NULL;
                                        (yyval.functionDef)->f_body = (yyvsp[-1].FBodyNode);
                                        (yyval.functionDef)->return_type = (yyvsp[-6].data_type);
                                        (yyval.functionDef)->is_class_method = is_inside_class;  // Flag if this is a class method
                                        
                                        // Check return type only if a return value exists
                                        if ((yyval.functionDef)->f_body && (yyval.functionDef)->f_body->return_op) {
                                            if ((yyvsp[-6].data_type) != (yyval.functionDef)->f_body->return_op->val_type) {
                                                printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                                    (yyval.functionDef)->func_name, type_to_str((yyvsp[-6].data_type)), type_to_str((yyval.functionDef)->f_body->return_op->val_type));
                                                n_error++;
                                            }
                                        }
                                        
                                        // add function to function array
                                        function_array[function_counter] = (yyval.functionDef);
                                        function_counter++;
                                        
                                        scope_exit();
                                        printf("[DEBUG] Defined function %s with return type %s\n", (yyval.functionDef)->func_name, type_to_str((yyval.functionDef)->return_type));
                                        }
#line 1810 "parser.tab.c"
    break;

  case 23: /* function_def: INT MAIN LPAR RPAR func_body  */
#line 514 "parser.y"
                                                      {     
                                                        printf("[DEBUG] Matched main function\n");
                                                        scope_enter();
                                                        (yyval.functionDef) = (struct AST_Node_FunctionDef*)malloc(sizeof(struct AST_Node_FunctionDef));
                                                        (yyval.functionDef)->func_name = "main";
                                                        (yyval.functionDef)->params = NULL;
                                                        (yyval.functionDef)->return_type = DATA_TYPE_INT;
                                                        (yyval.functionDef)->f_body = (yyvsp[0].FBodyNode);
                                                        scope_exit();
                                                        }
#line 1825 "parser.tab.c"
    break;

  case 24: /* function_def: initialization LPAR RPAR func_body  */
#line 524 "parser.y"
                                                      { if (in_class == false ){scope_enter();};
                                                        (yyval.functionDef) = (struct AST_Node_FunctionDef*)malloc(sizeof(struct AST_Node_FunctionDef));
                                                        (yyval.functionDef)->func_name = (yyvsp[-3].init)->assign->var;
                                                        (yyval.functionDef)->params = NULL;
                                                        (yyval.functionDef)->f_body = (yyvsp[0].FBodyNode);
                                                        // check if return data type and function data type match
                                                        if ((yyvsp[-3].init)->data_type !=  (yyval.functionDef)->f_body->return_op->val_type)
                                                            {
                                                            printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                                            (yyval.functionDef)->func_name, type_to_str((yyvsp[-3].init)->data_type), type_to_str((yyval.functionDef)->f_body->return_op->val_type));n_error++;
                                                            }
                                                        (yyval.functionDef)->return_type = (yyvsp[-3].init)->data_type;
                                                        // add function to function array; 
                                                        function_array[function_counter] = (yyval.functionDef);
                                                        function_counter++;
                                                        if (in_class == false ){scope_exit();};
                                                    }
#line 1847 "parser.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 747 "parser.y"
                                        {in_class = true;}
#line 1853 "parser.tab.c"
    break;

  case 26: /* create_class: CLASS ID $@2 class_body  */
#line 748 "parser.y"
                                        {
                                        (yyval.classNode) = (struct AST_Node_Class*)malloc(sizeof(struct AST_Node_Class));
                                        (yyval.classNode)->parent_class_public = (struct AST_Node_Parent_Public*)malloc(sizeof(struct AST_Node_Parent_Public));
                                        (yyval.classNode)->class_name = (yyvsp[-2].string);
                                        (yyval.classNode)->c_body = (yyvsp[0].CBodyNode);
                                        (yyval.classNode)->parent_class_public = NULL;
                                        class_array[class_counter] = (yyval.classNode);
                                        class_counter++;
                                        in_class = false;
                                        }
#line 1868 "parser.tab.c"
    break;

  case 27: /* $@3: %empty  */
#line 761 "parser.y"
                                               {in_class = true;}
#line 1874 "parser.tab.c"
    break;

  case 28: /* create_class_child: CLASS ID $@3 COLON PUBLIC ID class_body  */
#line 762 "parser.y"
                                               {
                                                        (yyval.classNode) = (struct AST_Node_Class*)malloc(sizeof(struct AST_Node_Class));
                                                        (yyval.classNode)->parent_class_public = (struct AST_Node_Parent_Public*)malloc(sizeof(struct AST_Node_Parent_Public));
                                                        (yyval.classNode)->class_name = (yyvsp[-5].string);
                                                        (yyval.classNode)->c_body = (yyvsp[0].CBodyNode);
                                                        // search parent class in the class array
                                                        for (int i = 0; i<class_counter; i++)
                                                            {
                                                            // compare the name of the parent class in the statement with the name of the class in the class array
                                                             if (strcmp(class_array[i]->class_name, (yyvsp[-1].string)) == 0)
                                                                {
                                                                (yyval.classNode)->parent_class = class_array[i];
                                                                (yyval.classNode)->parent_class->class_name = class_array[i]->class_name;
                                                                (yyval.classNode)->parent_class_public->parent_pub_body = class_array[i]->c_body->pub_body;
                                                                (yyval.classNode)->parent_class_public->next_parent_public = class_array[i]->parent_class_public;
                                                                class_array[class_counter] = (yyval.classNode);        
                                                                class_counter++;
                                                                break;
                                                                }
                                                             else if (i == class_counter){printf("\n\n\n\t\t***ERROR: class parent %s not found***\n\n\n",(yyvsp[-1].string)); n_error++;}
                                                        }
                                                        in_class = false;

                                                        }
#line 1903 "parser.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 789 "parser.y"
                       { is_inside_class = true; }
#line 1909 "parser.tab.c"
    break;

  case 30: /* class_body: LBRACE $@4 sections RBRACE  */
#line 790 "parser.y"
                    {
                    (yyval.CBodyNode) = (struct AST_Node_CBody*)malloc(sizeof(struct AST_Node_CBody));
                    (yyval.CBodyNode)->pri_body = NULL;
                    (yyval.CBodyNode)->pub_body = NULL;
                    is_inside_class = false;
                    debug_print("Class body created", (yyval.CBodyNode));
                    }
#line 1921 "parser.tab.c"
    break;

  case 33: /* section: PUBLIC COLON statements  */
#line 806 "parser.y"
                    { 
                    (yyval.statements) = (yyvsp[0].statements); 
                    debug_print("Public section processed", (yyval.statements)); 
                    }
#line 1930 "parser.tab.c"
    break;

  case 34: /* section: PRIVATE COLON statements  */
#line 811 "parser.y"
                    { 
                    (yyval.statements) = (yyvsp[0].statements); 
                    debug_print("Private section processed", (yyval.statements)); 
                    }
#line 1939 "parser.tab.c"
    break;

  case 35: /* if_statement: IF LPAR if_condition RPAR body else_if_statement else_statement  */
#line 820 "parser.y"
                                                        { 
                                                        (yyval.ifNode) = (struct AST_Node_If*)malloc(sizeof(struct AST_Node_If));
                                                        (yyval.ifNode)->condition = (yyvsp[-4].expression);
                                                        (yyval.ifNode)->if_body = (yyvsp[-2].statements);
                                                        (yyval.ifNode)->else_if = (yyvsp[-1].elseIfNode);
                                                        (yyval.ifNode)->else_body = (yyvsp[0].elseNode);
                                                        }
#line 1951 "parser.tab.c"
    break;

  case 36: /* if_statement: IF LPAR if_condition RPAR body ELSE body  */
#line 828 "parser.y"
                                                        { 
                                                        (yyval.ifNode) = (struct AST_Node_If*)malloc(sizeof(struct AST_Node_If));
                                                        (yyval.ifNode)->condition = (yyvsp[-4].expression);
                                                        (yyval.ifNode)->if_body = (yyvsp[-2].statements);
                                                        (yyval.ifNode)->else_if = NULL;
                                                        struct AST_Node_Else *else_node = (struct AST_Node_Else*)malloc(sizeof(struct AST_Node_Else));
                                                        else_node->else_body = (yyvsp[0].statements);
                                                        (yyval.ifNode)->else_body = else_node;
                                                        }
#line 1965 "parser.tab.c"
    break;

  case 37: /* if_statement: IF LPAR if_condition RPAR body  */
#line 838 "parser.y"
                                                        { 
                                                        (yyval.ifNode) = (struct AST_Node_If*)malloc(sizeof(struct AST_Node_If));
                                                        (yyval.ifNode)->condition = (yyvsp[-2].expression);
                                                        (yyval.ifNode)->if_body = (yyvsp[0].statements);
                                                        (yyval.ifNode)->else_if = NULL;
                                                        (yyval.ifNode)->else_body = NULL;
                                                        }
#line 1977 "parser.tab.c"
    break;

  case 38: /* if_condition: expr  */
#line 848 "parser.y"
                                                {
                                                if((yyvsp[0].expression)->expr_type != DATA_TYPE_BOOL) { printf("\n\n\t***Error: IF condition must be boolean type***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                                else { (yyval.expression) = (yyvsp[0].expression); }
                                                }
#line 1986 "parser.tab.c"
    break;

  case 39: /* else_if_statement: ELSE IF LPAR if_condition RPAR body  */
#line 855 "parser.y"
                                                    {
                                                    (yyval.elseIfNode) = (struct AST_Node_Else_If*)malloc(sizeof(struct AST_Node_Else_If));
                                                    (yyval.elseIfNode)->condition = (yyvsp[-2].expression);
                                                    (yyval.elseIfNode)->elif_body = (yyvsp[0].statements);
                                                    }
#line 1996 "parser.tab.c"
    break;

  case 40: /* else_if_statement: %empty  */
#line 860 "parser.y"
                              { (yyval.elseIfNode) = NULL; }
#line 2002 "parser.tab.c"
    break;

  case 41: /* else_statement: ELSE body  */
#line 864 "parser.y"
                                                {
                                                (yyval.elseNode) = (struct AST_Node_Else*)malloc(sizeof(struct AST_Node_Else));
                                                (yyval.elseNode)->else_body = (yyvsp[0].statements);
                                                }
#line 2011 "parser.tab.c"
    break;

  case 42: /* else_statement: %empty  */
#line 868 "parser.y"
                              { (yyval.elseNode) = NULL; }
#line 2017 "parser.tab.c"
    break;

  case 43: /* for_loop: FOR LPAR assignment SEMICOLON rel_expr SEMICOLON assignment RPAR body  */
#line 872 "parser.y"
                                                                                        {
                                                                                        (yyval.forNode) = (struct AST_Node_For*)malloc(sizeof(struct AST_Node_For));
                                                                                        (yyval.forNode)->init = (yyvsp[-6].assign);
                                                                                        (yyval.forNode)->condition = (yyvsp[-4].expression);
                                                                                        (yyval.forNode)->increment = (yyvsp[-2].assign);
                                                                                        // The increment can be expressed only as x = x + 1 and not as x++ or x += 1
                                                                                        // The sign of the increment expression will be used at translation time for further control:
                                                                                        // The control is needed to solve a problem where the decrement is written as x = x -1 and not as x = x - 1
                                                                                        (yyval.forNode)->increment->a_val.expr->op = (yyvsp[-2].assign)->a_val.expr->op;
                                                                                        (yyval.forNode)->for_body = (yyvsp[0].statements);
                                                                                        delete_symbol( find_symbol((yyvsp[-6].assign)->var,local_table), local_table);
                                                                                        }
#line 2034 "parser.tab.c"
    break;

  case 44: /* body: LBRACE statements RBRACE  */
#line 887 "parser.y"
                                                  { (yyval.statements) = (yyvsp[-1].statements); }
#line 2040 "parser.tab.c"
    break;

  case 45: /* func_body: LBRACE statements RETURN content SEMICOLON RBRACE  */
#line 892 "parser.y"
            {
                printf("[DEBUG] Function body with statements and return\n");
                (yyval.FBodyNode) = (struct AST_Node_FBody*)malloc(sizeof(struct AST_Node_FBody));                                       
                (yyval.FBodyNode)->func_body = (yyvsp[-4].statements);
                (yyval.FBodyNode)->return_op = (yyvsp[-2].operand);
                printf("[DEBUG] Return type: %d\n", (yyval.FBodyNode)->return_op->val_type);
            }
#line 2052 "parser.tab.c"
    break;

  case 46: /* func_body: LBRACE statements RETURN expr SEMICOLON RBRACE  */
#line 900 "parser.y"
            {
                printf("[DEBUG] Function body with statements and return expression\n");
                (yyval.FBodyNode) = (struct AST_Node_FBody*)malloc(sizeof(struct AST_Node_FBody));                                       
                (yyval.FBodyNode)->func_body = (yyvsp[-4].statements);
                
                // Create an operand for the expression
                struct AST_Node_Operand *expr_operand = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                expr_operand->value.expr = (yyvsp[-2].expression);
                expr_operand->val_type = (yyvsp[-2].expression)->expr_type;
                expr_operand->operand_type = CONTENT_TYPE_EXPRESSION;
                
                (yyval.FBodyNode)->return_op = expr_operand;
                printf("[DEBUG] Return expression type: %d\n", (yyval.FBodyNode)->return_op->val_type);
            }
#line 2071 "parser.tab.c"
    break;

  case 47: /* func_body: LBRACE RETURN content SEMICOLON RBRACE  */
#line 915 "parser.y"
            {
                printf("[DEBUG] Function body with return only\n");
                (yyval.FBodyNode) = (struct AST_Node_FBody*)malloc(sizeof(struct AST_Node_FBody));
                (yyval.FBodyNode)->func_body = NULL;
                (yyval.FBodyNode)->return_op = (yyvsp[-2].operand);
                printf("[DEBUG] Return type: %d\n", (yyval.FBodyNode)->return_op->val_type);
            }
#line 2083 "parser.tab.c"
    break;

  case 48: /* func_body: LBRACE RETURN expr SEMICOLON RBRACE  */
#line 923 "parser.y"
            {
                printf("[DEBUG] Function body with return expression only\n");
                (yyval.FBodyNode) = (struct AST_Node_FBody*)malloc(sizeof(struct AST_Node_FBody));
                (yyval.FBodyNode)->func_body = NULL;
                
                // Create an operand for the expression
                struct AST_Node_Operand *expr_operand = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                expr_operand->value.expr = (yyvsp[-2].expression);
                expr_operand->val_type = (yyvsp[-2].expression)->expr_type;
                expr_operand->operand_type = CONTENT_TYPE_EXPRESSION;
                
                (yyval.FBodyNode)->return_op = expr_operand;
                printf("[DEBUG] Return expression type: %d\n", (yyval.FBodyNode)->return_op->val_type);
            }
#line 2102 "parser.tab.c"
    break;

  case 49: /* func_body: LBRACE statements RBRACE  */
#line 938 "parser.y"
            {
                printf("[DEBUG] Function body with statements only (no return)\n");
                (yyval.FBodyNode) = (struct AST_Node_FBody*)malloc(sizeof(struct AST_Node_FBody));
                (yyval.FBodyNode)->func_body = (yyvsp[-1].statements);
                // For a function with no return, set a default return type
                struct AST_Node_Operand *default_return = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                default_return->operand_type = CONTENT_TYPE_INT_NUMBER;
                default_return->val_type = DATA_TYPE_INT;
                default_return->value.val = strdup("0"); // Default return 0
                (yyval.FBodyNode)->return_op = default_return;
            }
#line 2118 "parser.tab.c"
    break;

  case 50: /* expr: math_expr  */
#line 954 "parser.y"
                {
                    (yyval.expression) = (yyvsp[0].expression);
                }
#line 2126 "parser.tab.c"
    break;

  case 51: /* expr: ID INC  */
#line 958 "parser.y"
                {
                    debug_print("Creating increment expression", NULL);
                    struct AST_Node_Expression *node = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                    node->op = "+=";
                    
                    // Create left operand (variable)
                    struct AST_Node_Operand *left = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                    left->operand_type = CONTENT_TYPE_ID;
                    left->value.val = (yyvsp[-1].string);
                    left->val_type = DATA_TYPE_INT;
                    node->left_op = left;
                    
                    // Create right operand (constant 1)
                    struct AST_Node_Operand *right = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                    right->operand_type = CONTENT_TYPE_INT_NUMBER;
                    right->value.val = "1";
                    right->val_type = DATA_TYPE_INT;
                    node->right_op = right;
                    
                    node->expr_type = DATA_TYPE_INT;
                    (yyval.expression) = node;
                }
#line 2153 "parser.tab.c"
    break;

  case 52: /* expr: ID DEC  */
#line 981 "parser.y"
                {
                    debug_print("Creating decrement expression", NULL);
                    struct AST_Node_Expression *node = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                    node->op = "-=";
                    
                    // Create left operand (variable)
                    struct AST_Node_Operand *left = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                    left->operand_type = CONTENT_TYPE_ID;
                    left->value.val = (yyvsp[-1].string);
                    left->val_type = DATA_TYPE_INT;
                    node->left_op = left;
                    
                    // Create right operand (constant 1)
                    struct AST_Node_Operand *right = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                    right->operand_type = CONTENT_TYPE_INT_NUMBER;
                    right->value.val = "1";
                    right->val_type = DATA_TYPE_INT;
                    node->right_op = right;
                    
                    node->expr_type = DATA_TYPE_INT;
                    (yyval.expression) = node;
                }
#line 2180 "parser.tab.c"
    break;

  case 53: /* expr: logic_expr  */
#line 1003 "parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2186 "parser.tab.c"
    break;

  case 54: /* expr: rel_expr  */
#line 1004 "parser.y"
                                        { (yyval.expression) = (yyvsp[0].expression); }
#line 2192 "parser.tab.c"
    break;

  case 55: /* expr: %empty  */
#line 1005 "parser.y"
                                        { (yyval.expression) = NULL; }
#line 2198 "parser.tab.c"
    break;

  case 56: /* expr: LPAR expr RPAR  */
#line 1006 "parser.y"
                                        { (yyval.expression) = (yyvsp[-1].expression); }
#line 2204 "parser.tab.c"
    break;

  case 57: /* math_expr: content ADD content  */
#line 1010 "parser.y"
                                            {
                                            (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                            // queste malloc permettono il riconoscimento della x
                                            (yyval.expression)->left_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->right_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->op = (yyvsp[-1].string);
                                            (yyval.expression)->expr_type = (yyvsp[0].operand)->val_type;
                                            if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                                { printf("\n\n\t***Error: Cannot add '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                                
                                            else 
                                                {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                                };
                                            }
#line 2227 "parser.tab.c"
    break;

  case 58: /* math_expr: content SUB content  */
#line 1028 "parser.y"
                                            { 
                                            (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                            (yyval.expression)->op = (yyvsp[-1].string);
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = (yyvsp[-2].operand)->val_type;
                                            if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                                { printf("\n\n\t***Error: Cannot subtract '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                            else 
                                                {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                                };
                                            }
#line 2246 "parser.tab.c"
    break;

  case 59: /* math_expr: content MUL content  */
#line 1042 "parser.y"
                                            { 
                                            (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                            // queste malloc permettono il riconoscimento della x
                                            (yyval.expression)->left_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->right_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->op = (yyvsp[-1].string);
                                            if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                                { printf("\n\n\t***Error: Cannot multiply '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                            else 
                                                {
                                                (yyval.expression)->left_op = (yyvsp[-2].operand);
                                                (yyval.expression)->right_op = (yyvsp[0].operand);
                                                (yyval.expression)->expr_type = (yyvsp[-2].operand)->val_type;
                                                }
                                            }
#line 2268 "parser.tab.c"
    break;

  case 60: /* math_expr: content INT_NUMBER  */
#line 1059 "parser.y"
                                            {   
                                            // This rule is used in case expression written as: int x = A -B and not as x = A - B
                                            // check if the second token is a negative integer number
                                            if (atoi((yyvsp[0].string))<0) 
                                                {                                               
                                                int temp= atoi((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%d", temp );
                                                char* temp_str = (char*)malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%d", temp );

                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S1->value = (yyvsp[-1].operand)->value;
                                                S1->val_type = DATA_TYPE_INT;
                                                S1->operand_type = CONTENT_TYPE_INT_NUMBER;

                                                S2 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_INT;
                                                S2->operand_type = CONTENT_TYPE_INT_NUMBER;
                                                
                                                (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_INT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed ***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
#line 2305 "parser.tab.c"
    break;

  case 61: /* math_expr: INT_NUMBER INT_NUMBER  */
#line 1091 "parser.y"
                                            {   
                                            // This rule is used in case expression written as: int x = A -B and not as x = A - B
                                            // check if the second token is a negative integer number
                                            if (atoi((yyvsp[0].string))<0) 
                                                {                                               
                                                int temp= atoi((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%d", temp );
                                                char* temp_str = (char*)malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%d", temp );

                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S1->value.val = (yyvsp[-1].string);
                                                S1->val_type = DATA_TYPE_INT;
                                                S1->operand_type = CONTENT_TYPE_INT_NUMBER;

                                                S2 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_INT;
                                                S2->operand_type = CONTENT_TYPE_INT_NUMBER;
                                                
                                                (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_INT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed ***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
#line 2342 "parser.tab.c"
    break;

  case 62: /* math_expr: content FLOAT_NUMBER  */
#line 1124 "parser.y"
                                            {
                                            //check if the second token is a negative float number
                                            if (atof((yyvsp[0].string))<0) 
                                                {                                               
                                                float temp= atof((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%4.3f", temp );
                                                char* temp_str = (char*)malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%4.3f", temp );
                                                
                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S1->value = (yyvsp[-1].operand)->value;
                                                S1->val_type = DATA_TYPE_FLOAT;
                                                S1->operand_type = CONTENT_TYPE_FLOAT_NUMBER;

                                                S2 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_FLOAT;
                                                S2->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                                
                                                (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_FLOAT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                            }
#line 2378 "parser.tab.c"
    break;

  case 63: /* math_expr: FLOAT_NUMBER FLOAT_NUMBER  */
#line 1155 "parser.y"
                                            {
                                            //check if the second token is a negative float number
                                            if (atof((yyvsp[0].string))<0) 
                                                {                                               
                                                float temp= atof((yyvsp[0].string));
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%4.3f", temp );
                                                char* temp_str = (char*)malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%4.3f", temp );
                                                
                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S1->value.val = (yyvsp[-1].string);
                                                S1->val_type = DATA_TYPE_FLOAT;
                                                S1->operand_type = CONTENT_TYPE_FLOAT_NUMBER;

                                                S2 = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_FLOAT;
                                                S2->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                                
                                                (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                                (yyval.expression)->op = "-";
                                                (yyval.expression)->left_op = S1;
                                                (yyval.expression)->right_op = S2;
                                                (yyval.expression)->expr_type = DATA_TYPE_FLOAT;

                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
#line 2415 "parser.tab.c"
    break;

  case 64: /* math_expr: content DIV content  */
#line 1187 "parser.y"
                                        { 
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        // queste malloc permettono il riconoscimento della x
                                        (yyval.expression)->left_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->right_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->left_op = (yyvsp[-2].operand);
                                        (yyval.expression)->right_op = (yyvsp[0].operand);
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot divide '%s' by '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else    
                                            {
                                            if (strcmp((yyvsp[0].operand)->value.val,"0" ) == 0)   { printf("\n\n\t***Error: Cannot divide by 0***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            else 
                                                {
                                                (yyval.expression)->left_op = (yyvsp[-2].operand);
                                                (yyval.expression)->right_op = (yyvsp[0].operand);
                                                (yyval.expression)->expr_type = (yyvsp[-2].operand)->val_type;
                                                }
                                            }
                                        }
#line 2441 "parser.tab.c"
    break;

  case 65: /* logic_expr: LPAR logic_expr RPAR  */
#line 1211 "parser.y"
                                        {   
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression) = (yyvsp[-1].expression);
                                        }
#line 2450 "parser.tab.c"
    break;

  case 66: /* logic_expr: content AND content  */
#line 1215 "parser.y"
                                        {   
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != DATA_TYPE_BOOL || (yyvsp[0].operand)->val_type != DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot AND '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno);n_error++; }
                                        else {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2466 "parser.tab.c"
    break;

  case 67: /* logic_expr: content OR content  */
#line 1226 "parser.y"
                                        {   
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != DATA_TYPE_BOOL || (yyvsp[0].operand)->val_type != DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot OR '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno);n_error++; }
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2483 "parser.tab.c"
    break;

  case 68: /* rel_expr: LPAR rel_expr RPAR  */
#line 1241 "parser.y"
                                        {  
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression) = (yyvsp[-1].expression); 
                                        }
#line 2492 "parser.tab.c"
    break;

  case 69: /* rel_expr: content LT content  */
#line 1245 "parser.y"
                                        { 
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->left_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->right_op = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                        (yyval.expression)->left_op = (yyvsp[-2].operand);
                                        (yyval.expression)->right_op = (yyvsp[0].operand);
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                        else {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2514 "parser.tab.c"
    break;

  case 70: /* rel_expr: content LE content  */
#line 1262 "parser.y"
                                        { 
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2533 "parser.tab.c"
    break;

  case 71: /* rel_expr: content GT content  */
#line 1276 "parser.y"
                                        { 
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2552 "parser.tab.c"
    break;

  case 72: /* rel_expr: content GE content  */
#line 1290 "parser.y"
                                        {
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno);n_error++; }
                                        else if ((yyvsp[-2].operand)->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2571 "parser.tab.c"
    break;

  case 73: /* rel_expr: content EEQ content  */
#line 1304 "parser.y"
                                        { 
                                        (yyval.expression) = (struct AST_Node_Expression*)malloc(sizeof(struct AST_Node_Expression));
                                        (yyval.expression)->op = (yyvsp[-1].string);
                                        if ((yyvsp[-2].operand)->val_type != (yyvsp[0].operand)->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str((yyvsp[-2].operand)->val_type), type_to_str((yyvsp[0].operand)->val_type),yylineno); n_error++;}
                                        else 
                                            {
                                            (yyval.expression)->left_op = (yyvsp[-2].operand);
                                            (yyval.expression)->right_op = (yyvsp[0].operand);
                                            (yyval.expression)->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
#line 2588 "parser.tab.c"
    break;

  case 74: /* output_stmnt: COUT multi_lshift  */
#line 1323 "parser.y"
                                  {
                    debug_print("Creating output statement", NULL);
                    (yyval.outputNode) = (yyvsp[0].outputNode);
                    debug_print("Output statement created", (yyval.outputNode));
                }
#line 2598 "parser.tab.c"
    break;

  case 75: /* multi_lshift: single_lshift  */
#line 1340 "parser.y"
                              { // Base case for the recursion
                    debug_print("multi_lshift: single_lshift base case", (yyvsp[0].operand));
                    (yyval.outputNode) = (struct AST_Node_Output*)malloc(sizeof(struct AST_Node_Output));
                    (yyval.outputNode)->output_op = (yyvsp[0].operand); // $1 is an AST_Node_Operand from single_lshift
                    (yyval.outputNode)->next_output = NULL;
                }
#line 2609 "parser.tab.c"
    break;

  case 76: /* multi_lshift: single_lshift multi_lshift  */
#line 1346 "parser.y"
                                           { // Recursive step
                    debug_print("multi_lshift: single_lshift multi_lshift recursive step", (yyvsp[-1].operand));
                    (yyval.outputNode) = (struct AST_Node_Output*)malloc(sizeof(struct AST_Node_Output));
                    (yyval.outputNode)->output_op = (yyvsp[-1].operand); // $1 is an AST_Node_Operand from single_lshift
                    (yyval.outputNode)->next_output = (yyvsp[0].outputNode); // $2 is the AST_Node_Output from the recursive call
                }
#line 2620 "parser.tab.c"
    break;

  case 77: /* single_lshift: LSHIFT content  */
#line 1371 "parser.y"
                                {
                    (yyval.operand) = (yyvsp[0].operand);
                }
#line 2628 "parser.tab.c"
    break;

  case 78: /* multi_fun_param: fun_param  */
#line 1378 "parser.y"
                                                   {
                                                    (yyvsp[0].params)->next_param = NULL;
                                                    (yyval.params) = (yyvsp[0].params);
                                                    }
#line 2637 "parser.tab.c"
    break;

  case 79: /* multi_fun_param: fun_param COMMA multi_fun_param  */
#line 1382 "parser.y"
                                                    {
                                                    (yyvsp[-2].params)->next_param = (yyvsp[0].params);
                                                    (yyval.params) = (yyvsp[-2].params);
                                                    }
#line 2646 "parser.tab.c"
    break;

  case 80: /* fun_param: types ID  */
#line 1389 "parser.y"
                                { 
                                (yyval.params) = (struct AST_Node_Params*)malloc(sizeof(struct AST_Node_Params));
                                (yyval.params)->decl_param = (struct AST_Node_Init*)malloc(sizeof(struct AST_Node_Init));
                                (yyval.params)->decl_param->data_type = (yyvsp[-1].data_type);
                                (yyval.params)->decl_param->assign = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                                (yyval.params)->decl_param->assign->val_type = (yyvsp[-1].data_type);
                                (yyval.params)->decl_param->assign->var = (yyvsp[0].string);
                                (yyval.params)->decl_param->assign->a_val.val = NULL;
                                (yyval.params)->decl_param->assign->a_type = CONTENT_TYPE_ID;
                                }
#line 2661 "parser.tab.c"
    break;

  case 81: /* fun_param: content  */
#line 1399 "parser.y"
                                { 
                                (yyval.params) = (struct AST_Node_Params*)malloc(sizeof(struct AST_Node_Params));
                                //$$->call_param = malloc(sizeof(struct AST_Node_Operand));
                                (yyval.params)->call_param = (yyvsp[0].operand);
                                //$$->call_param->val_type = $1->val_type;
                                }
#line 2672 "parser.tab.c"
    break;

  case 82: /* initialization: types ID  */
#line 1408 "parser.y"
                                {
                                (yyval.init) = (struct AST_Node_Init*)malloc(sizeof(struct AST_Node_Init));
                                (yyval.init)->data_type = (yyvsp[-1].data_type);
                                (yyval.init)->next_init = NULL;
                                (yyval.init)->assign = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                                (yyval.init)->assign->val_type = (yyvsp[-1].data_type);
                                (yyval.init)->assign->var = (yyvsp[0].string);
                                (yyval.init)->assign->a_val.val = NULL;
                                (yyval.init)->assign->a_type = CONTENT_TYPE_ID;
                                }
#line 2687 "parser.tab.c"
    break;

  case 83: /* assignment: ID EQ ID  */
#line 1421 "parser.y"
                                    { 
                                    (yyval.assign) = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                                    (yyval.assign)->var = (yyvsp[-2].string);
                                    (yyval.assign)->a_val.val = (yyvsp[0].string);
                                    (yyval.assign)->a_type = CONTENT_TYPE_ID;
                                    struct Symbol *s = find_symbol((yyvsp[0].string), local_table);
                                    if (s==NULL) { (yyval.assign)->val_type = DATA_TYPE_NONE; }
                                    else { (yyval.assign)-> val_type = s->data_type; }
                                    }
#line 2701 "parser.tab.c"
    break;

  case 84: /* assignment: types ID EQ content  */
#line 1430 "parser.y"
                                    { 
                                    struct Symbol *s = NULL;
                                    s = find_symbol((yyvsp[-2].string), local_table);
                                    if (s == NULL)  
                                        { s = add_symbol((yyvsp[-2].string), local_table, SYMBOL_VARIABLE, (yyvsp[-3].data_type), (yyvsp[-3].data_type), false, NULL, false, yylineno, (yyvsp[0].operand)->value); }
                                    else { printf("\n\n\t***Error: Variable %s already declared, value is %s***\n\t***Line: %d***\n\n\n",(yyvsp[-2].string),s->value_sym.val,yylineno); n_error++;}
                                    if(((yyvsp[-3].data_type) != (yyvsp[0].operand)->val_type))
                                        { printf("\n\n\t***Error: Cannot assign type %s to type %s***\n\t***Line: %d***\n\n\n",type_to_str((yyvsp[0].operand)->val_type),type_to_str((yyvsp[-3].data_type)),yylineno); n_error++;}
                                    else
                                        {
                                        (yyval.assign) = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                                        (yyval.assign)->a_type = (yyvsp[0].operand)->operand_type;
                                        (yyval.assign)->var = (yyvsp[-2].string);
                                        (yyval.assign)->a_val = (yyvsp[0].operand)->value;
                                        (yyval.assign)->val_type = (yyvsp[-3].data_type);
                                        }
                                    }
#line 2723 "parser.tab.c"
    break;

  case 85: /* assignment: ID EQ content  */
#line 1447 "parser.y"
                                    { 
                                    (yyval.assign) = (struct AST_Node_Assign*)malloc(sizeof(struct AST_Node_Assign));
                                    (yyval.assign)->var = (yyvsp[-2].string);
                                    (yyval.assign)->a_val = (yyvsp[0].operand)->value;
                                    (yyval.assign)->val_type = (yyvsp[0].operand)->val_type;
                                    (yyval.assign)->a_type = (yyvsp[0].operand)->operand_type;
                                    }
#line 2735 "parser.tab.c"
    break;

  case 86: /* content: ID  */
#line 1457 "parser.y"
                                { 
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                struct Symbol *s = find_symtab((yyvsp[0].string), local_table);
                                if(s==NULL) { (yyval.operand)->val_type = DATA_TYPE_NONE; }
                                else 
                                    {
                                    (yyval.operand)->value.val = (yyvsp[0].string);
                                    (yyval.operand)->val_type = s->data_type;
                                    (yyval.operand)->operand_type = CONTENT_TYPE_ID;
                                    }
                                }
#line 2751 "parser.tab.c"
    break;

  case 87: /* content: FLOAT_NUMBER  */
#line 1468 "parser.y"
                                {
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.val = (yyvsp[0].string);
                                (yyval.operand)->val_type = DATA_TYPE_FLOAT;
                                (yyval.operand)->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                }
#line 2762 "parser.tab.c"
    break;

  case 88: /* content: INT_NUMBER  */
#line 1474 "parser.y"
                                {
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.val = (yyvsp[0].string);
                                (yyval.operand)->val_type = DATA_TYPE_INT;
                                (yyval.operand)->operand_type = CONTENT_TYPE_INT_NUMBER;
                                }
#line 2773 "parser.tab.c"
    break;

  case 89: /* content: STRING_V  */
#line 1480 "parser.y"
                                { 
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.val = (yyvsp[0].string);
                                (yyval.operand)->val_type = DATA_TYPE_STRING;
                                (yyval.operand)->operand_type = CONTENT_TYPE_STRING;
                                }
#line 2784 "parser.tab.c"
    break;

  case 90: /* content: BOOL_V  */
#line 1486 "parser.y"
                                { 
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                if (strcmp((yyvsp[0].string),"false")==0){(yyval.operand)->value.val = "False";}
                                else if (strcmp((yyvsp[0].string),"true")==0){(yyval.operand)->value.val = "True";}
                                (yyval.operand)->val_type = DATA_TYPE_BOOL;
                                (yyval.operand)->operand_type = CONTENT_TYPE_BOOL;
                                }
#line 2796 "parser.tab.c"
    break;

  case 91: /* content: function_call  */
#line 1493 "parser.y"
                                {
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.funca = (yyvsp[0].functionCall);
                                (yyval.operand)->val_type = (yyvsp[0].functionCall)->return_type;
                                (yyval.operand)->operand_type = CONTENT_TYPE_FUNCTION;
                                }
#line 2807 "parser.tab.c"
    break;

  case 92: /* content: expr  */
#line 1499 "parser.y"
                                { 
                                (yyval.operand) = (struct AST_Node_Operand*)malloc(sizeof(struct AST_Node_Operand));
                                (yyval.operand)->value.expr = (yyvsp[0].expression);
                                (yyval.operand)->val_type = (yyvsp[0].expression)->expr_type;
                                (yyval.operand)->operand_type = CONTENT_TYPE_EXPRESSION;
                                }
#line 2818 "parser.tab.c"
    break;

  case 93: /* types: FLOAT  */
#line 1508 "parser.y"
                    { (yyval.data_type) = DATA_TYPE_FLOAT; }
#line 2824 "parser.tab.c"
    break;

  case 94: /* types: INT  */
#line 1509 "parser.y"
                    { (yyval.data_type) = DATA_TYPE_INT; }
#line 2830 "parser.tab.c"
    break;

  case 95: /* types: STRING  */
#line 1510 "parser.y"
                    { (yyval.data_type) = DATA_TYPE_STRING; }
#line 2836 "parser.tab.c"
    break;

  case 96: /* types: BOOL  */
#line 1511 "parser.y"
                    { (yyval.data_type) = DATA_TYPE_BOOL; }
#line 2842 "parser.tab.c"
    break;


#line 2846 "parser.tab.c"

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

#line 1512 "parser.y"


/****************** Functions *****************/ 

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Error: Cannot open input file %s\n", argv[1]);
        return 1;
    }

    fptr = fopen(argv[2], "w");
    if (fptr == NULL) {
        printf("Error: Cannot open output file %s\n", argv[2]);
        fclose(yyin);
        return 1;
    }

    yyparse();

    if (n_error == 0) {
        traverse(root);
    }

    // Clean up arrays before exiting
    cleanup_arrays();

    fclose(yyin);
    fclose(fptr);
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

/****************** Scope handling *****************/ 

void scope_enter(){
    local_table = new_symtab(indent_counter, local_table);
    indent_counter++;
}

void scope_exit(){
    delete_symtab(local_table);
    indent_counter--;
}

/****************** Convert Data Type to String and viceversa *****************/ 

char * type_to_str(int type) {
    switch (type) {
        case DATA_TYPE_STRING:
            return strdup("string");
        case DATA_TYPE_FLOAT:
            return strdup("float");
        case DATA_TYPE_INT:
            return strdup("int");
        case DATA_TYPE_BOOL:
            return strdup("bool");
        case DATA_TYPE_NONE:
            return strdup("Type none");
        default:
            return strdup("Type not defined");
    }
}

// Debug print function
void debug_print(const char *msg, void *ptr) {
    printf("[DEBUG] %s: %p\n", msg, ptr);
}

void debug_token(const char *token_name, const char *token_value) {
    printf("[TOKEN] %s: '%s'\n", token_name, token_value);
}
