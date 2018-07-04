int led1=8,led2=9,led3=10,led4=11,led5=12,motorL1=4,motorL2=5,motorR1=6,motorR2=7;
void setup( )
{
  pinMode (led1 ,INPUT);
  pinMode (led2 ,INPUT);
  pinMode (led3 ,INPUT);
  pinMode (led4 ,INPUT);
  pinMode (led5 ,INPUT);
  pinMode (motorL1,OUTPUT);
  pinMode (motorR1,OUTPUT);
  pinMode (motorL2,OUTPUT);
  pinMode (motorR2,OUTPUT);
}
void loop( )
{
  led1=digitalRead(8);
  led2=digitalRead(9);
  led3=digitalRead(10);
  led4=digitalRead(11);
  led5=digitalRead(12);
  
  if (led1==LOW&&led2==LOW&&led3==LOW&&led4==LOW&&led5==LOW)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  else if (led1==LOW&&led2==LOW&&led3==LOW&&led4==LOW&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==LOW&&led3==LOW&&led4==HIGH&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==LOW&&led3==LOW&&led4==HIGH&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==LOW&&led3==HIGH&&led4==LOW&&led5==LOW)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==LOW&&led3==HIGH&&led4==LOW&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==LOW&&led3==HIGH&&led4==HIGH&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==LOW&&led3==HIGH&&led4==HIGH&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==LOW&&led4==LOW&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==LOW&&led4==LOW&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==LOW&&led4==HIGH&&led5==LOW)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==LOW&&led4==HIGH&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==HIGH&&led4==LOW&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==HIGH&&led4==LOW&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==HIGH&&led4==HIGH&&led5==LOW)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==LOW&&led2==HIGH&&led3==HIGH&&led4==HIGH&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==LOW&&led4==LOW&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==LOW&&led4==LOW&&led5==HIGH)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==LOW&&led4==HIGH&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==LOW&&led4==HIGH&&led5==HIGH)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==HIGH&&led4==LOW&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==HIGH&&led4==LOW&&led5==HIGH)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==HIGH&&led4==HIGH&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==LOW&&led3==HIGH&&led4==HIGH&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==LOW&&led4==LOW&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==LOW&&led4==LOW&&led5==HIGH)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==LOW&&led4==HIGH&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==LOW&&led4==HIGH&&led5==HIGH)
  {
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==HIGH&&led4==LOW&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==HIGH&&led4==LOW&&led5==HIGH)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else if (led1==HIGH&&led2==HIGH&&led3==HIGH&&led4==HIGH&&led5==LOW)
  {
    delay(10);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
   else 
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }

      
