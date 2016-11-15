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


int main(int argc, char **argv[])
{
        int cfd = socket_conn();       
        int buffSize = 4;
        char buffer[buffSize];
        int wSize = sizeof(buffer);//Write Size
        int endRead;
        int *outbuff;
        bool quit;
        int sensor_id, sensor_status, sensor_value;
        quit = false;
        while(quit != true){
                quit = false;
                endRead = read(cfd,buffer,wSize);
                
                printf("Recv'd from Client: %s \n",buffer);        

                if(endRead < 0)
                        handle_error("SOCKET READING ERR");
                if(buffer[0] == 'q')
                {
                        printf("Quitting\n");
                        quit = true;
                }
                else if(buffer[0] == '1'){
                        
                        //char *name, value[1];
                        //strncpy(name,buffer,1);
                        //name[1] = '\0';
                        //strncpy(value,buffer+1,1);
                        //value[1] = '\0';
                        //insertSensor(name,value);
                        write(cfd,"111",3);
                }
                else if(buffer[0] =='i'){
                        //insertSensor(name,value);
                        write(cfd,"iii",3);
                        insertSensor("i","i");
                }
                else if(buffer[0] =='g'){
                        //Get the list of with name
                        //getCollSensors();
                        write(cfd,"ggg",3);

                }
                else if (buffer[0] =='u'){
                        updateSensor("name","value");
                        write(cfd,"uuu",3);

                }
                else                       
                        write(cfd,"Err",3);
                }

        printf("\nClosing connection...\n");
        printf("Unlinking...");
        unlink("/tmp/mysocket");
        printf("Done\n");
        socket_close();
        return 0;
}
