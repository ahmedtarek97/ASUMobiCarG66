const int dipS[8] = {2,3,4,5,6,7};
const int x=13;
int val=0 ;
int t ;
void setup() {
  for(int i=0;i<6;i++){
    pinMode (dipS[i],INPUT) ;
  }
pinMode(x,OUTPUT);
}

void loop() {
for(int j=0;j<6;j++)
{
    val = 0 ;
    t = digitalRead(dipS[j]) ;
    for(int k=0;k<j;k++)
    {
      t = t * 2 ;
    }
    val = val + t ;
}
 digitalWrite(x,HIGH) ;
  delay(val*4);
 digitalWrite(x,LOW) ;
}