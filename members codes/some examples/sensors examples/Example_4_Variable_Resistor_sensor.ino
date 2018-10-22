//Example_4_Variable_Resistor_sensor
const int sensorPin = A0;    
const int ledPin = 13;      
int sensorValue;

void setup( ) 
{
  pinMode(ledPin, OUTPUT);  
}
void loop ( )
{
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);         
  delay(sensorValue);                 
  digitalWrite(ledPin, LOW);          
  delay(sensorValue);                
}

