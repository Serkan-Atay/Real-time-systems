
#define OFF HIGH
#define ON LOW



void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(5, OFF);
  digitalWrite(6, OFF);
  digitalWrite(7, OFF);
  digitalWrite(8, OFF);
  digitalWrite(9, OFF);
  digitalWrite(10, OFF);
  digitalWrite(11, OFF);
  digitalWrite(12, OFF);
  pinMode(2, INPUT_PULLUP);
  

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
 while(digitalRead(2)== ON);
  digitalWrite(5,ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(5, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(6,ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(6, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(7,ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(7, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(8,ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(8, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(9, ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(9, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(10, ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(10, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(11, ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(11, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
  digitalWrite(12, ON);
  delay(2);
 while(digitalRead(2)== ON);
  digitalWrite(12, OFF);
  delay(60);
  delayMicroseconds(500);
 while(digitalRead(2)== ON);
}
