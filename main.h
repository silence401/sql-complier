#ifndef _MAIN_
#define _MAIN_

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
struct TableItems{
    char *content;
    char *type;
    struct TableItems *next_item;
};
struct Table
{
      char *table_name;
      struct TableItems *items;
};
struct Condition
{
    char *left;
    char *right;
    char cmp;
    char op;
    struct Condition *next_con;
};
void CreateTable(struct Table *table);
void DropTable(char *TableName);
void GetDB();
void ShowDB();
void ShowTables();
void UseDB();
void CeatrDB();
void DropDB();
void GetTable();
void InsertValue(char *TableName,struct TableItems *items);
void InsertByRow(char *TableName,struct TableItems *itemname,struct TableItems *items);
void SelectAll(char *TableName);
void SelectByCol(char *TableName,struct TableItems *itemname);
void SelectWhere1(char *TableName,struct Condition *con,struct TableItems *rowsname);
void SelectWhere2(char *TableName,struct Condition *con);
int conok(char (*rowname)[100],char (*row)[100],int cols,struct Condition *con);
void UpdateTable(char *TableName,struct TableItems *items,struct Condition *con);
#endif