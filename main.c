#include "main.h"
extern char database[100]; //current database
extern char rootdir[1024]; //root directory
void GetDB()// get the information of the database
{
    FILE* file;
    char name[1024];
    chdir(rootdir);
    file=fopen(".databases","r");
    if(file==NULL)
    {
        printf("open error\n");

    }
    while(fscanf(file,"%s",name)!=EOF)
    {
        printf("%s\n",name);
    }
    fclose(file);
    chdir(rootdir);
    printf(">>");
}
void CreateDB()//create a new database
{
    chdir(rootdir);
    if(mkdir(database,S_IRUSR|S_IWUSR|S_IXUSR)==-1)
    printf("***********create error database %s exits************\n",database);
    else 
    {
        FILE *file;
        file=fopen(".databases","a+");
        if(file==NULL)
        {
            printf("error\n");
            return;
        }
        else{
             fprintf(file,"%s\n",database);
             printf("***************succeed create database %s*****************8\n",database);
             fflush(file);
             fclose(file);
        }

    }
    strcpy(database,"\0");
    chdir(rootdir);
    printf(">>");
}
void DropDB()//drop a database
{
    chdir(rootdir);
    if(chdir(database)== -1)
    printf("database does not exit\n");
    else{
        char cmd[128]="rm -rf ";
        FILE *filein;
        FILE *fileout;
        char dbname[64]={0};
        chdir("..");
        strcat(cmd,database);
        system(cmd);
        system("mv .databases .databases.backup");
        filein=fopen(".databases.backup","r");
        fileout=fopen(".databases","w");
        while(fscanf(filein,"%s",dbname)!=EOF)
        {
            if(strcmp(dbname,database)!=0)
            {
                fprintf(fileout,"%s\n",dbname);
            }
        }
        
        fclose(filein);
        fclose(fileout);
        system("rm .databases.backup");
    printf("******************ucceed drop the database %s******************\n",database);
    }
    chdir(rootdir);
    printf(">>");
}
void ShowDB()
{
    chdir(rootdir);
    char dbname[60];
    FILE *file;
    file=fopen(".databases","r");
    while(fscanf(file,"%s",dbname)!=EOF){
        printf("%s\n",dbname);
    }
    fclose(file);
    printf(">>");
}
void UseDB()
{
    chdir(rootdir);
    if(chdir(database)==-1)
    {
        printf("***************database not exit!********************\n");
    }
    else
    {
        printf("*******************current database %s******************\n",database);
        chdir(rootdir);
    }
    printf("%s:",database);
    printf(">>");

}
void CreateTable(struct Table *table)
{

     struct TableItems *fitems;
     char row[100][100]={0};
     chdir(rootdir);
     if(chdir(database)==-1)
     {
         printf("*********************database not exit!*********************\n");
     }
     else
     { 
         FILE *ftables;
         ftables=fopen(".tables","a+");
         if(ftables==NULL)
         {
             printf("os error\n");
         }
         else
         {
            if(access(table->table_name,F_OK)!=-1)
            {
                printf("*********************table already exit*********************\n");
            }
            else
            {
                fprintf(ftables,"%s\n",table->table_name);
                fclose(ftables);
                fitems=table->items;
                FILE *ftable;
                ftable=fopen(table->table_name,"a+");
                if(ftable==NULL)
                printf("*********************os error*********************\n");
                else
                {
                       int cnt=0;
                       while(fitems!=NULL)
                       {
                            strcpy(row[cnt++],fitems->content);
                            fitems=fitems->next_item;

                       }
                       fprintf(ftable,"%d\n",cnt);
                       int i;
                       for(i=cnt-1;i>=0;i--)
                       fprintf(ftable,"%s\n",row[i]);
                       printf("*********************succeed create table: %s*********************\n",table->table_name);
                       fclose(ftable);

                }

                
            }
            chdir(rootdir);
         }

     }
     fitems=table->items;
     while(fitems!=NULL)
     {
         struct TableItems *tmp=fitems;
         fitems=fitems->next_item;
         free(tmp);
     }
     free(table);
     chdir(rootdir);
     printf("%s:",database);
     printf(">>");

}
void DropTable(char *TableName)
{
    chdir(rootdir);
    chdir(database);
    char tablename[100]={0};
    char cmd[64]={"rm "};
    system("mv .tables .tables.backup");  
    FILE *filein = fopen(".tables.backup","r");
    FILE *fileout=fopen(".tables","w");
    while(fscanf(filein,"%s",tablename)!=EOF)
    {
          if(strcmp(TableName,tablename)!=0)
          {
              fprintf(fileout,"%s\n",tablename);
          }
    }
    fclose(fileout);
    fclose(filein);
    system("rm .tables.backup");
    strcat(cmd,TableName);
    system(cmd);
    printf("*********************succeed drop table :%s*********************\n",TableName);
    printf("%s:",database);
    printf(">>");

}
void ShowTables()
{
    char tablename[100]={0};
     chdir(rootdir);
     chdir(database);
     FILE *file=fopen(".tables","r");
     while(fscanf(file,"%s",tablename)!=EOF)
     {
         printf("%s\n",tablename);
     }
     fclose(file);
    printf("%s:",database);
     printf(">>");
}
void InsertValue(char *TableName,struct TableItems *items)
{
    char row[100][100];
    chdir(rootdir);
    chdir(database);
    if(access(TableName,F_OK)==-1)
    printf("*********************Table not exit!*********************\n");
    else
    {
        FILE *ftable=fopen(TableName,"a+");
        struct TableItems *it=items;
        int rows;
        fscanf(ftable,"%d",&rows);
        int cnt=0;
        while(it!=NULL)
        {
          strcpy(row[cnt++],it->content);
          it=it->next_item;
        }
        if(cnt!=rows)
        {
            printf("*********************table rows don't match*********************\n");

        }
        else
        {
        int i;
        for(i=cnt-1;i>=0;i--)
        {
           fprintf(ftable,"%s\n",row[i]);
        }
        it=items;
        while(it!=NULL)
        {
            struct TableItems *tmp=it;
            it=it->next_item;
            free(tmp);
        }
        fclose(ftable);
        printf("*********************insert succeed*********************\n");
      }
    }
    printf("%s:",database);
    printf(">>");

}
void InsertByRow(char *TableName,struct TableItems *itemname,struct TableItems *items)
{
    char rowname[100][100]={0};
    char row[100][100]={0};
    char tablerow[100][100]={0};
    chdir(rootdir);
    chdir(database);
    if(access(TableName,F_OK)==-1)
    printf("table don't exit\n");
    else
    {
        struct TableItems *tmp=itemname;
        int rownum=0;
        while(tmp!=NULL)
        {
            strcpy(rowname[rownum++],tmp->content);
            tmp=tmp->next_item;
        }
        rownum=0;
        tmp=items;
        while(tmp!=NULL)
        {
            strcpy(row[rownum++],tmp->content);
            tmp=tmp->next_item;
        }
        FILE *ftable=fopen(TableName,"a+");
        int cnt=0,i=0,j=0,flag=0;
        fscanf(ftable,"%d",&cnt);
        for(i=0;i<cnt;i++)
        {
            fscanf(ftable,"%s",tablerow[i]);

        }
        for(i=0;i<cnt;i++)
        {
        flag=0;
        for(j=0;j<rownum;j++)
        {
          if(strcmp(rowname[j],tablerow[i])==0)
          {
              flag=1;
              fprintf(ftable,"%s\n",row[j]);
          }   
        }
          if(flag==0)
          {
              fprintf(ftable,"null\n");
          }
        
        }
      tmp=itemname;
      while(tmp!=NULL)
      {
          struct TableItems *t=tmp;
          tmp=tmp->next_item;
          free(t);
      }
      tmp=items;
      while(tmp!=NULL)
      {
          struct TableItems *t=tmp;
          tmp=tmp->next_item;
          free(t);
      }
      fclose(ftable);
      printf("*********************insert succeed*********************\n");
    }
    printf("%s:",database);
    printf(">>");
}
void SelectAll(char *TableName)
{
    char row[100]={0};
    chdir(rootdir);
    chdir(database);
    if(access(TableName,F_OK)==-1)
    printf("*********************table don't exit*********************\n");
    else
    {
        FILE *ftable=fopen(TableName,"r");
        int rows;
        fscanf(ftable,"%d",&rows);
        int i=0;
        for(i=0;i<50;i++)
        printf("-");
        printf("\n");
        for(i=0;i<rows;i++)
        {
            fscanf(ftable,"%s",row);
            printf("%-15s",row);
        }
        printf("\n");
        int cnt=0;
        while(fscanf(ftable,"%s",row)!=EOF)
        {
            if(cnt==rows)
            {
                cnt=0;
                printf("\n");
            }
            printf("%-15s",row);
            cnt++;
        }
        printf("\n");
        for(i=0;i<50;i++)
        printf("-");
        printf("\n");
        fclose(ftable);
    }
    printf("\n%s:>>",database);
}
void SelectByCol(char *TableName,struct TableItems *itemname)
{
    char rowname[100][100]={0};
    char row[100][100]={0};
    char tablerow[100][100]={0};
    char tmp[100]={0};
    chdir(rootdir);
    chdir(database);
    if(access(TableName,F_OK)==-1)
    printf("*********************table don't exit*********************\n");
    else
    {
        int i=0,j=0,k=0;
        FILE *ftable=fopen(TableName,"r");
        int rows=0;
        fscanf(ftable,"%d",&rows);
        struct TableItems *it=itemname;
        int cnt=0,cnt2=0;
        while(it!=NULL)
        {
            strcpy(rowname[cnt++],it->content);
            it=it->next_item;
        }
        for(i=0;i<rows;i++)
        {
            fscanf(ftable,"%s",tablerow[i]);

        }
        while(fscanf(ftable,"%s",tmp)!=EOF)
        {
            strcpy(row[cnt2++],tmp);
        }
        for(i=0;i<50;i++)
            printf("-");
            printf("\n");
        for(j=cnt-1;j>=0;j--)
        {
            printf("%-15s",rowname[j]);
        }
        printf("\n");
        for(i=0;i<cnt2/rows;i++)
        {
            for(j=cnt-1;j>=0;j--)
            {
                for(k=0;k<rows;k++)
                {
                    if(strcmp(tablerow[k],rowname[j])==0)
                    {
                           
                            printf("%-15s",row[i*rows+k]);
                    }
                }
            }
            printf("\n");
        }
        for(i=0;i<50;i++)
            printf("-");
            printf("\n");
        fclose(ftable);
        it=itemname;
        while(it!=NULL)
        {
            struct TableItems *temp=it;
            it=it->next_item;
            free(it);
        }

        
    }
    printf("%s:",database);
    printf(">>");
}
int conok(char (*rowname)[100],char (*row)[100],int cols,struct Condition *con)
{
    int ans=-1;
    char right[100]={0};
    char left[100]={0};
    char cmp;
    char op;
    char preop;
    struct Condition *tc=con;
    while(tc!=NULL)
    {
       strcpy(right,tc->right);
       strcpy(left,tc->left);
       cmp=tc->cmp;
       op=tc->op;
       int i=0;
       int flag=0;
       for(i=0;i<cols;i++)
       {
          if(strcmp(rowname[i],left)==0)
          {
              if(cmp=='=')
              {
                  if(strcmp(row[i],right)==0)
                    flag=1;
              }
              else if(cmp=='!')
              {
                  if(strcmp(row[i],right)!=0)
                  flag=1;
              }
              else if(cmp=='>')
              {
                  if(strcmp(row[i],right)>0)
                  flag=1;
              }
              else if(cmp='<')
              {
                  if(strcmp(row[i],right)<0)
                  flag=1;
              }
          }
         
       }
       if(ans==-1)
       {
           ans=flag;
       }
       else
       {
        if(preop=='o')
        {
         if(ans==0&&flag==0)
         ans=0;
         else 
         ans=1;
        }
        else if(preop=='a')
        {
           
                if(ans==1&&flag==1)
                ans=1;
                else 
                ans=0;
        }
        }
        preop=op;
        tc=tc->next_con;
    }
    return ans;
}
void SelectWhere1(char *TableName,struct Condition *con,struct TableItems *rowsname)
{
    char row[100][100]={0};
    char rowname[100][100]={0};
    char outcol[100][100]={0};
    chdir(rootdir);
    chdir(database);
    struct TableItems *it;
    struct Condition *tc;
    if(access(TableName,F_OK)==-1)
    printf("*********************table not exit*********************\n");
    else
    {
        int rows;
        int i=0,j=0,k=0;
        FILE *ftable=fopen(TableName,"r");
        fscanf(ftable,"%d",&rows);
        if(rows==0)
        {
            printf("*********************no thing in table*********************\n");
        }
        else
        {
            for(i=0;i<50;i++)
            printf("-");
            printf("\n");
            for(i=0;i<rows;i++)
            fscanf(ftable,"%s",rowname[i]);
            int cnt1=0,cnt2=0;
            while(fscanf(ftable,"%s",row[cnt1++])!=EOF)
            {

            }
            it=rowsname;
            while(it!=NULL)
            {
                strcpy(outcol[cnt2++],it->content);
                it=it->next_item;
            }
            for(i=cnt2-1;i>=0;i--)
            printf("%-15s",outcol[i]);
            printf("\n");
            for(i=0;i<cnt1/rows;i++)
            {
            if(conok(rowname,row+(i*rows),rows,con))
            {
                    for(j=cnt2-1;j>=0;j--)
                    {
                        for(k=0;k<rows;k++)
                        {
                            if(strcmp(rowname[k],outcol[j])==0)
                            printf("%-15s",row[i*rows+k]);
                        }
                    }
                printf("\n");
            }
            }
            for(i=0;i<50;i++)
            printf("-");
            printf("\n");
        }
        fclose(ftable);
        
    }
    tc=con;
    while(tc!=NULL)
    {
        struct Condition *tmp=tc;
        tc=tc->next_con;
        free(tmp);
    }
    it=rowsname;
    while(it!=NULL)
    {
        struct TableItems *tmp=it;
        it=it->next_item;
        free(tmp);
    }
    printf("%s:",database);
    printf(">>");

}
void SelectWhere2(char *TableName,struct Condition *con)
{
    char row[100][100]={0};
    char rowname[100][100]={0};
    chdir(rootdir);
    chdir(database);
    struct TableItems *it;
    struct Condition *tc;
    if(access(TableName,F_OK)==-1)
    printf("table not exit\n");
    else
    {
        int rows;
        int i=0,j=0,k=0;
        FILE *ftable=fopen(TableName,"r");
        fscanf(ftable,"%d",&rows);
        for(i=0;i<rows;i++)
        fscanf(ftable,"%s",rowname[i]);
        int cnt1=0,cnt2=0;
        while(fscanf(ftable,"%s",row[cnt1++])!=EOF)
        {

        }
        for(i=0;i<50;i++)
        printf("-");
        printf("\n");
        for(i=0;i<rows;i++)
        printf("%-15s",rowname[i]);
        printf("\n");
        for(i=0;i<cnt1/rows;i++)
        {
           if(conok(rowname,row+(i*rows),rows,con))
           {
            for(k=0;k<rows;k++)
            printf("%-15s",row[i*rows+k]);
            printf("\n");
           }
        }
        for(i=0;i<50;i++)
        printf("-");
        printf("\n");
     fclose(ftable);
    }
    tc=con;
    while(tc!=NULL)
    {
        struct Condition *tmp=tc;
        tc=tc->next_con;
        free(tmp);
    }
    printf("%s:",database);
    printf(">>");

}
void UpdateTable(char *TableName,struct TableItems *items,struct Condition *con)
{
    char rowname[100][100]={0};
    char row[100][100]={0};
    char newrow[100][100]={0};
    chdir(rootdir);
    chdir(database);
    struct TableItems *it;
    struct Condition *tc;
    if(access(TableName,F_OK)==-1)
    printf("table not exit\n");
    else
    { 
        int rows;
        int i=0,j=0,k=0,cnt1=0;
        FILE *ftable=fopen(TableName,"r");
        fscanf(ftable,"%d",&rows);
        for(i=0;i<rows;i++)
        fscanf(ftable,"%s",rowname[i]);
        while(fscanf(ftable,"%s",row[cnt1++])!=EOF)
        {

        }
        for(i=0;i<cnt1/rows;i++)
        {
           if(conok(rowname,row+(i*rows),rows,con))
           {
              it=items;
              while(it!=NULL)
              {
                  printf("%s\n",it->type);

                  for(k=0;k<rows;k++)
                  {
                      if(strcmp(rowname[k],it->type)==0)
                      {
                          
                          strcpy(row[i*rows+k],it->content);
                      }
                  }
                  it=it->next_item;
              }
           }
        }
     for(i=0;i<cnt1;i++)
     printf("%s\n",row[i]);
     fclose(ftable);
     ftable=fopen(TableName,"w");
     fprintf(ftable,"%d\n",rows);
     for(i=0;i<rows;i++)
     fprintf(ftable,"%s\n",rowname[i]);
     for(i=0;i<cnt1;i++)
     fprintf(ftable,"%s\n",row[i]);
     fclose(ftable);
     printf("*********************succeed update table:%s*********************\n",TableName);
    }
    tc=con;
    while(tc!=NULL)
    {
        struct Condition *tmp=tc;
        tc=tc->next_con;
        free(tmp);
    }
    it=items;
    while(it!=NULL)
    {
        struct TableItems *tmp=it;
        it=it->next_item;
        free(tmp);
    }
    printf("%s:",database);
    printf(">>");

     
}
void Delete(char *TableName,struct Condition *con)
{
    char row[100][100]={0};
    char rowname[100][100]={0};
    chdir(rootdir);
    chdir(database);
    struct TableItems *it;
    struct Condition *tc;
    if(access(TableName,F_OK)==-1)
    printf("*********************table not exit*********************\n");
    else
    {
        int rows;
        int i=0,j=0,k=0;
        FILE *ftable=fopen(TableName,"r");
        fscanf(ftable,"%d",&rows);
        for(i=0;i<rows;i++)
        fscanf(ftable,"%s",rowname[i]);
        int cnt1=0,cnt2=0;
        while(fscanf(ftable,"%s",row[cnt1++])!=EOF)
        {

        }
        fclose(ftable);
        ftable=fopen(TableName,"w");
        ftable=fopen(TableName,"w");
        fprintf(ftable,"%d\n",rows);
        for(i=0;i<rows;i++)
        fprintf(ftable,"%s\n",rowname[i]);
        for(i=0;i<cnt1/rows;i++)
        {
           if(conok(rowname,row+(i*rows),rows,con)==0)
           {
            for(k=0;k<rows;k++)
            fprintf(ftable,"%s\n",row[i*rows+k]);
           }
        }
     printf("*********************succeed delete!*********************\n");
     fclose(ftable);
    }
    tc=con;
    while(tc!=NULL)
    {
        struct Condition *tmp=tc;
        tc=tc->next_con;
        free(tmp);
    }
    printf("%s:",database);
    printf(">>");
}
