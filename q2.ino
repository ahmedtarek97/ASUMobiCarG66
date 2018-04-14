
void setup() {
  
  Serial.begin(9600);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(6, OUTPUT);

}

void loop() {
  
  int sensor = digitalRead(2);
  
  Serial.println(sensorVal);


  if (sensor == HIGH) {
    digitalWrite(6, LOW);
  } else {
    digitalWrite(6, HIGH);
  }
}
