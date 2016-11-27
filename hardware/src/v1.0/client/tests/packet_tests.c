/*
 * This class handles testing the packet sender
 * Arguments:
 * -allPack    -- Tests the whole packets suit
 * -onePacki   -- Allows you to input one packet by prompting for
 			   -- 	for information
 * -onePacki   -- Tests one packet without prompt 

 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int printHelp(){
	printf("-h          -- Help\n");
	printf("-ap      	-- (all Packets) Tests the whole Packet suite\n");
	printf("-1pi   		-- (one packet info) Tests one packet w/ prompt for info\n");
	printf("-1p    -- (one Packets) Tests packet w/out prompt \n");
	return 0;
}


int main(int argc, char * argv[])
{
    if( argc == 1 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"") == 0){
		printHelp();
		return 0;
	}
	

	if(strcmp(argv[1],"-ap") == 0){
		FILE *fp;
		fp = popen("../client_v1 -s","w");
		if(fp == NULL){
			printf("fp is null\n");
			return 0;
		}
		char bufferOut[12];
		//fprintf(fp,"ertyuiokjhgf");
		//while(fgetc(fp) != EOF){
		//}
		fprintf(fp,"qqqqqqqqqqqq");
		pclose(fp);
		//while( c = fgetc(fp) != EOF){
	//}
	}



}