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

#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)


int main(int argc, char **argv[])
{
		int test;
 		test = 0;
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
        strcpy(local.sun_path, "/tmp/mysocket1111111");
		//Connect to Server
        status = connect(s, (struct sockaddr *)&local, sizeof(local));            
      
      
        char *buffer = "Hi my name is sam";
		//write()
        write(s,buffer,strlen(buffer));
        close(s);
		unlink("/tmp/mysocket111111");

}