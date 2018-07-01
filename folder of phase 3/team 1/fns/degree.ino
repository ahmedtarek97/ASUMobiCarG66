
int y;//angle in degrees
float assume = 888;

void degree(int y)//the range of rotation is from 0 to 360 don't forget to put asssume value 
{
  float wait = ( y * assume ) / 360 ;//time of delay in milly 
  //make car moves right for a certain time 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 30);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 30);
  //make a delay 
  delay (wait);
  //stop the car 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
 }
