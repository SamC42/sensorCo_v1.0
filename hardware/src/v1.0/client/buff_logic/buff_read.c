/*
This file handles the reading logic for the buffer

*/
//#include "../mongoDB_c/mongodb_api.c"
//#include "buff_read.h"
/*
Inputs: 
	File Descriptor
	Buffer 
	Byte length
*/


int read_buffer(int file_d, char* buffer, int count_size){
	int readIn;
    int retVal;
	readIn = read(file_d,buffer,count_size);
	if(readIn == 0){
    	printf("End Of File, Nothing was read (buff_read.c/ln 19)\n");
        retVal = 0;
    }
    if(readIn == -1){
        perror("Read Error");
        retVal = 0;
    }
    if(readIn > 0){
        //Closed
    	if(buffer[0] == '0'){ //bufferOut is a address
    	//check if value pointed to by bufferOut == 3
        	printf("Recv: %s \n",buffer);
            //update_door(0); --MONGO DB
            //int num;
            //num = "0";
            //insertSensor(num, "Name 0");
            retVal = 1;
        }
        //Open
        else if(buffer[0] == '1'){
            printf("Recv: %s \n",buffer);
            //update_door(1);
            //int num;
            //num = "1";
            //insertSensor(num,"Name 1");
            retVal = 1;
        }
        else if(*buffer == 'i'){
            //int num = "v";
            //insertSensor(num,"Name");
        }
        else{
            printf("Recv: %s \n ",buffer);
            retVal = 1;
        }
    }
    else{
        printf("Read Error !> 0: %i \n",readIn);
        retVal = 0;
    }
    return retVal;
}