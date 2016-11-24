/*
 * This class tests interprocess socket communication and the mongdb insert and update
 * If you input from client, a 1xx then you can test the insert mongdb     
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./mongoDB_c/mongodb_api.c"
#include "./socket_conn/socket_conn.c"
#include "./packets/packet_parser.c"


int main(int argc, char **argv[])
{
        int sockFd = socket_conn();

        //Define the bufferIn that will accept the data packet with length of 127 bytes       
        int buffSize = 7; // Length of bufferIn in = 6
        char bufferIn[buffSize];
        
        int readRes;
        bool quit = false; //Loop Lookinf for q to exit
        int sensor_id, sensor_status, sensor_value;

        while(quit != true){

                quit = false;
                readRes = read(sockFd,bufferIn,buffSize);
                printf("Naked Data from Client: %s \n",bufferIn);        

                if(readRes < 0)
                        handle_error("SOCKET READING ERR");
                if(bufferIn[0] == 'q')
                {
                        printf("Quitting\n");
                        quit = true;
                }
                if(bufferIn[0] == 'e'){
                       printPacket(bufferIn);
                        write(sockFd,"eeeeee",buffSize);
                }
                
                /*else if(bufferIn[0] == '1'){
                        
                        //char *name, value[1];
                        //strncpy(name,bufferIn,1);
                        //name[1] = '\0';
                        //strncpy(value,bufferIn+1,1);
                        //value[1] = '\0';
                        //insertSensor(name,value);
                        write(sockFd,"111",3);
                }
                else if(bufferIn[0] =='i'){
                        //insertSensor(name,value);
                        write(sockFd,"iii",3);
                        insertSensor("i","i");
                }
                else if(bufferIn[0] =='g'){
                        //Get the list of with name
                        //getCollSensors();
                        write(sockFd,"ggg",3);

                }
                else if (bufferIn[0] =='u'){
                        updateSensor("name","value");
                        write(sockFd,"uuu",3);

                }*/
                //else                       
                //        write(sockFd,"Err",3);
                }

        printf("\nClosing connection...\n");
        printf("Unlinking...");
        unlink("/tmp/mysocket");
        printf("Done\n");
        socket_close();
        return 0;
}
