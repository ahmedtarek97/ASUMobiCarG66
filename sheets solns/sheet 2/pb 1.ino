#include <math.h>
void setup() {
  // put your setup code here, to run once:
for (int i =0 ; i<8 ; i++)
{
    pinMode (i, INPUT);
  }
  pinMode (8,OUTPUT);
}
float T =0;
void loop() {
  // put your main code here, to run repeatedly:
for (int i=0; i<8 ; i++)
{
  T +=(pow(2,i)*digitalRead (i));
  
  }
  T=T*4;
 digitalWrite (8,HIGH);
 delay (T);
}

