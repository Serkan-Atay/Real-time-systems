/*******************************************************  M3RTS  *************************************************************
     Prof. Dr. rer. nat Karsten Weronek, Faculty 2, B.Sc. Informatik, Faculty 2, Frankfurt Univeristy of Appliec Sciences
     Real-Time Systems: Module RTA, Source-Code for program: leds-leonardo.c
 *                                                                                                                           
 *   Demo Program for serial monitore                                                                                                                        
 *                                                                                                                           *
 *****************************************************************************************************************************/

// The setup() function is called when a sketch starts.
// Use it to initialize variables, pin modes, start using libraries, etc.
// The setup() function will only run once, after each powerup or reset of the Arduino board.

#define PUSH_BUTTON_S1 8

#define PINLED1    0 
#define PINLED2    1 
#define PINLED3    2 
#define PINLED4    3
#define PINLED5    4
#define PINLED6    5
#define PINLED7    6
#define PINLED8    7

void setup() {

  unsigned long time1;
  unsigned long time2;
  unsigned long delta_time;

  pinMode(PUSH_BUTTON_S1, INPUT);
  pinMode(PUSH_BUTTON_S2, INPUT);

  pinMode(PINLED1, OUTPUT);
  pinMode(PINLED2, OUTPUT);
  pinMode(PINLED3, OUTPUT);
  pinMode(PINLED4, OUTPUT);
  pinMode(PINLED5, OUTPUT);
  pinMode(PINLED6, OUTPUT);
  pinMode(PINLED7, OUTPUT);
  pinMode(PINLED8, OUTPUT);


  digitalWrite(PINLED1,  LOW);    // turn off PINLED1
  digitalWrite(PINLED2,  LOW);    // turn off PINLED1
  digitalWrite(PINLED3,  LOW);    // turn off PINLEDRX
  digitalWrite(PINLED4,  LOW);    // turn off PINLEDTX
  digitalWrite(PINLED5,  LOW);    
  digitalWrite(PINLED6,  LOW);    
  digitalWrite(PINLED7,  LOW);    
  digitalWrite(PINLED8,  LOW);
}


// After creating a setup() function, which initializes and sets the initial values,
// the loop() function does precisely what its name suggests, and loops consecutively,
// allowing your program to change and respond.
// The loop function runs over and over again forever
// Use it to actively control the Arduino board.
// This program has nothing to control. This leads to an empty loop block.

void loop() {


  while(digitalRead(PUSH_BUTTON_S1)==1){}
  time1=micros();

  while(digitalRead(PUSH_BUTTON_S2)==1){}
  time2=micros();

  delta_time=time2-time1;
  Serial.println(time1);
  Serial.println(time2);
  Serial.println(delta_time);

}
