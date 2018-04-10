// Right Side Motors
int enA = 9;
int in1 = 8;
int in2 = 7;

// Left Side Motors
int enB = 3;
int in3 = 5;
int in4 = 4;
int ir1=10;
int data1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(enB , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  pinMode(ir1,INPUT);//black zero  white one
}

void loop() {
  data1=digitalRead(ir1);
  Serial.println(data1);
  delay(2000);
  if(data1==HIGH)
  { //FORWARD
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,250);
        digitalWrite(in3,HIGH); 
        digitalWrite(in4,LOW);
        analogWrite(enB,250);
       
  }

     else{ //REVERSE
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);
       }

      

  
}
