/* Author: Patrick Billasch 1319907*/

void setup() {
  pinMode(2, INPUT);
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

  // int buttonstate = digitalRead(2);

  
  //if(buttonstate == HIGH){
    for(int i = 5; i < 13; i++){
    digitalWrite(i, LOW);
    delay(2);
    digitalWrite(i, HIGH);
    delay(60);
    /*delayMicroseconds(60500);*/
    }  
  //}
  
} 
