
void setup() {
  
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(13,OUTPUT);
}

int timer = 0;
void loop() {
  
  
  for(int i=2;i<=9;i++)
  {
    timer += digitalRead(i)*pow(2,(i-2));
    
    }
    digitalWrite(13,HIGH);
    delay (timer*4);

}
