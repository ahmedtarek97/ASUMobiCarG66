const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  pinMode(analogOutPin,OUTPUT);
  pinMode(analogInPin ,INPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  digitalWrite(analogOutPin,HIGH);
  delay(sensorValue);
  digitalWrite(analogOutPin,LOW);
  delay(sensorValue);
  }
