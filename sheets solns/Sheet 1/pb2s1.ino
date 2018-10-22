void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4,OUTPUT) ;
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
 
}

void loop()
{
 for(int i=3; i<=6; i++)
   {
   digitalWrite(i, HIGH);
   delay(1000);
    digitalWrite(i,LOW);
    delay(1000);

        
   }

   for(int i=6; i>=3; i--)
   {
    digitalWrite(i, HIGH);
   delay(1000);
   digitalWrite(i,LOW);
    delay(1000);

   }
  
}

