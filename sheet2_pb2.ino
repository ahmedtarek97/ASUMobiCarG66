#define PIN 11
#define pls 2
#define mns 3
int x=1;

void setup() 
  {
    pinMode(PIN, OUTPUT); 
    attachInterrupt(digitalPinToInterrupt(pls), zwd, RISING);
     attachInterrupt(digitalPinToInterrupt(mns), alil, RISING);
  }
void loop() 
  {
    int state = 0;
    
  while(1) {
    if(state == 0) {
      digitalWrite(PIN , LOW);
      state = 1;
    } 
    else {
      digitalWrite (PIN , HIGH) ;
      state = 0;
    }
    float  t=x*1000/2;
    delay(t);
  }}
void zwd()
{
if(x<10)
{x++;}  
}
void alil ()
{
  if (x>1)
  {x--;}
}
