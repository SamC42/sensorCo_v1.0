/*
 * This class handles setting up the bluetooth connection and 
 * parsing the output from the bluetooth connection
 *
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <string.h>
#include <stdbool.h>
#include "./socket_helpers/internalSocketConnect.c"
#include "./help/help_menu.h"
#include "./buff_logic/buff_read.h"
#include "./socket_helpers/bluetoothSocketConnect.h"



int main(int argc, char *argv[])
{
    int test = 1;
    int sConn = 0;
    int loopFlag = 0;
    if( argc == 1 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"") == 0){
        //Input help menu print function
        printHelpMenu();
        //clientTracking(strIn); //Need to make a header and include header
        return 0;

    }
    if(strcmp(argv[1],"-s") == 0 || strcmp(argv[1],"-sl") == 0){

        if( strcmp(argv[1],"-sl") == 0)
        {
            loopFlag = 1;
        }
        sConn = bluetoothConnect();
        if(sConn == 0){
            return 0;
        }   
    }
    
    char resultW, resultR;
    char *buffer;
    buffer = malloc(sizeof(char));
    int c;
    char *bufferOut;
    bufferOut = malloc(1); //size of a char = 1 byte
    int cntTime = 0;
    bool quit = false;
    //Test socket to connect to a Socket on the computer
    if(strcmp(argv[1],"-t") == 0){
        test = 0;
        //Add in Test Socket
        sConn = sockConn();

    }
    if(strcmp(argv[1],"-u") == 0){
        test = 1;
        printf("Unlinking...");
        unlink("/tmp/mysocket11111111");


    }
    // send a message
    if(sConn != 0 || test == 0){
       while(quit != true){
        printf("\nSend: ");
        
        if(loopFlag == 0){
            fgets(buffer,2,stdin); //Needs to be to so we have an ending to get past for loop
            while((c = getchar()) != '\n' && c != EOF);   
           }
        else if(loopFlag == 1){
            *buffer = 'g';
            printf("g\n");
            sleep(3);
            if(cntTime == 5){
                *buffer = 'q';
            }
            else 
                cntTime += 1;
        }
            //QUIT
            if(*buffer == 'q'){
                quit = true;
                break;
            }
            //NOT QUITTING
            else{
                //printf("BUFFER: %c \n", *buffer);
                resultW = write(sConn,buffer,1); //read 1 byte
                //clientTracking(buffer);
                if(resultW == 0){
                    printf("Nothing was written\n");
                }
                if(resultW == -1){
                    perror("Write Error: ");
                }
                if(resultW > 0)
                {
                    resultR = read_buffer(sConn,bufferOut,1);
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
        unlink("/tmp/mysocket11111111");
    }
    else{
        printf("\nClosing connection...\n");
        close(sConn);
    }

    printf("Done\n");
    return 0;
}





