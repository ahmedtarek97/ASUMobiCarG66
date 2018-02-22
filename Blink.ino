/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   
  delay(1000);              
  digitalWrite(13, LOW);    
  delay(1000);   
  digitalWrite(12, HIGH);   
  delay(1000);              
  digitalWrite(12, LOW);    
  delay(1000); 
  digitalWrite(10, HIGH);   
  delay(1000);              
  digitalWrite(10, LOW);    
  delay(1000); 
  digitalWrite(9, HIGH);   
  delay(1000);              
  digitalWrite(9, LOW);    
  delay(1000);            
}
