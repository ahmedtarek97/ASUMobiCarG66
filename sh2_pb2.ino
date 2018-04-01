void setup(){
pinMode(2,INPUT);  
pinMode(3,INPUT);
pinMode(4,OUTPUT);
attachInterrupt(digitalPinToInterrupt(2), faster , RISING);
attachInterrupt(digitalPinToInterrupt(3), slower , RISING);
}

int x=1000;
void loop() {

  digitalWrite(4,HIGH);
  delay(x);
  digitalWrite(4,LOW);
  delay(x);
 
}

void slower()
{
  
  if(x<10000)
  x+=1000;
  
  }
  void faster()
{
  
  if(x>1000)
  x-=1000;
  
  }
