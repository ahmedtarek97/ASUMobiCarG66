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
      t = t - 128 ;
    }else{
      digitalWrite(9,LOW) ;
    }
    if(t>64){
      digitalWrite(8,HIGH) ;
      t = t - 64 ;
    }else{
      digitalWrite(8,LOW) ;
    }
    if(t>32){
      digitalWrite(7,HIGH) ;
      t = t - 32 ;
    }else{
      digitalWrite(7,LOW) ;
    }
    if(t>16){
      digitalWrite(6,HIGH) ;
      t = t - 16 ;
    }else{
      digitalWrite(6,LOW) ;
    }
    if(t>8){
      digitalWrite(5,HIGH) ;
      t = t - 8 ;
    }else{
      digitalWrite(5,LOW) ;
    }
    if(t>4){
      digitalWrite(4,HIGH) ;
      t = t - 4 ;
    }else{
      digitalWrite(4,LOW) ;
    }
    if(t>2){
      digitalWrite(3,HIGH) ;
      t = t - 2 ;
    }else{
      digitalWrite(3,LOW) ;
    }
    if(t>1){
      digitalWrite(2,HIGH) ;
      t = t - 1 ;
    }else{
      digitalWrite(2,LOW) ;
    }
    delay(1000) ;

  }
}
