
// Right Side Motors
int enA = 9;
int in1 = 8;
int in2 = 7;

// Left Side Motors
int enB = 3;
int in3 = 5;
int in4 = 4;

// sensiors pins 

int s1 =10;
int s2 =12;
int s3 =13;
int res1 ,res2 ,res3;
void setup() {
  pinMode(enA , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(enB , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);

  pinMode(s1 , INPUT);   // middel
  pinMode(s2 , INPUT);   //right
  pinMode(s3 , INPUT);   //left
  

}

void loop() {

res1 = digitalRead(s1);
res2 = digitalRead(s2);
res3 = digitalRead(s3);

if  (  res1== 1 && res2 ==0 && res3 == 0 ) 
{
  
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,250);
        digitalWrite(in3,HIGH); 
        digitalWrite(in4,LOW);
        analogWrite(enB,250);
  
  
  }


else if ( res1== 0 && res2 ==1 && res3 == 0)
{       
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,250);
        
  }



else if ( res1== 0 && res2 ==0 && res3 == 1)
{       digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);
  }

 
}
