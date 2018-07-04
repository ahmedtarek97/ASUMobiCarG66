// Right Side Motors
int enA = 9,in1=8,in2=7;

// Left Side Motors
int enB = 3,in3=5,in4=4;
//reading data for the 3 sensors //zero for black and 1 for white 
int data1,data2,data3;//data1 for center, data2 for right,data3 for left
int r1=10,r2=11,r3=12;// r1 for center,r2 for right, r3 for left;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(enB , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  pinMode(r1,INPUT);
  pinMode(r2,INPUT);
  pinMode(r3,INPUT); 
}

void loop() {
   data1 =digitalRead(r1);
   data2 =digitalRead(r2);
   data3 =digitalRead(r3);
   Serial.print("data1  =   ");
   Serial.println(data1);

    Serial.print("data2  =   ");
   Serial.println(data2);
    Serial.print("data3  =   ");
   Serial.println(data3);
   

   

  if(data1==HIGH&&data2==HIGH&&data3==HIGH)//the three sensors see white
  {//stop
        
    }
else if(data1==LOW&&data2==HIGH&&data3==HIGH)//the middle sees black while the others white
{
        //FORWARD
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,60);
        digitalWrite(in3,HIGH); 
        digitalWrite(in4,LOW);
        analogWrite(enB,60);
  }

else if(data1==LOW&&data2==HIGH&&data3==LOW)//the middle and left see black while the right sees others white
{
        //FORWARD LEFT
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,60);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,0);
  }
else if(data1==LOW&&data2==LOW&&data3==HIGH)//the middle and right see black while the left sees  white
{
      // FORWARD RIGHT
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,0);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,60);
     
  }

 else if(data1==HIGH&&data2==HIGH&&data3==LOW)//the middle and right see white while the left sees  black
 {
    //FORWARD LEFT
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        analogWrite(enA,60);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,0);
  }

 else if(data1==HIGH&&data2==LOW&&data3==HIGH)//the middle and left see white while the right sees  black
 {
  // FORWARD RIGHT
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,0);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,60);
  }
  
      /*  //REVERSE
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);
      //BACKWARD LEFT 
        digitalWrite(in1,LOW);
        digitalWrite(in2,HIGH);
        analogWrite(enA,250);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,0);
      //BACKWARD RIGHT
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        analogWrite(enA,0);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
        analogWrite(enB,250);*/
}

