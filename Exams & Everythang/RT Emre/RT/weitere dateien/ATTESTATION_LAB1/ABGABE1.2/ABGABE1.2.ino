/*******************************************************  M3RTS  *************************************************************
 *   Prof. Dr. rer. nat Karsten Weronek, Faculty 2, B.Sc. Informatik, Faculty 2, Frankfurt Univeristy of Appliec Sciences    *
 *   Real-Time Systems: Module RTA, Source-Code for program: leds-leonardo.c                                                 *
 *                                                                                                                           *
 *   Turns an LED on for one second, then off for one second, repeatedly.                                                    *
 *   This example code is in the public domain.  It is based on: http://www.arduino.cc/en/Tutorial/Blink                     *
 *                                                                                                                           *
 *   new to learn: pinMode, digitalWirte                                                                                     *
 *****************************************************************************************************************************/

// #define is a useful C component that allows the programmer to give a name to a constant value before the program is compiled.
// The compiler will replace references to these constants with the defined value at compile time.
// Defined constants in arduino don’t take up any program memory space on the chip.
// The assignment of PINs depend on the specific hardware. We user Olimex. Olimex is equivalent to "Arduiuno Leonardo"
#define PUSH_BUTTON_S1 8

#define PINLED1    0 
#define PINLED2    1 
#define PINLED3    2 
#define PINLED4    3
#define PINLED5    4
#define PINLED6    5
#define PINLED7    6
#define PINLED8    7


// The setup() function is called when a sketch starts. 
// Use it to initialize variables, pin modes, start using libraries, etc. 
// The setup() function will only run once, after each powerup or reset of the Arduino board.
void setup() {

  // pinMode configures the specified pin to behave either as an input or an output.
  pinMode(PINLED1, OUTPUT);
  pinMode(PINLED2, OUTPUT);
  pinMode(PINLED3, OUTPUT);
  pinMode(PINLED4, OUTPUT);
  pinMode(PINLED5, OUTPUT);
  pinMode(PINLED6, OUTPUT);
  pinMode(PINLED7, OUTPUT);
  pinMode(PINLED8, OUTPUT);
  

  // digitalWrite() Writes a HIGH or a LOW value to a digital pin.
  // If the pin has been configured as an OUTPUT with pinMode(), its voltage will be set to the corresponding value:
  // 5 Volt(V) for HIGH and 0V for LOW.
  // next lines perform the preset for the LEDs
  digitalWrite(PINLED1,  LOW);    // turn off PINLED1
  digitalWrite(PINLED2,  LOW);    // turn off PINLED1
  digitalWrite(PINLED3,  LOW);    // turn off PINLEDRX
  digitalWrite(PINLED4,  LOW);    // turn off PINLEDTX
  digitalWrite(PINLED5,  LOW);    
  digitalWrite(PINLED6,  LOW);    
  digitalWrite(PINLED7,  LOW);    
  digitalWrite(PINLED8,  LOW);    


}

// the loop function runs over and over again forever
// After creating a setup() function, which initializes and sets the initial values, 
// the loop() function does precisely what its name suggests, and loops consecutively, 
// allowing your program to change and respond. Use it to actively control the Arduino board. 
void loop() {


while(digitalRead(PUSH_BUTTON_S1)==1{
  digitalWrite(PINLED1,   HIGH);
  delay(50);
  digitalWrite(PINLED2,   HIGH);   
  delay(50);                     
  digitalWrite(PINLED3,   HIGH); 
  delay(50);
  digitalWrite(PINLED4,   HIGH); 
  delay(50); 
  digitalWrite(PINLED5,   HIGH); 
  delay(50);
  digitalWrite(PINLED6,   HIGH);  
  delay(50); 
  digitalWrite(PINLED7,   HIGH);
  delay(50);
  digitalWrite(PINLED8,   HIGH);
  delay(50);
  digitalWrite(PINLED1,   LOW);
  delay(50);
  digitalWrite(PINLED2,   LOW);   
  delay(50);                     
  digitalWrite(PINLED3,   LOW); 
  delay(50);
  digitalWrite(PINLED4,   LOW); 
  delay(50); 
  digitalWrite(PINLED5,   LOW); 
  delay(50);
  digitalWrite(PINLED6,   LOW);  
  delay(50); 
  digitalWrite(PINLED7,   LOW);
  delay(50);
  digitalWrite(PINLED8,   LOW); 
}
  
}
