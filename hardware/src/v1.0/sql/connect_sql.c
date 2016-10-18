//This Class is to Connect to the MYSQL database hosted at logproj.com

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "connect_sql.h"

static MYSQL conn;
static char *host = "mysql.logproj.com";
static char *user = "samc123";
static char *password= "samDF33"; 
static char *database= "logprojmembers";
static MYSQL_RES *result;
char str[1024];
static int status;

int sql_test_conn(){
	

	
	mysql_init(&conn);
	
	if(!mysql_real_connect(&conn, host, user, password, database, 0, NULL, 0)){
		printf("FAIL: %s", mysql_error(&conn));
		return 0;
	}
	else{
		printf("Successfully Logged in!\n");
	}
	//Test to ensure it works
	//Get SQl info
	sprintf(str,"SELECT Bookmark1,Bookmark2,Bookmark3,Bookmark4,Bookmark5 FROM bookmarks");
	mysql_query(&conn,str);
	//Store the Result
	result = mysql_store_result(&conn); //Should equal 12
	printf("Test Passed if Rows: %i = 12\n", (int)mysql_num_rows(result));
	mysql_free_result(result);

	//Test to Set the Status to Open
	//int st = 3;
	//status = *update_door(st);
	//printf("Door is: %i\n",status);
	return 1;
}


int *update_door(int i){
	mysql_init(&conn);
	
	if(!mysql_real_connect(&conn, host, user, password, database, 0, NULL, 0)){
		printf("FAIL: %s", mysql_error(&conn));
		return 0;
	}
	else{
		printf("Logged in! ");
	}
	int *ret_value;
	int errNum = -1;
	if(i == 1){
		//Change status to OPEN = 1
		sprintf(str,"UPDATE `sensors_in` SET `sensorType`='DOOR',`Data`=1");
		mysql_query(&conn,str);
		ret_value = &i;		
		printf("Updated\n");
	}
	else if(i == 0){
		//Change status to CLOSED = 0
		sprintf(str,"UPDATE `sensors_in` SET `sensorType`='DOOR',`Data`=0");
		mysql_query(&conn,str);
		ret_value = &i;
		printf("Updated\n");
	}
	else{
		printf("Nothing received\n");
		ret_value = &errNum;
	}
	return ret_value;

}


