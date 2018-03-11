// Right Side Motors
int enA = 9;
int in1 = 8;
int in2 = 7;

// Left Side Motors
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() 
{
  Serial.begin(9600);
  pinMode(enA ,OUTPUT);
  pinMode(in1 ,OUTPUT);
  pinMode(in2 ,OUTPUT);
  pinMode(enB ,OUTPUT);
  pinMode(in3 ,OUTPUT);
  pinMode(in4 ,OUTPUT);
}

void loop() {
  if (Serial.available() > 0)
  {
    int data;
    data = Serial.read();
    Serial.print(data);

    switch (data)
    {

      case '1': //FORWARD
        analogWrite(enA,255);
        analogWrite(enB,255);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        break;

      case '2': //REVERSE
        analogWrite(enA,255);
        analogWrite(enB,255);
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
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
 

