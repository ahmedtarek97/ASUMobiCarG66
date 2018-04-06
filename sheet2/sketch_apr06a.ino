byte leds[10] = {0,1,2,3,4,5,6,7,8,9} ;
float t ;
void setup() {
  for (byte i=0 ; i<10 ;i++){
    pinMode(leds[i],OUTPUT) ;
  }

}

void loop() {
  t = analogRead(0) ;
  for (byte j=0 ; j<10 ;j++){
    digitalWrite(leds[j],HIGH) ;
    delay(t*1000) ;
    digitalWrite(leds[j],LOW) ;
  }

}
