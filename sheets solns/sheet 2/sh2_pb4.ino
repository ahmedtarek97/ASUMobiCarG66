
void setup() {
  
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(13,OUTPUT);
 attachInterrupt(digitalPinToInterrupt(2),nxt_out , RISING);
}
int i=3;

void loop() {
float x =analogRead(nxt_out(i));
digitalWrite(13,HIGH);
delay(x);
digitalWrite(13,LOW);

}

int nxt_out(int i)
{
  
  
  switch(i){
    case'3': i=4;
    case'4': i=5;
    case'5': i=6;
    case'6': i=7;
    case'7': i=8;
    case'8': i=3;
    
    }
  
  }
