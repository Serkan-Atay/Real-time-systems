unsigned long int time1;
unsigned long int time2;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
  Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
  Serial.println("Hello this is a reaction Test of Gökhan");

  while(digitalRead(8)==HIGH){}
  
  time1 =micros();
  
  while(digitalRead(9)==HIGH){}
  
  time2 =micros();
  
  Serial.println(time1);
  Serial.println(time2);
  Serial.println(time2-time1);
  Serial.println((float)(time2-time1)/1000000.0,6);
  Serial.end();
}
