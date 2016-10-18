int anaIn = A0;
int senseIn = 0;


void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  //Read Value from Sensor
  senseIn = analogRead(anaIn);
  if(senseIn > 100){
    Serial.write(1);
    }
  else
    Serial.write(0);
  
}
