#include<math.h>
int time=0;
int value;
void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void loop()
{
  for(int i=0;i<8;i++)
  {
    value=digitalRead(i);
    Serial.print("value is   ");
    Serial.println(value);
    value=value*(pow(2,i));
    time = time+(value*4);
    Serial.println(time);
  }
  digitalWrite(8,HIGH);
  delay(time);
  digitalWrite(8,LOW);
  delay(1000);
  
  
 // value=0;
  time=0;
}
