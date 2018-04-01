#include "NewPing.h"
 
// Hook up HC-SR04 with Trig to Arduino Pin 10, Echo to Arduino pin 13
// Maximum Distance is 400 cm
 
#define TRIGGER_PIN  10
#define ECHO_PIN     13
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
float distance;
 
void setup() {
  Serial.begin (9600);
}
 
void loop() {
   
  distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
}
