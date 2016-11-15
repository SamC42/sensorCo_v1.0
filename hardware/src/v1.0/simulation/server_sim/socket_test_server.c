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
#include "../../mongoDB_c/mongodb_api.c"

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)


int main(int argc, char **argv[])
{
        unlink("/tmp/mysocket");	
        int cfd;
        socklen_t peer_addr_size;
        struct sockaddr_un local, peer_addr;        
        int s;

        memset(&local, 0, sizeof(struct sockaddr_un));
        // allocate a socket
        s = socket(AF_UNIX, SOCK_STREAM, 0);
        // set the connection parameters (who to connect to)
        local.sun_family = AF_UNIX;
        strcpy(local.sun_path, "/tmp/mysocket");
		//Bind name to a socket
	if (bind(s, (struct sockaddr *) &local, sizeof(struct sockaddr_un)) == -1)
		handle_error("bind");
        // Listen
        if(listen(s,50) == -1 )
                handle_error("listen");
        // Accept the Connection
        peer_addr_size = sizeof(struct sockaddr_un);
        cfd = accept(s, (struct sockaddr *)&peer_addr, &peer_addr_size);
        if(cfd == -1)
                handle_error("Accept");
        else
        puts("Accepted! Incoming data...");
                
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
                //Write to a log file
                
                printf("Recv'd from Client: %s \n",buffer);        

                if(endRead < 0)
                        handle_error("SOCKET READING ERR");
                if(buffer[0] == 'q')
                {
                        printf("Quitting\n");
                        quit = true;
                }
                else if(buffer[0] == '1'){
                        printf("In Buff = 1");
                        char *name, value[1];
                        strncpy(name,buffer,1);
                        name[1] = '\0';
                        strncpy(value,buffer+1,1);
                        value[1] = '\0';
                        insertSensor(name,value);
                        write(cfd,"111",3);
                }
                
                else if(buffer[0] == 'r'){
                        char *name0, value0[1];
                        strncpy(name0,buffer,1);
                        name0[1] = '\0';
                        strncpy(value,buffer+1,1);
                        value[1] = '\0';
                        insertSensor(name0,"1");
                        write(cfd,"000",3);
                }
                else if(buffer[0] =='i'){
                        char *name, value[1];
                        strncpy(name,buffer,1);
                        name[1] = '\0';
                        strncpy(value,buffer+1,1);
                        value[1] = '\0';
                        insertSensor(name,value);
                        write(cfd,"iii",3);
                        insertSensor("i","i");
                }
                else if(buffer[0] =='g'){
                        //Get the list of with name
                        //getCollSensors();
                        write(cfd,"ggg",3);

                }
                else if (buffer[0] =='u'){
                        write(cfd,"uuu",3);

                }
                else                       
                        write(cfd,"Wee",3);
                }

        printf("\nClosing connection...\n");
        printf("Unlinking...");
        unlink("/tmp/mysocket");
        printf("Done\n");
        close(s);
        return 0;
}
