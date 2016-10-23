/*
This file handles the reading logic for the buffer

*/
#include "../mongoDB_c/mongodb_api.c"
//#include "buff_read.h"
/*
Inputs: 
	File Descriptor
	Buffer 
	Byte length
*/


int read_buffer(int file_d, char *buffer, int count_size){
	int readIn;
	readIn = read(file_d,buffer,1);//read 1 byte
	if(readIn == 0){
    	printf("End Of File, Nothing was read (buff_read.c/ln 19)\n");
        return 0;
    }
    if(readIn == -1){
        perror("Read Error");
        return 0;
    }
    if(readIn > 0){
        //Closed
    	if(*buffer == '0'){ //bufferOut is a address
    	//check if value pointed to by bufferOut == 3
        	printf("Recv: %c \n",*buffer);
            //update_door(0); --MONGO DB
            int num;
            num = "0";
            insert_mdb(num);
            return 1;
        }
        //Open
        else if(*buffer == '1'){
            printf("Recv: %c \n",*buffer);
            //update_door(1);
            int num;
            num = "1";
            insert_mdb(num);
            return 1;
        }
        else{
            printf("Recv: %c \n ",*buffer);
            return 1;
        }
        }
    }