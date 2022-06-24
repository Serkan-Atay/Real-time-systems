//Creates a Blinking Led Bar with delays of 200ms

#define OFF HIGH
#define ON LOW
#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 8
#define LED5 9
#define LED6 10
#define LED7 11
#define LED8 12
const int ledCount = 8;   //Number of LEDs
const byte ledPins[] = {5,6,7,8,9,10,11,12};
const byte interruptPin = 2;    // Pin where the button is connected
int pinStatus = 0;    //Variable for reading the pin status

void setup() {
  // sets the pushbutton to INPUT
   pinMode(interruptPin, INPUT_PULLUP);  
   attachInterrupt(digitalPinToInterrupt(interruptPin),idle,CHANGE);  
  // sets all the LEDs to OUTPUT
for (int thisLed = 0; thisLed < ledCount; thisLed++) {    
  pinMode(ledPins[thisLed], OUTPUT);
  digitalWrite(ledPins[thisLed], OFF);
  }

}

void loop() {


  // Turns the Led on
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
          digitalWrite(ledPins[thisLed], ON);
    // calculate the step duration
     int stepDuration = 500/8;  // 500ms = 2Hz --> dividing this with 8 gives the step duration
     delay(stepDuration);
     //turns the Led off
     for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        digitalWrite(ledPins[thisLed], OFF);
        }
    while(digitalRead(interruptPin)==LOW);
    }
    
}
void idle() {
   for (int thisLed = 0; thisLed < ledCount; thisLed++) 
          digitalWrite(ledPins[thisLed], OFF);
    
         
        digitalWrite(ledPins[0], ON);
        digitalWrite(ledPins[7], ON);
        
    while(digitalRead(interruptPin)==LOW);
    }
      
    
