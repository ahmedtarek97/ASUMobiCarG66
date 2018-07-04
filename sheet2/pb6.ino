int i;
int sensorValue1;
int sensorValue2;
int sensorValue3;
void setup () 
{  
    pinMode(4, OUTPUT);
    pinMode(5 , OUTPUT);
    pinMode(6 , OUTPUT);
}
void loop ()
{
  sensorValue6 = analogRead(9);  
  sensorValue5 = analogRead(10);  
  sensorValue4 = analogRead(11);  
  if(sensorValue6>sensorValue5)
  {
    if(sensorValue6>sensorValue4)
    {
       digitalWrite(1, HIGH);
     }
   }
   else if (sensorValue5>sensorValue4)
   {
     digitalWrite(2, HIGH);
    }
    else
    { digitalWrite(3, HIGH);}
}
