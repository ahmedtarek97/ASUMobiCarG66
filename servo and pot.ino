#include <Servo.h> 
Servo servo; 
 
void setup() 
{ 
  Serial.begin(9600);
  servo.attach(7);  
} 
 
void loop() 
{ 
  int reading = analogRead(A0);     
  int angle = reading / 6;              
  servo.write(angle);  
  Serial.println(angle);
} 