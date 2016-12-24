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
        int buffSize = 19; // Length of bufferIn in = 6
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
                       printf("RES:%s \n",printPacket(bufferIn));
                       write(sockFd,"eeeeeeeeeeeeeeeeee",buffSize);
                }
                // Insert Command Received
                if(bufferIn[0] == 'i'){ //0 right now for clarity 14
                    printf("Instr: i\n");
                    char *id,*val,*cInstr,*cData,*sInstr,*sData;
                    id = malloc(4);
                    val = malloc(4);
                    cInstr = malloc(4);
                    cData = malloc(4);
                    sInstr = malloc(4);
                    sData = malloc(4);

                    id = getId(bufferIn);
                    val = getVal(bufferIn);
                    cInstr = getCInstr(bufferIn);
                    cData = getCData(bufferIn);
                    sInstr = getSInstr(bufferIn);
                    sData = getSData(bufferIn);
                    
                    char *name, value[1];
                    strncpy(name,bufferIn,1);

                    name[1] = '\0';
                    strncpy(value,bufferIn+1,1);
                    value[1] = '\0';

                    insertSensor(id, val, cInstr, cData, sInstr, sData);

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
                else                       
                        write(sockFd,"ssssssssssss",buffSize);
                }

        printf("\nClosing connection...\n");
        printf("Unlinking...");
        unlink("/tmp/mysocket");
        printf("Done\n");
        socket_close();
        return 0;
}
