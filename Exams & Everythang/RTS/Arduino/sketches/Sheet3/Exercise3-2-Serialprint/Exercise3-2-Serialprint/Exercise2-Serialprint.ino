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
#define PUSH_BUTTON_S2 9

void setup() {

  unsigned long time1;
  unsigned long time2;
  unsigned long delta_time;

  pinMode(PUSH_BUTTON_S1, INPUT);
  pinMode(PUSH_BUTTON_S2, INPUT);
  
  // Serial. is used for communication between the Arduino board and a computer or other devices.
  // All Arduino boards have at least one serial port (also known as a UART or USART):
  // You can use the Arduino environment’s built-in serial monitor to communicate with an Arduino board.
  // Click the serial monitor button in the toolbar and select the same baud rate used in the call to begin().
  // The Arduino Leonardo board uses Serial is reserved for USB CDC communication.

  // Serial.begin() sets the data rate in bits per second (baud) for serial data transmission.
  // For communicating with the computer, use one of these rates: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 57600, or 115200.
  Serial.begin(9600);

  // if Serial indicates if the specified Serial port is ready.
  // while (!Serial) {} loops until the serial port is ready

  while (!Serial) {}


  // Serial.write() Writes binary data to the serial port.
  // This data is sent as a byte or series of bytes.

  Serial.write(65); // send a byte with the value 65 = "A"


  // Serial.pringln prints data to the serial port as human-readable ASCII text followed by
  // a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
  // This command takes the same forms as Serial.print().

  Serial.println();


  // sends the string "hello" and return the length of the string.

  int bytesSent = Serial.write("hello");
  Serial.println();


  // Serial.print prints data to the serial port as human-readable ASCII text.
  // to send the characters representing the digits of a number use the Serial.print() function instead.
  // DEC specifices the format for decimal numbers
  // for other formats refer: https://www.arduino.cc/reference/en/language/functions/communication/serial/print/

  Serial.print(bytesSent, DEC);
  Serial.println();

  // the following part demonstrates the differen format options for Serial.print()
  
  Serial.println();
  Serial.println("Hello world!");
  Serial.println();
  
  Serial.print("this with print and an excape sequence \n");
  Serial.print("this with print");
  Serial.println(" and this with println");
  Serial.println();
  
  Serial.println(47, BIN);
  Serial.println(47, OCT);
  Serial.println(47, DEC);
  Serial.println(47, HEX);
  Serial.println();

  Serial.println(1.23456, 0);
  Serial.println(1.23456, 2);
  Serial.println(1.23456, 4);
  Serial.println();


  // Serial.end() disables the serial communication

  Serial.end();
}


// After creating a setup() function, which initializes and sets the initial values,
// the loop() function does precisely what its name suggests, and loops consecutively,
// allowing your program to change and respond.
// The loop function runs over and over again forever
// Use it to actively control the Arduino board.
// This program has nothing to control. This leads to an empty loop block.

void loop() {
}
