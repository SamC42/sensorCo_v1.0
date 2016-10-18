#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>


int main(int argc, char **argv)
{
    struct sockaddr_rc addr = {0},loc_addr = {0}, rem_addr = {0};  
    char buf[1024] = {0};
    int s, client, bytes_read;
    socklen_t opt = sizeof(rem_addr);

    // Allocate the Socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    //bind socket to port 1 of the first available
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY;
    loc_addr.rc_channel = (uint8_t) 1;
    bind(s, (struct  sockaddr *)&loc_addr, sizeof(loc_addr));

    listen(s,1);


    client = accept(s, (struct sockaddr *)&rem_addr, &opt);
    ba2str(&rem_addr.rc_bdaddr, buf);
    fprintf(stderr, "Accepted connection from %s\n", buf);
    memset(buf, 0, sizeof(buf));

    bytes_read = read(client, buf, sizeof(buf));
    if(bytes_read > 0) {
        printf("Received [%s]\n",buf);
    }

    close(client);
    close(s);
    return 0;
}




