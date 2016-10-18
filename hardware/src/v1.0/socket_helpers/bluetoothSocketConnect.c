/*
This file handles the Bluetooth Socket Connection

*/

#include "bluetoothSocketConnect.h"
#include <stdio.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int bluetoothConnect(){
	int sConn = 0;
	struct sockaddr_rc addr = { 0 };
    int n;
    char dest[18] = "98:D3:31:20:A5:68";
    int s, status;
    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );
    printf("Connecting to bluetooth...\n");
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));            
    if(status == 0){
        printf("Connection Successful! \n");
        sConn = s;
        return sConn;
    }
    else
    {
        perror("Connection Failed");
        close(s);
        return 0;
    }  



	
}
