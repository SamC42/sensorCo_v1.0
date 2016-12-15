int anaIn = A0;
int senseIn = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  char cmd = 'n';
  if(Serial.available() > 0)
    {
      cmd = Serial.read();  
  
  if(cmd == 'g'){
    senseIn = analogRead(anaIn);
    Serial.print(senseIn);
    Serial.println("New Line");
    }
  else if(cmd == 'q')
    {
    Serial.end();
    }
  }
}
