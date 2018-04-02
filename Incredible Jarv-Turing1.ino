


int pos = 0;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  // turn off tone function for pin 8:
  noTone(8);
  // play a note on pin 6 for 200 ms:
  tone(6, 5274, 200); // play tone 100 (E8 = 5274 Hz)
  delay(200); // Wait for 200 millisecond(s)
  // turn off tone function for pin 6:
  noTone(6);
  // play a note on pin 7 for 500 ms:
  tone(7, 1661, 500); // play tone 80 (G#6 = 1661 Hz)
  delay(500); // Wait for 500 millisecond(s)
  // turn off tone function for pin 7:
  noTone(7);
  // play a note on pin 8 for 300 ms:
  tone(8, 294, 300); // play tone 50 (D4 = 294 Hz)
  delay(300); // Wait for 300 millisecond(s)
}