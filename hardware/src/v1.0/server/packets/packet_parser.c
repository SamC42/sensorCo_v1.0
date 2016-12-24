/*
	This file creates the packet parser for the Server

*/
#include <stdio.h>
/* Method to Determine the Id
 * Args: Id in int
 * Return:
 * Range is from 0-32767
 */
/*
char* getPart(char* idIn, char cmd, int from, int to){

	//int from   = 0;
	//int to 	   = 24;
    int count  = 0;
    char *res;
    res = malloc(24);
    for(int i=from; i<to; i++){
        count = count + 1;
        res[i] = idIn[i];

        if(count == 3){
            //res[i] = '\0';
            //i = i+1;
            count = 0;
            //printf("IN count 3\n");
        }
        printf("%c",res[i]);
   
    }
        return res;
}
*/
char* getId(char* idIn){
    char *res;
    res = malloc(4);
    int fromVal = 0;
    int toVal   = 3;
    printf("Status ID:              ");
    for(int i=fromVal; i<toVal; i++){
           printf("%c",idIn[i]);
           res[i] = idIn[i];
        }
    res[4] = '\0';
    printf("\n");   
    return res;
}
/* Method to Determine the Value
 * Args: Value as int
 * Returns: 
 * 
 */
char* getVal(char* valIn){
	int fromVal	= 3;
	int toVal	= 6;
    char *res;
    malloc(4);
    printf("Sensor Value: 			");
	for(int i=fromVal; i<toVal; i++){
           printf("%c",valIn[i]);
           res[i] = valIn[i];
        }
    res[4] = '\0';
    printf("\n");
	return res;
}

/* Method to Determine the Controller Instruction
 * Args: Value in hex
 * Returns: Value as a decimal
 * Range is from 0x000 - 0xFFF
 */
char* getCInstr(char* cInstrIn){
    char *res;
    malloc(4);
	int fromCInstr = 6;
	int toCInstr   = 9;	
	printf("Controller Instruction: 	");
    for(int i=fromCInstr; i<toCInstr; i++){
                printf("%c",cInstrIn[i]);
                res[i] = cInstrIn[i];
            }
    res[4] = '\0';
	printf("\n");
    return res;
	
}
/* Method to determine the controller data
*/
char* getCData(char* cDataIn){
    char *res;
    malloc(4);
	int fromCData  = 9;
	int toCData    = 12;
	printf("Controller Data:		");
    for(int i=fromCData; i<toCData; i++){
            printf("%c",cDataIn[i]);
            res[i] = cDataIn[i];
        }
    res[4] = '\0';        
	printf("\n");
    return res;
}
/*	Method to determine the Sensor Instruction (Recieving Instr)

*/
char* getSInstr(char* sInstrIn){
	char *res;
    malloc(4);
    int fromSInstr = 12;
	int toSInstr   = 15;
	printf("Sensor Instruction: 		");
    for(int i=fromSInstr; i<toSInstr; i++){
            printf("%c",sInstrIn[i]);
            res[i] = sInstrIn[i];
        }
    res[4] = '\0';
	printf("\n");
    return res;
}
/* Method to determine the Sensor's data from the instruction

*/
char* getSData(char* sDataIn){
	char *res;
    malloc(4);
    int fromSData  = 15;
	int toSData    = 18;
	printf("Sensor Data: 			");
    for(int i=fromSData; i<toSData; i++){
            printf("%c",sDataIn[i]);
            res[i] = sDataIn[i];
            }
    res[4] = '\0';
	printf("\n");
    return res;

}
/*
Method to print the packet

*/
char* printPacket(char* bufferIn){
	printf("--------------Packet--------------\n");
    getId(bufferIn);
    getVal(bufferIn);
    getCInstr(bufferIn);
    getCData(bufferIn);
    getSInstr(bufferIn);
    getSData(bufferIn);
    printf("--------------Packet--------------\n");
}
/*
int padwNull(char* bufferIn, int from, int to){
    char cmd = 'n';
    char* res;
    res = malloc(18);
    getPart(bufferIn, cmd, 0, 3);
    getPart(bufferIn, cmd, 3, 6);
    getPart(bufferIn, cmd, 6, 9);
    getPart(bufferIn, cmd, 9, 12);
    getPart(bufferIn, cmd, 12, 15);
    getPart(bufferIn, cmd, 15, 18);
    printf("\n");
}
*/