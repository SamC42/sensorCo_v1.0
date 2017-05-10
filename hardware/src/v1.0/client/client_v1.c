/*
 * This class handles setting up the bluetooth connection and 
 * parsing the output from the bluetooth connection
 *
*/
#include <stdio.h>
#include <unistd.h>  
#include <sys/socket.h> 
//#include <bluetooth/bluetooth.h>
//#include <bluetooth/rfcomm.h>
#include <string.h>
#include <stdbool.h>
#include "./socket_helpers/client_socketConn.c"
#include "./help/help_menu.h"
#include "./buff_logic/buff_read.c"
//#include "./socket_helpers/bluetoothSocketConnect.h"

  

int main(int argc, char *argv[])
{
    int test = 1;
    int sConn = 0; 
    if( argc == 1 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"") == 0){
        printHelpMenu();
        return 0;
 
    }
    
    char resultW, resultR;

    //Defines the Write Buffer
    int buffSize = 19;
    char buffer[buffSize];

    int c;
    char bufferOut[buffSize];

    bool quit = false;
    //Test socket to connect to a Socket on the computer
    if(strcmp(argv[1],"-s") == 0){
        test = 0;
        //Add in Test Socket
        sConn = sockConn();

    }
    if(strcmp(argv[1],"-u") == 0){
        test = 1;
        printf("Unlinking...");
        unlink("/tmp/mysocket");


    }
    // send a message
    if(sConn != 0 || test == 0){
       while(quit != true){
        printf("\nSend: ");
        //Get from Input Stream
        if(fgets(buffer,buffSize,stdin) !=NULL){

        } //Needs to be to so we have an ending to get past for loop
        while((c = getchar()) != '\n' && c != EOF);   
        //QUIT
        if(buffer[0] == 'q'){
            quit = true;
            break;
        }
        //NOT QUITTING
        else{
            //printf("BUFFER: %c \n", *buffer);
            resultW = write(sConn,buffer,buffSize); //Write 7 bytes

            if(resultW == 0){
                printf("Nothing was written\n");
            }
            if(resultW == -1){
                perror("Write Error: ");
            }
            if(resultW > 0)
            {
                resultR = read_buffer(sConn,bufferOut,buffSize);
                if(resultR == 0){
                    return 0;
                }
            }
            else
                printf("ERROR!!! Write Returned something other than 0, -1 or >0");
        }
                
       }
   }
    if(test == 0)
    {
        printf("Unlinking...");
        unlink("/tmp/mysocket");
    }
    else{
        printf("\nClosing connection...\n");
        close(sConn);
    }

    printf("Done\n");
    return 0;
}





