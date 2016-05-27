#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mysql_deal.h"
int mysql_connect( MYSQL_CONFIG* mysql_config , MYSQL *mysql)
{
    if(!mysql_real_connect(mysql,mysql_config->server,mysql_config->user,mysql_config->password,mysql_config->database,0,NULL,0)){
      fprintf(stderr,"无法连接到数据库，错误原因是:%s/n",mysql_error(mysql));
      return -1;
    }else{
        puts("数据库连接成功");
    }
    return 0;
}
void mysql_insert(char *sqlcmd,MYSQL* mysql)
{
    mysql_query(mysql,sqlcmd);
}
void mysql_my_query(char *sqlcmd,MYSQL* mysql)
{
    int t;
    MYSQL_RES *res;
    MYSQL_ROW row;
    //sprintf(sqlcmd,"%s",sqlcmd);
    t=mysql_real_query(mysql,sqlcmd,(unsigned int)strlen(sqlcmd));
    if(t){
        printf("查询数据库失败%s/n",mysql_error(mysql));
    }
    else {
        res=mysql_store_result(mysql);//返回查询的全部结果集
        while(row=mysql_fetch_row(res)){//mysql_fetch_row取结果集的下一行
            for(t=0;t<mysql_num_fields(res);t++){//结果集的列的数量
                printf("%s\t",row[t]);
            }
            printf("\n");
        }
    mysql_free_result(res);//操作完毕，查询结果集
    }
}
/*
int main(){
    MYSQL mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL_CONFIG mysql_config = {"localhost","root","mysql","test1"};
    mysql_init(&mysql);//初始化MYSQL标识符，用于连接
    mysql_connect( &mysql_config , &mysql);
    mysql_insert("insert into table_test (content) Values('eeee')",&mysql);
    mysql_my_query("select * from table_test",&mysql);
    mysql_close(&mysql);//关闭数据库连接
    mysql_library_end();//关闭MySQL库
    return EXIT_SUCCESS;
}
*/
