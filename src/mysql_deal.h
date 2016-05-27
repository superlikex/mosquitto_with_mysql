#ifndef _MYSQL_DEAL_H_
#define _MYSQL_DEAL_H_

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mysql_deal.h"
typedef struct my_config{
    char *server ;//= "localhost",
    char *user   ;//= "root",
    char *password; //= "mysql",
    char *database;// = "test1",
}MYSQL_CONFIG;
int mysql_connect( MYSQL_CONFIG*,MYSQL *mysql);
void mysql_insert(char * ,MYSQL* );
void mysql_my_query(char *,MYSQL* );
#endif
