%option caseless
%{
    #include<stdio.h>
    #include"y.tab.h"
%}
%%
CREATE      return CREATE;
DATABASES   return DATABASES;
DATABASE    return DATABASE;
TABLE       return TABLE;
TABLES      return TABLES;
USE         return USE;
DROP        return DROP;
SHOW        return SHOW;
CHAR        return CHAR;
INT         return INT;
INSERT      return INSERT;
INTO        return INTO;
VALUES      return VALUES;
SELECT      return SELECT;
FROM        return FROM;
WHERE       return WHERE;
AND         return AND;
OR          return OR;
UPDATE      return UPDATE;
SET         return SET;
DELETE      return DELETE;


[0-9]+      { yylval.yych=strdup(yytext); return NUMBER;}
[A-Za-z][A-Za-z0-9_]* { yylval.yych=strdup(yytext); return ID;}
"*"|"."|"="|":"|";"|"("|")"|">"|"<"|"!"|","  { return yytext[0];}
\'
\n
[ \t]+
%%