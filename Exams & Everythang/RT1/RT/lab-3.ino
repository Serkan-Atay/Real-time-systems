#define PINLED1    0 // LED1
#define PINLED2    1 // LED2
#define PINLED3    2 // LED3
#define PINLED4    3 // LED4
#define PINLED5    4 // LED5
#define PINLED6    5 // LED6
#define PINLED7    6 // LED7
#define PINLED8    7 // LED8
#define PUSH_BUTTON_S1 8 
#define PUSH_BUTTON_S2 9

int val = 0;

void setup() {


  pinMode(PINLED1,  OUTPUT);
  pinMode(PINLED2,  OUTPUT);
  pinMode(PINLED3,  OUTPUT);
  pinMode(PINLED4,  OUTPUT);
  pinMode(PINLED5,  OUTPUT);
  pinMode(PINLED6,  OUTPUT);
  pinMode(PINLED7,  OUTPUT);
  pinMode(PINLED8,  OUTPUT);
  
 
  digitalWrite(PINLED1,   HIGH);
  digitalWrite(PINLED2,   HIGH);
  digitalWrite(PINLED3,   HIGH);
  digitalWrite(PINLED4,   HIGH);
  digitalWrite(PINLED5,   HIGH);
  digitalWrite(PINLED6,   HIGH);
  digitalWrite(PINLED7,   HIGH);
  digitalWrite(PINLED8,   HIGH);
}


void loop(){
  val = digitalRead(PUSH_BUTTON_S1);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(PINLED1, LOW);   // turn LED OFF
    delay(100);
    digitalWrite(PINLED3, LOW);
    delay(100);
    digitalWrite(PINLED5, LOW);
    delay(100);
    digitalWrite(PINLED7, LOW);
    
  digitalWrite(PINLED2,  HIGH); 
  delay(75);                    
  digitalWrite(PINLED4,  HIGH);   
  delay(75);
  digitalWrite(PINLED6,  HIGH); 
  delay(75);                    
  digitalWrite(PINLED8,  HIGH); 

  } else {
    // turn LED ON
  digitalWrite(PINLED2,  LOW); 
  delay(75);                    
  digitalWrite(PINLED4,  LOW);   
  delay(75);
  digitalWrite(PINLED6,  LOW); 
  delay(75);                    
  digitalWrite(PINLED8,  LOW);  
   
    digitalWrite(PINLED1, HIGH);   // turn LED OFF
    delay(100);
    digitalWrite(PINLED3, HIGH);
    delay(100);
    digitalWrite(PINLED5, HIGH);
    delay(100);
    digitalWrite(PINLED7, HIGH);


 // delay(2000);
  }
}
  
