/* Client Tracking
 *
 * Write what was inputted to a text file. 
 * TODO: Will be adding to record in db later
 */

 void clientTracking(char *toRecord){
 	FILE *clientFile;
	clientFile = fopen("/home/bull4/Projects/Sensor_breakout/tracking/log.txt","w+");
	fprintf(clientFile,toRecord);
	fclose(clientFile);
    
 }