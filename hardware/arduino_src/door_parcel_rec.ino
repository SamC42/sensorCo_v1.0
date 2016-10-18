
//Sensor Declaration
int analogPad = 0;
int val =0;
int flag = 0;
int outFull = 3;
int outHalf = 5;
int outEmpty= 6;
int outToInternet = 8;

void setup() {
  Serial.begin(9600);
  //digitalWrite(outVal,LOW);
  pinMode(outToInternet, OUTPUT);
  digitalWrite(outToInternet,LOW);

}

void loop() {
  timeStart = millis();  
  val = analogRead(analogPad);
  
  //IF the Package Has arrived
  if(val < 800 ){
    //Write to Green Led
    analogWrite(outHalf, val / 4);
    //Write to cloudBit
    digitalWrite(outToInternet,HIGH);
    delay(100);
    digitalWrite(outToInternet,LOW);
    
  }
  else{
    analogWrite(outHalf, 0);  
    
  }
  //If there is no package
  if(val > 850){
    //Write to Red led
    analogWrite(outEmpty, val / 4);
  }
  else{
    analogWrite(outEmpty, 0);  
    
  }  
  
}
