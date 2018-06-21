%{
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
%}
%union
{
    char * yych;
    struct TableItems  *item_type;
    struct Table       *table_type;
    struct Condition   *con_type;
}
%token CREATE DROP DATABASES TABLE TABLES  USE DATABASE SHOW  DELETE INSERT INTO VALUES SELECT FROM WHERE UPDATE SET
%token <yych> ID NUMBER INT CHAR 
%type <item_type> items item values value upvalues upvalue
%type <table_type> createfunc
%type <con_type>  condition conditions
%left OR
%left AND 

%%
start: start statement|statement

statement:createfunc|showfunc|dropfunc|usedatabase|insertfunc|selectfunc|updataefunc|deletefunc

createfunc: CREATE DATABASE ID ';' {strcpy(database,$3); CreateDB();}
           |CREATE TABLE ID '(' items ')' ';'
            {
                $$=(struct Table *)malloc(sizeof(struct Table));
                $$->table_name=$3;
                $$->items=$5;
                CreateTable($$);
                
            }

items :     items ',' item
            {
                $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                $$->next_item =$1;
                $$->content=$3->content;
                $$->type=$3->type;
            }
            |item
            {
                 $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                 $$->next_item=NULL;
                 $$->type=$1->type;
                 $$->content=$1->content;
            }

item :      ID CHAR '('NUMBER ')'
            {
                
                $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                $$->content=$1;
                $$->type=$2;

            }
            | ID INT
            {
                $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                $$->content=$1;
                $$->type=$2;
            }

showfunc: SHOW DATABASES ';' {ShowDB();};
          |SHOW TABLES ';' {ShowTables();}
usedatabase : USE ID';'
              {
                  strcpy(database,$2);
                  UseDB();
              }
dropfunc : DROP DATABASE ID';' {strcpy(database,$3); DropDB();}
           |DROP TABLE ID ';'{DropTable($3);}

 insertfunc: INSERT INTO ID VALUES '(' values ')' ';'
              {
                  InsertValue($3,$6);
              }     
            |INSERT INTO ID '(' values ')' VALUES '(' values ')' ';'
             {
                 InsertByRow($3,$5,$9);
             }
              values: values','value
              {
                  $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                  $$->content=$3->content;
                  $$->next_item=$1;
              }
              |value 
              {
                    $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                    $$->content=$1->content;
                    $$->next_item=NULL;
              }    

              value: ID 
                     {
                        $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                        $$->content=$1;
                        $$->next_item=NULL;

                     }
                     |NUMBER
                     {
                          $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                         $$->content=$1;
                         $$->next_item=NULL;
                     }
selectfunc :  SELECT '*' FROM ID ';'
                {
                     SelectAll($4);
                }           
            |SELECT values FROM ID ';'
            {
                SelectByCol($4,$2);
            } 
            |SELECT '*' FROM ID WHERE conditions ';'
            {
                SelectWhere2($4,$6);
            }
            |SELECT values FROM ID WHERE conditions ';'
            {
                SelectWhere1($4,$6,$2);
            }
            conditions : conditions AND condition
                        {
                              $$=$3;
                              $$->next_con=$1;
                              $$->op='a';
                              
                        } 
                        |conditions OR condition
                         {

                              $$=$3;
                              $$->next_con=$1;
                              $$->op='o';
                         }
                        |condition
                        {
                            $$=$1;
                        }
                    
            condition: '(' condition ')' 
                         {
                             $$=$2;
                         }
                        | ID '>' NUMBER
                        {
                            $$=(struct Condition*)malloc(sizeof(struct Condition));
                            $$->left=$1;
                            $$->right=$3;
                            $$->cmp='>';
                            $$->next_con=NULL;
                        }
                        | ID '=' NUMBER
                          {
                            $$=(struct Condition*)malloc(sizeof(struct Condition));
                            $$->left=$1;
                            $$->cmp='=';
                            $$->right=$3;
                            $$->next_con=NULL;
                        }
                        | ID '<' NUMBER
                          {
                            $$=(struct Condition*)malloc(sizeof(struct Condition));
                            $$->left=$1;
                            $$->cmp='<';
                            $$->right=$3;
                            $$->next_con=NULL;
                        }
                        | ID '!''=' NUMBER
                          {
                            $$=(struct Condition*)malloc(sizeof(struct Condition));
                            $$->left=$1;
                            $$->cmp='!';
                            $$->right=$4;
                            $$->next_con=NULL;
                        }
                        | ID '=' ID
                          {
                            $$=(struct Condition*)malloc(sizeof(struct Condition));
                            $$->left=$1;
                            $$->cmp='=';
                            $$->right=$3;
                            $$->next_con=NULL;
                        }
                        | ID  '!''=' ID     
                          {
                            $$=(struct Condition*)malloc(sizeof(struct Condition));
                            $$->left=$1;
                            $$->cmp='!';
                            $$->right=$4;
                            $$->next_con=NULL;
                        }      
updataefunc : UPDATE ID SET upvalues WHERE conditions ';'
            {
                UpdateTable($2,$4,$6);

            }
            upvalues: upvalues ',' upvalue
                      {
                          $$=$3;
                          $$->next_item=$1;

                      }
                      | upvalue
                      {
                          $$=$1;
                      }
            upvalue: ID '=' NUMBER
                     {  
                        $$=(struct TableItems*)malloc(sizeof(struct TableItems)); 
                        $$->content=$3;
                        $$->type=$1;
                     }
                     |ID '=' ID
                     {
                         $$=(struct TableItems*)malloc(sizeof(struct TableItems));
                         $$->content=$3;
                         $$->type=$1;
                     }
deletefunc :DELETE FROM ID WHERE conditions ';'
            {
                 Delete($3,$5);
            }