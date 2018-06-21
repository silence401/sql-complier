/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
#line 27 "sql.y" /* yacc.c:1909  */

    char * yych;
    struct TableItems  *item_type;
    struct Table       *table_type;
    struct Condition   *con_type;

#line 111 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
