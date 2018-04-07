int lightlength = 1;
#define increasebutten 2
#define decreasebutten 3
#define led 13

void increas_x () {
  
  lightlength++;
  
  }
  void decreas_x () {
  
  lightlength--;
  
  }

void setup() {
  interrupts ();
  
   pinMode (led,OUTPUT);
   pinMode (increasebutten,INPUT);
   pinMode (decreasebutten,INPUT);
  
 
  attachInterrupt (0,increas_x,RISING);
  
  attachInterrupt (1,decreas_x,RISING);

  digitalWrite (led ,HIGH);
  delay (lightlength *1000);

}

void loop() {
 
}
