#define LED 13
#define BUTTON 2
int state = LOW;
void changeState() {
  state = (state==LOW)?HIGH:LOW;
  digitalWrite(LED, state);
  }
void setup()
{ 
  interrupts();
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(BUTTON, HIGH);
  attachInterrupt(0, changeState, FALLING); 
  }
void loop()
{
}
