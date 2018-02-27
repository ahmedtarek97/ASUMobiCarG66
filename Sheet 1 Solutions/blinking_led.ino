const short led = 7;
 const short  swichpin1 =6; 
 const short switchpin2=5;
void setup() {
  // put your setup code here, to run once:
pinMode (led , OUTPUT );
pinMode (swichpin1 ,INPUT );
pinMode (switchpin2 ,INPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
bool on= digitalRead (6);
bool off=digitalRead (5); 
if (on == HIGH){
digitalWrite (led , HIGH);
}
else if (off ==HIGH) {
  digitalWrite (led , LOW);
  }
}
