/*
	This file creates the packet parser for the Server

*/
#include <stdio.h>
/* Method to Determine the Id
 * Args: Id in hex
 * Return: id as an decimal
 * Range is from 0x000 -0xFFF
 */
int id_to_dec(int idIn){
	printf("ID 1: %d \n",idIn); 

	return 0;
}
/* Method to Determine the Status
 * Args: Status in hex
 * Returns: status as a decimal
 * Range is from 0x0 - 0x1
 */
int status_to_dec(int statusIn){
	if(statusIn = '0'){
		return 0
	}
	else if(statusIn = '1'){
		return 1;
	}
	else
		return 3;
}

/* Method to Determine the Value
 * Args: Value in hex
 * Returns: Value as a decimal
 * Range is from 0x000 - 0xFFF
 */
int value_to_dec(int bufferIn){

}
/* Method to Determine the Instruction
 * Args: instruction in hex
 * Returns: Instruction as an ascii character
 * Range is from 0x61 - 0x71
 */
int instruction_to_ascii(int bufferIn){

}

/*
 * Tests the hex input to the functions above
 */
int main(int argc, char **argv[]){
	int hexVal = 0xFF;
	id_to_dec(hexVal);
	return 0;





}