int motorPin1 = 10;
int motorPin2 = 11;
int motorPin3 = 5;
int motorPin4 = 6;
char data = 0; 

void setup() 
{
 Serial.begin(9600);
 pinMode(motorPin1,OUTPUT); 
 pinMode(motorPin2,OUTPUT); 
 pinMode(motorPin3,OUTPUT); 
 pinMode(motorPin4,OUTPUT); 
}

void loop() 
{
 
  if (Serial.available() > 0) 
{ 
 data = Serial.read(); 
   if(data == '1')        //move forwards 
 { 
   digitalWrite(motorPin1,HIGH); 
   digitalWrite(motorPin2,LOW); 
   digitalWrite(motorPin3,HIGH); 
   digitalWrite(motorPin4,LOW); 
 } 
 
   else if (data == '2')       //move backwards 
 { 
   digitalWrite(motorPin1,LOW); 
   digitalWrite(motorPin2,HIGH); 
   digitalWrite(motorPin3,LOW); 
   digitalWrite(motorPin4,HIGH); 
 } 
   else if (data == '3')       //move forward left 
 { 
   digitalWrite(motorPin1,LOW); 
   digitalWrite(motorPin2,HIGH); 
   digitalWrite(motorPin3,HIGH); 
   digitalWrite(motorPin4,LOW); 
 } 
   else if (data == '4')       //move forward right 
 { 
   digitalWrite(motorPin1,HIGH); 
   digitalWrite(motorPin2,LOW); 
   digitalWrite(motorPin3,LOW); 
   digitalWrite(motorPin4,HIGH); 
 } 

  }
}
