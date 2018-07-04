int j;
int sensorValue;
void setup () 
{  
  for(j=0;j<10;j++)
  {pinMode(j , OUTPUT);}
}
void loop ()
{
  sensorValue = analogRead(3);  
   for(j=0;j<10;j++)
  {
  digitalWrite(j, HIGH);      
  delay(sensorValue);    
  digitalWrite(j, LOW);
  delay(sensorValue);
 } 
}
