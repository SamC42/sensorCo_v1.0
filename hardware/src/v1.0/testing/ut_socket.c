/*
Current functionality needs to be tested to ensure the socket sending and receiving 
logic is working as needed. These tests will be written and tested with v1.0 but will
be extended to v2.0. 

The test cases in these scenarios function as per v1.0. 
	1. PC sends is denoted as s1
	2. PC receives is denoted as r1
	3. Arduino sends is denoted as s2
	4. Arduino receives is denoted as r2

*/


/*Test Cases:

Scenario #  |     Sender	| data sent   		|   Expected Results	| Comments
    1       | 		s1		|	char 			|   r1 receive 			| Simulates polling sensor
    2	    | 		r2		|	char 			|   s1 receive 			| Simulates receiving from sensor
    3	    |		s1		|	send nothing	|	wait should not complete	| simulates waiting, check arduino and PC
    4		|		s1		|	


*/
#include <stdlib.h>
// Invoke Client.c with -t for testing 

int main(int argc, char *argv[]){
	testClientConn();

}
int testClientConn(){
	// Run the ./client executable with -t
	// Return prompt of 
	// Can start off using system()
	system("./client -t");
	// But should use exec_prog()

	//Return the prompt if the socket connect was successful

}




/*	Send a char 
 * Inputs: char input 
 * Outputs: returns the char that was sent

int send1(char * charIn){
char toSys[32];
	// Need to figure out how to wait to see if connection works before
	snprintf(toSys,"./client -t %c", charIn);
	system(toSys);
	return charIn;
}


int rec1(){



}

/*	Scenario 1 
 * Inputs: char input, char Expectedoutput
 * Outputs: returns if the test passes or not
 * Test condition: if the input char when sent gets received by r1 and loaded into ExpectedOutput

int scenario1(char input, char expOutput){
	
	if(expOutput == send1(input)){
		//The output Recieved is the expected output

	}
	else
		//something unexpected happened


}
*/