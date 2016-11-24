/*
	This file creates the packet parser for the Server

*/
#include <stdio.h>
/* Method to Determine the Id
 * Args: Id in hex
 * Return: id as an decimal
 * Range is from 0x000 -0xFFF
 */


int getId(char* idIn){

	int fromId 	= 0;
	int toId 	= 1 - fromId;
    printf("Status ID: 			");
    for(int i=fromId; i<toId; i++){
            printf("%0x",idIn[i]);
            }
    printf("\n");
}
/* Method to Determine the Status
 * Args: Status in hex
 * Returns: status as a decimal
 * Range is from 0x0 - 0x1
 */
int getVal(char* valIn){
	int fromVal	= 1;
	int toVal	= 2;;
    printf("Sensor Value: 			");
	for(int i=1; i<2; i++){
           printf("%d",valIn[i]);
        }
    printf("\n");
	
}

/* Method to Determine the Value
 * Args: Value in hex
 * Returns: Value as a decimal
 * Range is from 0x000 - 0xFFF
 */
int getCInstr(char* cInstrIn){
	int fromCInstr = 2;
	int toCInstr   = 3;	
	printf("Controller Instruction: 	");
    for(int i=fromCInstr; i<toCInstr; i++){
                printf("%c",cInstrIn[i]);
            }
	printf("\n");
	
}
int getCData(char* cDataIn){
	int fromCData  = 3;
	int toCData    = 4;
	printf("Controller Data:		");
    for(int i=fromCData; i<toCData; i++){
            printf("%c",cDataIn[i]);
        }
	printf("\n");
}
int getSInstr(char* sInstrIn){
	int fromSInstr = 4;
	int toSInstr   = 5;
	printf("Sensor Instruction: 		");
    for(int i=fromSInstr; i<toSInstr; i++){
            printf("%c",sInstrIn[i]);
        }
	printf("\n");
}

int getSData(char* sDataIn){
	int fromSData  = 5;
	int toSData    = 6;
	printf("Sensor Data: 			");
    for(int i=fromSData; i<toSData; i++){
            printf("%c",sDataIn[i]);
            }
	printf("\n");

}

int printPacket(char* bufferIn){
	printf("--------------Packet--------------\n");
    getId(bufferIn);
    getVal(bufferIn);
    getCInstr(bufferIn);
    getCData(bufferIn);
    getSInstr(bufferIn);
    getSData(bufferIn);
    printf("--------------Packet--------------\n");
}



