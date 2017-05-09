CC=gcc
CFLAGS=`pkg-config --cflags` -g -Wall

LIBS= -lmongoc-1.0 -lbson-1.0 -lcjson
INC= -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/libbson-1.0 -I/usr/local/include/cjson
Server: server_v1.c
	$(CC) $(CFLAGS) -o Server server_v1.c $(LIBS) $(INC)
 
