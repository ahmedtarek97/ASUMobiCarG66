//to get the character from blutooth
char phase;//to get the phase
char dataChar;

// Right Side Motors
int enA = 9 , in1 = 8, in2 = 10;

// Left Side Motors
int enB = 3, in3 = 2, in4 = 4;

//Avoid Obstacles
int AvPin = 7;
int AvData;

//reading data for the 3 infrared sensors //zero for black and 1 for white
int dataCenter, dataRight, dataLeft; //dataCenter for center sensor, dataRight for right sensor,dataLeft for left sensor

//pins of infrared sensors
int irCenter = 12, irRight = 13, irLeft = 11; // irCenter for center,irRight for right, irLeft for left;

//phase 3 variables
unsigned int integerValue = 0;
char incomingByte;
unsigned int counter = 0;
int firstintur = 5; //pin of the encoders
int trial;




int speed;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA , OUTPUT);
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(enB , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  pinMode(AvPin, INPUT);
  pinMode(irCenter, INPUT);
  pinMode(irRight, INPUT);
  pinMode(irLeft, INPUT);
  pinMode(firstintur, INPUT);
}


void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
void Reverse(int speed)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speed);
}

void Forward(int speed)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speed);
}
void Right(int speed)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speed);

}

void Left(int speed)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speed);
}

void ForwardLeft(int speed)
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void ForwardRight(int speed)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speed);
}

void BackwardLeft(int speed)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speed);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void BackwardRight(int speed)
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speed);
}

void LineTracking(int speed)
{
  dataCenter = digitalRead(irCenter);
  dataRight = digitalRead(irRight);
  dataLeft = digitalRead(irLeft);
  Serial.print("dataCenter  =   ");
  Serial.println(dataCenter);
  Serial.print("dataRight  =   ");
  Serial.println(dataRight);
  Serial.print("dataLeft  =   ");
  Serial.println(dataLeft);

  if (dataCenter == HIGH && dataRight == HIGH && dataLeft == HIGH) //the three sensors see white
  {
    //keep the same state nothing is changed
  }
  else if (dataCenter == LOW && dataRight == HIGH && dataLeft == HIGH) //the middle sees black while the others white
  { //forward
    Forward(speed);
  }
  else if (dataCenter == LOW && dataRight == HIGH && dataLeft == LOW) //the middle and left see black while the right sees others white
  { //LEFT
    Left(speed);
  }
  else if (dataCenter == LOW && dataRight == LOW && dataLeft == HIGH) //the middle and right see black while the left sees  white
  { //RIGHT
    Right(speed);
  }
  else if (dataCenter == HIGH && dataRight == HIGH && dataLeft == LOW) //the middle and right see white while the left sees  black
  { // LEFT
    Left(speed);
  }
  else if (dataCenter == HIGH && dataRight == LOW && dataLeft == HIGH) //the middle and left see white while the right sees  black
  {
    // RIGHT
    Right(speed);
  }
}


