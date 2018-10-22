int x;
void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
}

void loop() {
 for(int j=0;j<256;j++){
    x = j ;
    if(t>128){
      digitalWrite(9,HIGH) ;
      x = x - 128 ;
    }else{
      digitalWrite(9,LOW) ;
    }
    if(x>64){
      digitalWrite(8,HIGH) ;
      x = x - 64 ;
    }else{
      digitalWrite(8,LOW) ;
    }
    if(x>32){
      digitalWrite(7,HIGH) ;
      x = x - 32 ;
    }else{
      digitalWrite(7,LOW) ;
    }
    if(x>16){
      digitalWrite(6,HIGH) ;
      x = x - 16 ;
    }else{
      digitalWrite(6,LOW) ;
    }
    if(x>8){
      digitalWrite(5,HIGH) ;
      x = x - 8 ;
    }else{
      digitalWrite(5,LOW) ;
    }
    if(x>4){
      digitalWrite(4,HIGH) ;
      x = x - 4 ;
    }else{
      digitalWrite(4,LOW) ;
    }
    if(x>2){
      digitalWrite(3,HIGH) ;
      x = x - 2 ;
    }else{
      digitalWrite(3,LOW) ;
    }
    if(x>1){
      digitalWrite(2,HIGH) ;
      x = x - 1 ;
    }else{
      digitalWrite(2,LOW) ;
    }
    delay(1000) ;

  }
}
