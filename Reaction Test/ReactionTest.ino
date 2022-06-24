
// Petrenco Veaceslav
void setup()
{
 Serial.begin(115200); 
 pinMode(2, INPUT_PULLUP); // Die 2 Knöpfe definieren 
 pinMode(2, INPUT_PULLUP);
}

void loop()
{
 


  if(digitalRead(2)==HIGH){ // solage der Knopf 1 nicht gedrückt wird passiert nichts 

    unsigned long time1 =micros(); //Time 1, nehme den Wert
    
       wait(); //warte auf den 2 Knopf

       //Ausgabe
       Serial.print("Time 1: "); // Ausgabe für time 1 in miliseconds
       Serial.println(time1);
        
      unsigned long time2 =micros(); //Time 2, nehme den Wert
    
      Serial.print("Time 2: ");// Ausgabe für time 2 in miliseconds
      Serial.println(time2);

    unsigned long df = time2-time1;
    Serial.print("Difference: ");// Ausgabe für time 2 in miliseconds
    Serial.println(df);
    delay(200);

    float convertInSeconds = df/1000.00000; // die miliseconds werden in seconds umgewandelt
     Serial.print("Ausgabe in Seconds ");// Ausgabe in Seconds
    Serial.println(convertInSeconds,6); //Ausgabe mit 7 kommachstellen
    
  }
}

void wait(){
   while(digitalRead(3)==LOW){
    //Warten bis der 2 Knopf gedrückt wird, dann springe zurück in die Schleife......
    }
}
