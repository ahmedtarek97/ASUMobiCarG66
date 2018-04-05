const int analogInPins[] ={A0,A1,A2,A3,A4,A5}; 
const int analogOutPin = 9; 

int sensorValue = 0;        
int outputValue = 0; 
int button  ;    

void setup() {
  pinMode(analogOutPin,OUTPUT);
  
  pinMode(button ,INPUT);
  
  
}
int oldvalue = LOW ;
int newvalue;
void loop(){
  for(int i = 0 ; i < 6 ; i ++){
   newvalue=digitalRead(button);
  if(newvalue==HIGH && oldvalue==LOW){
 i = i + 1 ;
  }
  if(newvalue==LOW && oldvalue==HIGH){
 i = i + 1 ;
  }
  
  sensorValue = analogRead(analogInPins[i]);
  digitalWrite(analogInPins[i],HIGH);
  delay(sensorValue);
  digitalWrite(analogInPins[i],LOW);
  delay(sensorValue);
  oldvalue=newvalue;
  if(i==6)
  i=0;
  }
  }
