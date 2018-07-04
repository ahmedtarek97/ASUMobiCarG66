float anal[6] ;
byte button = 0 ;
byte j = 0 ;
byte o = 1 ;
void setup() {
  pinMode(button,INPUT_PULLUP) ;
}

void loop() {
  for(byte k=0;k<6;k++){
   anal[k] = analogRead(k) ;
  }
  digitalWrite(o,HIGH) ;
  delay(anal[j]*1000) ;
  digitalWrite(o,LOW) ;
  delay(anal[j]*1000) ;
  if((digitalRead(button))==LOW){
    j++ ;
    if(j==6){
      j = 0 ;
    }
  }
}