void loop()
{
 

  if (Serial.available() > 0)
  {
    phase = Serial.read();
    Serial.print(phase);
  }

  //phase 1
  speed = 250;
  switch (phase)
  {
    case 'B': //REVERSE
      Reverse(speed);
      break;

    case 'F': //FORWARD
      AvData=digitalRead(AvPin);
      if(AvData==LOW)
      {
        Reverse(100);
       }
      else {Forward(100);}
      break;

    case 'R': //RIGHT
      Right(speed);
      break;

    case 'L': //LEFT
      Left(speed);
      break;

    case 'Q': //FORWARD LEFT
      ForwardLeft(speed);
      break;

    case 'E':  // FORWARD RIGHT
      ForwardRight(speed);
      break;

    case 'Z': //BACKWARD LEFT
      BackwardLeft(speed);
      break;

    case 'C': //BACKWARD RIGHT
      BackwardRight(speed);
      break;

    case 'S': //Stop
      Stop();
      break;
      
    default:
      break;

  }
  //phase2
  if (phase == 'T')
  {
    speed = 80;
    LineTracking(speed);

  }

  //phase 3
  if (phase == 'K')
  {
    while (1)
    {
      delay(1000);
      if (Serial.available() > 0)
      {
        integerValue = 0;
        while (1)
        { delay(1000);
          incomingByte = Serial.read();
          if (incomingByte == 'M' || incomingByte == 'D' || incomingByte == 'X') break;
          integerValue *= 10;
          integerValue = ((incomingByte - 48) + integerValue);
        }
        Serial.println(integerValue);
      }

      if (incomingByte == 'M')
      {
        //send to function of distance
        Serial.println("the car is moving ahead ## centimeters");
        go(integerValue);
        phase = 'S';
        break;
      }
      else if (incomingByte == 'D')
      {
        //send to function of degrees
        Serial.println("the car is moving by ## degrees");
        degree(integerValue);
        phase = 'S';
        break;
      }
      else if (incomingByte == 'X')
      {
        //send to the function of shapes
        Serial.println("The car is moving according to the shapes");
        draw();
        phase = 'S';
        break;
      }
     
    }
  }
}


//phase 3 functions
void go(int x)
{
  counter = 0;
  float number = 20 * x / (63) ; //calculate number of counts that needed for this distance
  Serial.println(number);
  while ( counter <= number )
  {
    Forward(50);//go forward
    if (digitalRead(5) == HIGH)
    {
      if (digitalRead(5) == LOW) //this structure because we count faling edge
      {
        Serial.println(counter);
        counter++;  // increase +1 the counter value
      }
      if (counter > number) {
        break;
      }
    }
  }
  Stop();//stop the car
}


void degree(int y)//the range of rotation is from 0 to 360 don't forget to put asssume value
{
  counter = 0; //initial count to 0 again
  float number = (36 * y) / 360 ; //time of delay in milly//48 moves 480 angles   36 makes a complete cycle(360)
  Serial.println(number);
  //  make car moves right for a certain time
  while ( counter <= number )
  {
    trial = digitalRead(5);
    Right(100);//go forward
    if (trial == HIGH)
    {
      if (digitalRead(5) == LOW) //this structure because we count faling edge
      {
        Serial.println(counter);
        counter++;  // increase +1 the counter value
      }
      if (counter > number) {
        break;
      }
    }
  }
  Stop();//stop the car
}


void Rec(int x, int y) //to make any rectangular
{
  go(x);
  degree(90);
  //Right(250);
  //delay(230);
  go(y);
   degree(90);
  //Right(250);
  //delay(230);
  go(x);
  degree(90);
  //Right(250);
  //delay(230);
  go(y);
  degree(90);
  //Right(250);
  //delay(230);
  Stop();
  delay(100);
}

void circle ()//assume that forward right function make car to move in circle just measure the time of this
{
  int i = 0;
  for (i = 0; i < 60; i++)
  {
    ForwardRight(130);
    delay (100);
    Forward(100);
    delay(100);
    //stop the car
    Stop();
    delay(10);
  }
}

void RightCircle ()//right circle for infinity
{
  int i = 0;
  for (i = 0; i < 38; i++)
  {
    ForwardRight(120);
    delay (150);
    Forward(100);
    delay(100);
    //stop the car
    Stop();
    delay(10);
  }
}

void LeftCircle ()//left circle for infinity
{
  int i = 0;
  for (i = 0; i < 60; i++)
  {
    ForwardLeft(140);
    delay (150);
    Forward(100);
    delay(100);
    //stop the car
    Stop();
    delay(10);
  }
}

void infinityshape()
{
  RightCircle();
  LeftCircle();
}

void draw()
{
  Rec(200, 200);
  delay (5000);
  circle ();
  delay (5000);
  infinityshape();
  delay (5000);
  Serial.println("DRAW FUNCTION ");
}
/*****************/


