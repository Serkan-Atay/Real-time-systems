#define PRESSED LOW
#define OPEN HIGH

#define S1 2
#define S2 3

void setup() {
  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  Serial.begin(9600);
}

unsigned long t1;
unsigned long t2;
unsigned long d;

void loop() {
  Serial.println("Hello this is a reaction Test of "); //#1
  
  while (digitalRead(S1) == OPEN) {}; //#2
  t1 = micros(); //#3
  
  while (digitalRead(S2) == OPEN) {}; //#4
  t2 = micros(); //#5

  Serial.println("t1: " + String(t1) + " micros"); //#6
  Serial.println("t2: " + String(t2) + " micros"); //#7

  d = t2 - t1;
  Serial.println("difference: " + String(d) + " micros");

  //#10
  float dS = d / 1000000;

  Serial.print(dS, 6);
  Serial.println(" s");
}
