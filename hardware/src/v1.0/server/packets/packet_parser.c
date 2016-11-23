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
    printf("Status ID: ");
        for(int i=0; i<1; i++){
                printf("%c",idIn[i]);
                }
    printf("\n");
}
/* Method to Determine the Status
 * Args: Status in hex
 * Returns: status as a decimal
 * Range is from 0x0 - 0x1
 */
int getVal(char* valIn){
    printf("Sensor Value: ");
        for(int i=1; i<2; i++){
                printf("%c",valIn[i]);
            }
    printf("\n");
	
}

/* Method to Determine the Value
 * Args: Value in hex
 * Returns: Value as a decimal
 * Range is from 0x000 - 0xFFF
 */
int getCInstr(char* cInstrIn){
	
	printf("Controller Instruction: ");
	        for(int i=2; i<3; i++){
	                printf("%c",cInstrIn[i]);
	            }
	printf("\n");
	
}
int getCData(char* cDataIn){

	printf("Controller Data: ");
	        for(int i=3; i<4; i++){
	                printf("%c",cDataIn[i]);
	            }
	printf("\n");
}
int getSInstr(char* sInstrIn){
	printf("Sensor Instruction: ");
	        for(int i=4; i<5; i++){
	                printf("%c",sInstrIn[i]);
	            }
	printf("\n");
}

int getSData(char* sDataIn){
	printf("Sensor Data: ");
	        for(int i=5; i<6; i++){
	                printf("%c",sDataIn[i]);
	            }
	printf("\n");

}
/* Method to Determine the Instruction
 * Args: instruction in hex
 * Returns: Instruction as an ascii character
 * Range is from 0x61 - 0x71
 */