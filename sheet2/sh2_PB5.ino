void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float x = analogRead(2);
for(int i=2;i<13;i++)
{
  digitalWrite(i,HIGH);
  delay(x);
  digitalWrite(i,LOW);
  delay(x);
  }
}
