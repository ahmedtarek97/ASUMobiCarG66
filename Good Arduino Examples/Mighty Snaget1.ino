/*
  This program blinks pin 13 of the Arduino (the
  built-in LED)
*/

void setup()
{
  pinMode(3, OUTPUT);

  pinMode(2, OUTPUT);
    digitalWrite(3, LOW);
  digitalWrite(2, LOW);

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);

}
