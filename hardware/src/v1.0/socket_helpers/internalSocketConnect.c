/*
 * This class handles connecting to a socket and passing the connection along
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include "internalSocketConnect.h"

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)


int sockConn(){      
        struct sockaddr_un local;        
        int s, status;

        memset(&local, 0, sizeof(struct sockaddr_un));
        // unlink the socket in case it exited with err last run
        // commented out so as to work with socat
        // unlink("/dev/pts/9");        
        // allocate a socket
        s = socket(AF_UNIX, SOCK_STREAM, 0);
        // set the connection parameters (who to connect to)
        local.sun_family = AF_UNIX;
        strcpy(local.sun_path, "/tmp/mysocket11111111");
                //Connect to Server
        status = connect(s, (struct sockaddr *)&local, sizeof(local));   
        if(status == 0){
                printf("Connect to Path: /tmp/mysocket11111111");
                return s;
        }
        else{
                printf("status: %i", status);
                perror("Connect");
                return 0;
        }
                
}
