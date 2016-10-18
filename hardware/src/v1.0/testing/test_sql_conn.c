/*
Testing SQl Connection 
Files: connect_sql.c connect_sql.h
*/

#include "./sql/connect_sql.h"

int main(){
	int *return_val = 0;
	printf("Testing Connection\n");
	sql_test_conn();
	printf("\nTesting Update Door Sensor to a value of 1...\n");
	return_val = update_door(1);
	printf("\nFinished Return value: %i\n",*return_val);
	
}
