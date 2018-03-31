#define LED 13 
int BUTTON1 = 7 ; 
int BUTTON2 = 8 ; 

void setup() {
  // put your setup code here, to run once:
  
pinMode(LED, OUTPUT); 
pinMode(BUTTON1, INPUT); 
pinMode(BUTTON2, INPUT); 

}
int value1 = LOW ; 
int value2 = LOW ; 
void loop() {
 int RD  = 500 ;
  value1 = digitalRead(BUTTON1); 
  value2 = digitalRead(BUTTON2); 
 while(100>RD>1000){
if(value1== HIGH && value2==LOW)
{
RD = RD +100 ; 
}
if(value2== HIGH && value1==LOW)
{
RD = RD -100 ; 
}
if(value1== LOW && value2==LOW)
{
RD = RD  ; 
}


 digitalWrite(LED, HIGH);
 delay(RD);
 digitalWrite(LED, LOW);
 delay(RD);
 }
 digitalWrite(LED, HIGH);
 delay(100);
 digitalWrite(LED, LOW);
 delay(100);
}
