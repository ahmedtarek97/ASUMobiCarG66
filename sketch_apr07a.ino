#define LED 13 
#define BUTTON 7
void setup()

{
   Serial.begin(9600);
  pinMode(LED, OUTPUT);
pinMode(BUTTON, INPUT);
digitalWrite(BUTTON, HIGH); 
}
int oldValue = HIGH;
int state = LOW;
void loop()
{
  int value = digitalRead(BUTTON);
if(value==LOW && oldValue==HIGH) 
state = (state==LOW)?HIGH:LOW;
digitalWrite(LED, state);
Serial.println ("state");
oldValue = value; 
}
