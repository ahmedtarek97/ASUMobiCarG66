unsigned int counter=0;
int x; //distance you need in cm 
int firstintur=5;//pin of the encoders






//

void go(int x)
{
  float number = 12 * x / 18;//calculate number of counts that needed for this distance
  while ( counter <= number )
  {
    Forward(200);//go forward
    if(digitalRead(2)==HIGH)
    {
      if(digitalRead(2)==LOW)//this structure because we count faling edge 
        {
        counter++;  // increase +1 the counter value
        }
    }
  }
  Stop();//stop the car 
  counter=0;//initial count to 0 again 
}
