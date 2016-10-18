/*
This file handles the reading logic for the buffer

*/

#include "buff_read.h"
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
    	if(*buffer == 3){ //bufferOut is a address
    	//check if value pointed to by bufferOut == 3
        	printf("Recv: %c \n",*buffer);
            //update_door(0); --MONGO DB
            return 1;
        }
        //Open
        else if(*buffer == 1){
            printf("Recv: %c \n",*buffer);
            //update_door(1);
            return 1;
        }
        else{
            printf("Recv no 1 or 0: %c \n ",*buffer);
            return 1;
        }
        }
    }