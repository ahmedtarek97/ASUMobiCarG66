//Example_5_Light_Sensor_1
const int lightPin = A0; 
const int ledPin = 9;
int lightLevel;

void setup ( )
{
  pinMode(ledPin, OUTPUT); 
}

void loop ( )
{
 lightLevel = analogRead(lightPin); 
 lightLevel = map(lightLevel, 0, 900, 0, 255); 
 lightLevel = constrain(lightLevel, 0, 255);
 analogWrite(ledPin, lightLevel);  
}

