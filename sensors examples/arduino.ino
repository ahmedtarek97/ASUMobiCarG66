const int pingPin = 7;
const int echoPin = 6;

#define limit_max  1000  // 500cm
#define limit_min  50  // 100cm

#define LedAlarm   8    // pin trigger alarm
#define LedPing    13   // pin Led ping Sensor
void setup() 
{
  pinMode(LedAlarm, OUTPUT);
  pinMode(LedPing, OUTPUT);
  digitalWrite(LedAlarm, LOW);
  digitalWrite(LedPing, LOW);
  
  // initialize serial communication:
  Serial.begin(9600);

}
void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  digitalWrite(LedPing, HIGH);
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
 
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  

  // SERIAL DEBUG
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  
  if((cm < limit_min) || (cm > limit_max)){
   digitalWrite(LedPing, LOW);
   digitalWrite(LedAlarm, HIGH);
   Serial.print("  Detected Alarm!");
   Serial.println();
   delay(500);
   digitalWrite(LedAlarm, LOW);
  }else{
   Serial.println(); 
  }
  
  digitalWrite(LedPing, LOW);
  delay(100);
  
}
long microsecondsToCentimeters(long microseconds)
{

  return microseconds / 29 / 2;
}

