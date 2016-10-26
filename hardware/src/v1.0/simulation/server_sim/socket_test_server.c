/*
 * This class tests interprocess socket communication
 *
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
		
                int cfd;
                socklen_t peer_addr_size;
        struct sockaddr_un local, peer_addr;        
        int s;

        memset(&local, 0, sizeof(struct sockaddr_un));
        // unlink the socket in case it exited with err last run
        // commented out so as to work with socat
        // unlink("/dev/pts/9");	
        // allocate a socket
        s = socket(AF_UNIX, SOCK_STREAM, 0);
        // set the connection parameters (who to connect to)
        local.sun_family = AF_UNIX;
        strcpy(local.sun_path, "/tmp/mysocket11111111");
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
                

        char *buffer;
        buffer = malloc(sizeof(char));
        int endRead;
        int *outbuff;
        bool quit;
        quit = false;
        while(quit != true){
                quit = false;
                endRead = read(cfd,buffer,sizeof(buffer));
                //Write to a log file
                
                printf("Recv'd from Client: %c \n",*buffer);        

                if(endRead < 0)
                        handle_error("SOCKET READING ERR");
                if(*buffer == 'q')
                {
                        printf("Quitting\n");
                        quit = true;
                }
                else if(*buffer == '1'){
                        outbuff = "1";
                        insertSensor("1","Name 1");
                        write(cfd,outbuff,1);
                }
                else if(*buffer == '0'){
                        outbuff = "0";
                        insertSensor("0","Name 0");
                        write(cfd,outbuff,1);
                }
                else if(*buffer =='i'){
                        write(cfd,"i",1);
                        insertSensor("i","Name i");
                        sleep(1000);
                }
                else if(*buffer =='D'){

                }
                else
                        write(cfd,"N",1);
                }

        printf("\nClosing connection...\n");
        printf("Unlinking...");
        unlink("/tmp/mysocket11111111");
        printf("Done\n");
        close(s);
        return 0;
}
