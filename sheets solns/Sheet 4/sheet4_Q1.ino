int min_temp= 20;
int max_temp= 50;
int temprature;
int  fan_speed;

void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT); //THE PIN OF THE FAN
pinMode(A1,INPUT); //output of sensor
}

void loop() {
  // put your main code here, to run repeatedly:
  
temprature = analogRead(A1);
  if(temprature < min_temp) 
  {   
      digitalWrite(10, LOW); 
   } 
    if((temprature >=  min_temp) && (temprature <= max_temp)) 
    { 
       fan_speed = map(temprature, min_temp, max_temp, 32, 255); 
      analogWrite(10,  fan_speed);  
   } 

   
}
