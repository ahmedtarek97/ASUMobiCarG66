void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float x = analogRead(2);
float y = analogRead(3);
float z = analogRead(4);
if(x>y)
{
  if(x>z)
digitalWrite(5,HIGH);

}
else if(y>z)
digitalWrite(6,HIGH);
else 
digitalWrite(7,HIGH);
}
