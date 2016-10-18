// Client Server Model for Raspberry Pi - Arduino


Currently the PC is being used as a client and the bluetooth module is serving as the server. This is version 1.0.

In version 2.0: The server should create the socket, bind the connection to a serial port then listen and accept for the arduino.

Functionality should be coded in the Arduino so the it becomes the client and uses 'connect' to attach to PC. This 
can be done with a button to search and connect for the home base, which will be hard coded for now. 

Server - PC (later Rpi)			|	Client - Arduino

Create

bind 

listen 							|	Connect

accept 

send 							|	Receive

Receive							|	Send
