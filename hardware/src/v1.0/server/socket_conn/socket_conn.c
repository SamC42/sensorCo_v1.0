/*
 * This file handles connecting to the mysocket socket


*/
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

 
int socket_alloc(){
	int s = socket(AF_UNIX, SOCK_STREAM, 0);
	return s;
}
// allocate a socket

int socket_conn(){
	unlink("/tmp/mysocket");
	int cfd;
	int s;
	s= socket_alloc();
    socklen_t peer_addr_size;
    struct sockaddr_un local, peer_addr;        
    memset(&local, 0, sizeof(struct sockaddr_un));
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

	return cfd;
}


void socket_close(){
	close(socket_alloc());
	
}