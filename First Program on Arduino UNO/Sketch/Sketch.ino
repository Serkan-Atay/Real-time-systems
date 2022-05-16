void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, LOW);         // "LOW" INSTEAD OF "HIGH" BECAUSE NO GROUND CABLE IS USED.
  delay(200);
  digitalWrite(3, LOW);
  delay(200);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(5, LOW);
  delay(200);
  digitalWrite(3, HIGH);        // Vice versa. See above comment.
  delay(200);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(2, HIGH);
  delay(200);
}
