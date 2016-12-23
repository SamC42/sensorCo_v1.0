/*
	This file creates the packet parser for the Server

*/
#include <stdio.h>
/* Method to Determine the Id
 * Args: Id in int
 * Return:
 * Range is from 0-32767
 */


char* getId(char* idIn, char cmd){

	int fromId 	= 0;
	int toId 	= 3;
    char *res;
    res = malloc(3);
    printf("Status ID: 			");
    for(int i=fromId; i<toId; i++){
            printf("%c",idIn[i]);
        //if(cmd == 'n'){
            res[i] = idIn[i];
        //}   
    }
    //if(cmd == 'n'){
        res[3] = '\0';
        return res;
    //}
}
/* Method to Determine the Value
 * Args: Value as int
 * Returns: 
 * 
 */
int getVal(char* valIn){
	int fromVal	= 3;
	int toVal	= 6;
    printf("Sensor Value: 			");
	for(int i=fromVal; i<toVal; i++){
           printf("%c",valIn[i]);
        }
    printf("\n");
	
}

/* Method to Determine the Controller Instruction
 * Args: Value in hex
 * Returns: Value as a decimal
 * Range is from 0x000 - 0xFFF
 */
int getCInstr(char* cInstrIn){
	int fromCInstr = 6;
	int toCInstr   = 9;	
	printf("Controller Instruction: 	");
    for(int i=fromCInstr; i<toCInstr; i++){
                printf("%c",cInstrIn[i]);
            }
	printf("\n");
	
}
/* Method to determine the controller data
*/
int getCData(char* cDataIn){
	int fromCData  = 9;
	int toCData    = 12;
	printf("Controller Data:		");
    for(int i=fromCData; i<toCData; i++){
            printf("%c",cDataIn[i]);
        }
	printf("\n");
}
/*	Method to determine the Sensor Instruction (Recieving Instr)

*/
int getSInstr(char* sInstrIn){
	int fromSInstr = 12;
	int toSInstr   = 15;
	printf("Sensor Instruction: 		");
    for(int i=fromSInstr; i<toSInstr; i++){
            printf("%c",sInstrIn[i]);
        }
	printf("\n");
}
/* Method to determine the Sensor's data from the instruction

*/
int getSData(char* sDataIn){
	int fromSData  = 15;
	int toSData    = 18;
	printf("Sensor Data: 			");
    for(int i=fromSData; i<toSData; i++){
            printf("%c",sDataIn[i]);
            }
	printf("\n");

}
/*
Method to print the packet

*/
int printPacket(char* bufferIn){
	printf("--------------Packet--------------\n");
    char *res;
    res = getId(bufferIn, 'n');
    printf("\n");
    getVal(bufferIn);
    getCInstr(bufferIn);
    getCData(bufferIn);
    getSInstr(bufferIn);
    getSData(bufferIn);
    printf("--------------Packet--------------\n");
    return res;
}

int addNullTerm(char *bufferIn){

}

