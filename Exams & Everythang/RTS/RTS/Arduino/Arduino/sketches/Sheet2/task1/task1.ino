#define PINLED1    7 // LED1
#define PINLED2    9 // LED2
#define PINLED3  17 // RXLED
#define PINLED4  30 // TXLED

void setup() {

  pinMode(PINLED1,  OUTPUT);
  digitalWrite(PINLED1,   LOW); 
   
  pinMode(PINLED2,  OUTPUT);
  digitalWrite(PINLED2,   LOW); 
  
    pinMode(PINLED3,  OUTPUT);
  digitalWrite(PINLED3,   LOW); 
   
  pinMode(PINLED4,  OUTPUT);
  digitalWrite(PINLED4,   LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PINLED2,  HIGH); 

delay(100);  
  digitalWrite(PINLED1,  HIGH);
  delay(100);  
  digitalWrite(PINLED3,  HIGH); 
  delay(100);  
  digitalWrite(PINLED4,  HIGH); 
 
  
delay(100);                     
  digitalWrite(PINLED1,   LOW);  


  digitalWrite(PINLED2,   LOW); 
    digitalWrite(PINLED3,   LOW); 
      digitalWrite(PINLED4,   LOW); 
  delay(100);                  
}
