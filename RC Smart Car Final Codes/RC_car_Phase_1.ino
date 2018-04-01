#include "NewPing.h"

#define TRIGGER_PIN  10
#define ECHO_PIN     13
#define MAX_DISTANCE 400

// Right Side Motors
int enA = 9;
int in1 = 8;
int in2 = 7;

// Left Side Motors
int enB = 3;
int in3 = 5;
int in4 = 4;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(enB , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
}

void loop() {
 distance = sonar.ping_cm();
 
 if (distance > 10) 
 {
  if (Serial.available() > 0)
  {
    char data ;
    data = Serial.read();
    Serial.print(data);
    switch (data)
    {

      case 'B': //REVERSE
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);
        break;

      case 'F': //FORWARD
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,250);
        digitalWrite(in3,HIGH); 
        digitalWrite(in4,LOW);
        analogWrite(enB,250);
        break;

      case 'R': //RIGHT
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,250);
        break; 

     case 'L': //LEFT
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);
        break; 

     case 'G': //FORWARD LEFT
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,100);
        break;  

     case 'I':  // FORWARD RIGHT
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,100);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,250);
        break;
   
     case 'H': //BACKWARD LEFT 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,0);
        break;

     case 'J': //BACKWARD RIGHT
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,0);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);
        break;     
        
     default: //If bluetooth module receives any value not listed above, both motors turn off
        analogWrite(enA,0);
        analogWrite(enB,0);
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
    }
  }
 }
 // if distace below 10 cm go reverse 
 else 
 {      
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,150);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,150);
 }
}
