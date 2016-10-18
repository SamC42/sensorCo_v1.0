
int analogIn = A0;
int senseIn  = 0; 
char state = 'n';

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char state = 'n';  
  //Serial.println(senseIn);
  if(Serial.available() > 0 ){
    state = Serial.read();
    if(state == 'g'){ //g for get
        senseIn = analogRead(analogIn);
        if(senseIn > 100){ //Open
          Serial.write(1); 
          //Serial.print(1); 
          }
        else if (senseIn < 101){ //Closed
          Serial.write(3);
          //Serial.print(0);
        }
        else{ //Protection case
          Serial.write(2);
        }
      }
    else if(state == 'q'){
       Serial.end();
        }
    else{
      Serial.write(2);   
        }
  }
}
