volatile byte state =LOW;
int buttonState = 0;
int i=0;


void setup() {
pinMode(0, INPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
attachInterrupt(digitalPinToInterrupt(0), next, FALLING);


}

void loop() {


digitalWrite(1, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);

state=!state;
digitalWrite(i, state);





/* attachInterrupt(digitalPinToInterrupt(0), next(i), LOW);


buttonState = digitalRead(8);
if(buttonState == LOW){
}
*/

}


void next() {
if(i==5){
i=0;
}
i++;
state=!state;
}
