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
  
  if(digitalRead(2) == HIGH) {
    
    for(int i = 5; i <= 12; i++) {
      digitalWrite(i, LO);
      delay(2);
      digitalWrite(i, LOW);
      delay(60); 
      delayMicroseconds(50);
      }
      
     }
     else if (digitalRead(2) == LOW) {
      for(int i = 5; i <= 12; i++) {
        digitalWrite(i, LOW);  
      }
  }
}
