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
#define PINLED1    7 // LED1
#define PINLED2    9 // LED2
#define PINLEDRX  17 // RXLED
#define PINLEDTX  30 // TXLED


// The setup() function is called when a sketch starts. 
// Use it to initialize variables, pin modes, start using libraries, etc. 
// The setup() function will only run once, after each powerup or reset of the Arduino board.
void setup() {

  // pinMode configures the specified pin to behave either as an input or an output.
  pinMode(PINLED1,  OUTPUT);
  pinMode(PINLED2,  OUTPUT);
  pinMode(PINLEDRX, OUTPUT);
  pinMode(PINLEDTX, OUTPUT);


  // digitalWrite() Writes a HIGH or a LOW value to a digital pin.
  // If the pin has been configured as an OUTPUT with pinMode(), its voltage will be set to the corresponding value:
  // 5 Volt(V) for HIGH and 0V for LOW.
  // next lines perform the preset for the LEDs
  digitalWrite(PINLED1,   LOW);    // turn off PINLED1
  digitalWrite(PINLED2,   LOW);    // turn off PINLED1
  digitalWrite(PINLEDRX,  LOW);    // turn off PINLEDRX
  digitalWrite(PINLEDTX,  LOW);    // turn off PINLEDTX

}

// the loop function runs over and over again forever
// After creating a setup() function, which initializes and sets the initial values, 
// the loop() function does precisely what its name suggests, and loops consecutively, 
// allowing your program to change and respond. Use it to actively control the Arduino board. 

void loop() {
//IIb Exercise 1 a
  digitalWrite(PINLED1,  HIGH);   
  delay(900);                     
  digitalWrite(PINLED1,   LOW);   
  delay(100);     
  
 //IIb Exercise 1b


 digitalWrite(PINLED1, HIGH);
 delay(500);
 digitalWrite(PINLED2, HIGH);
 delay(500);
 digitalWrite(PINLEDRX, HIGH);
 delay(500);
 digitalWrite(PINLEDTX, HIGH);
 delay(500);
 digitalWrite(PINLED2, LOW);
 delay(500);
 digitalWrite(PINLED4, LOW);
 delay(500);
 digitalWrite(PINLEDRX, LOW);
 delay(500);
 digitalWrite(PINLEDTX, LOW);
 delay(500);
 
}
