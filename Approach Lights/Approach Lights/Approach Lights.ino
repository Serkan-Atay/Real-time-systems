/* Author: Serkan Atay, 1207077*/

#define ON LOW
#define OFF HIGH

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  
  if(digitalRead(2) == OFF) {
    
    for(int i = 5; i < 13; i++) {
      digitalWrite(i, ON);
      delay(2);
      digitalWrite(i, OFF);
      delay(60); 
      delayMicroseconds(500);
      }
      
     }
     else {
      for(int i = 5; i < 13; i++) {
        digitalWrite(i, OFF);  
      }
  }
}
