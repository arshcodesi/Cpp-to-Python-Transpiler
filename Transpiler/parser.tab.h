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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    ID = 261,                      /* ID  */
    INT_NUMBER = 262,              /* INT_NUMBER  */
    FLOAT_NUMBER = 263,            /* FLOAT_NUMBER  */
    INT = 264,                     /* INT  */
    FLOAT = 265,                   /* FLOAT  */
    STRING = 266,                  /* STRING  */
    BOOL = 267,                    /* BOOL  */
    LPAR = 268,                    /* LPAR  */
    RPAR = 269,                    /* RPAR  */
    LBRACE = 270,                  /* LBRACE  */
    RBRACE = 271,                  /* RBRACE  */
    COLON = 272,                   /* COLON  */
    COMMA = 273,                   /* COMMA  */
    DOT = 274,                     /* DOT  */
    BRACKETS = 275,                /* BRACKETS  */
    RETURN = 276,                  /* RETURN  */
    COUT = 277,                    /* COUT  */
    CIN = 278,                     /* CIN  */
    STRING_V = 279,                /* STRING_V  */
    BOOL_V = 280,                  /* BOOL_V  */
    FOR = 281,                     /* FOR  */
    FUNCTION = 282,                /* FUNCTION  */
    CLASS = 283,                   /* CLASS  */
    MAIN = 284,                    /* MAIN  */
    PRIVATE = 285,                 /* PRIVATE  */
    PUBLIC = 286,                  /* PUBLIC  */
    UNKNOWN = 287,                 /* UNKNOWN  */
    EQ = 288,                      /* EQ  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    ADD = 291,                     /* ADD  */
    SUB = 292,                     /* SUB  */
    MUL = 293,                     /* MUL  */
    DIV = 294,                     /* DIV  */
    GT = 295,                      /* GT  */
    LT = 296,                      /* LT  */
    GE = 297,                      /* GE  */
    LE = 298,                      /* LE  */
    EEQ = 299,                     /* EEQ  */
    NE = 300,                      /* NE  */
    INC = 301,                     /* INC  */
    DEC = 302,                     /* DEC  */
    LSHIFT = 303,                  /* LSHIFT  */
    RSHIFT = 304                   /* RSHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union yystype YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
