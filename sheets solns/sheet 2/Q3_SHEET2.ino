byte digitalpins[8] = {1,2,3,4,5,6,7,8} ;
int t ;
void setup() {
  for(int i=0;i<8;i++){
    pinMode (digitalpins[i],OUTPUT) ;
  }

}

void loop() {
  for(int j=0;j<256;j++){
    t = j ;
    if(t>128){
      digitalWrite(digitalpins[7],HIGH) ;
      t = t - 128 ;
    }else{
      digitalWrite(digitalpins[7],LOW) ;
    }
    if(t>64){
      digitalWrite(digitalpins[6],HIGH) ;
      t = t - 64 ;
    }else{
      digitalWrite(digitalpins[6],LOW) ;
    }
    if(t>32){
      digitalWrite(digitalpins[5],HIGH) ;
      t = t - 32 ;
    }else{
      digitalWrite(digitalpins[5],LOW) ;
    }
    if(t>16){
      digitalWrite(digitalpins[4],HIGH) ;
      t = t - 16 ;
    }else{
      digitalWrite(digitalpins[4],LOW) ;
    }
    if(t>8){
      digitalWrite(digitalpins[3],HIGH) ;
      t = t - 8 ;
    }else{
      digitalWrite(digitalpins[3],LOW) ;
    }
    if(t>4){
      digitalWrite(digitalpins[2],HIGH) ;
      t = t - 4 ;
    }else{
      digitalWrite(digitalpins[2],LOW) ;
    }
    if(t>2){
      digitalWrite(digitalpins[1],HIGH) ;
      t = t - 2 ;
    }else{
      digitalWrite(digitalpins[1],LOW) ;
    }
    if(t>1){
      digitalWrite(digitalpins[0],HIGH) ;
      t = t - 1 ;
    }else{
      digitalWrite(digitalpins[0],LOW) ;
    }
    delay(1000) ;

  }

}
