

int ledDoor= 12;
int ledLaundry = 10;  
char state = '0';
int flag =0 ;

void setup() {
  // put your setup code here, to run once:
  digitalWrite(ledDoor,LOW);
  digitalWrite(ledLaundry,LOW);  
  pinMode(ledDoor, OUTPUT);
  pinMode(ledLaundry, OUTPUT);
  Serial.begin(9600);
  //delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    state = Serial.read();
    flag =0;
  
    if (state == 'n') {
      
      if(flag ==0) {
        flag=1;
        digitalWrite(ledDoor, HIGH);
        Serial.print(state);
        Serial.println("LED: OFF");
        delay(2000);
        digitalWrite(ledDoor, LOW);
        flag = 1;
      }
     }
     if (state == 'l'){ //L
          digitalWrite(ledLaundry, HIGH);
          delay(1000);
          digitalWrite(ledLaundry, LOW);
          Serial.print(state);
          Serial.println("Laundry");
     }
    }
}
