//the last code 
char phase;//to get the phase
char dataChar;
int flag;
// Right Side Motors
int enA = 9 , in1 = 8, in2 = 10;

// Left Side Motors
int enB = 3, in3 = 2, in4 = 4;

//ultrasonic
int trigPin = 6;
int echoPin = 7;
long duration;
int distance;

//reading data for the 3 infrared sensors //zero for black and 1 for white
int dataCenter, dataRight, dataLeft; //dataCenter for center sensor, dataRight for right sensor,dataLeft for left sensor

//pins of infrared sensors
int irCenter = 12, irRight = 13, irLeft = 11; // irCenter for center,irRight for right, irLeft for left;

//phase 3 variables
unsigned int integerValue = 0;
char incomingByte;

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

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(irCenter, INPUT);
  pinMode(irRight, INPUT);
  pinMode(irLeft, INPUT);
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
  { //FORWARD LEFT
    ForwardLeft(speed);
  }
  else if (dataCenter == LOW && dataRight == LOW && dataLeft == HIGH) //the middle and right see black while the left sees  white
  { // FORWARD RIGHT
    ForwardRight(speed);
  }
  else if (dataCenter == HIGH && dataRight == HIGH && dataLeft == LOW) //the middle and right see white while the left sees  black
  { //FORWARD LEFT
    ForwardLeft(speed);
  }
  else if (dataCenter == HIGH && dataRight == LOW && dataLeft == HIGH) //the middle and left see white while the right sees  black
  {
    // FORWARD RIGHT
    ForwardRight(speed);
  }
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  if (Serial.available() > 0)
  {
    phase = Serial.read();
    Serial.println(phase);
  }
  /* if (phase=='T')
    {flag=1;}
    else
    {flag=0;}*/
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  // delay(2000);

  if (distance < 15)
  {
    Stop();
    //we can add buzzer here
  }
  //phase 1
  speed = 250;
  switch (phase)
  {
    case 'B': //REVERSE
      Reverse(speed);
      break;

    case 'F': //FORWARD
      Forward(speed);
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
    speed = 100;
    LineTracking(speed);

  }

  //phase 3
  if (phase == 'K')
  {
    while (1)
    {
      ///////////////
      if (Serial.available() > 0)
      {
        integerValue = 0;
        while (1)
        {
          incomingByte = Serial.read();
          if (incomingByte == 'M' || incomingByte == 'D' || incomingByte == 'X') break;
          //if (incomingByte == -1) continue;
          integerValue *= 10;

          integerValue = ((incomingByte - 48) + integerValue);
        }
        Serial.println(integerValue);
      }

      if (incomingByte == 'M')
      {
        //send to function of distance
        Serial.println("the car is moving ahead ## centimeters");
        break;
      }
      else if (incomingByte == 'D')
      {
        //send to function of degrees
        Serial.println("the car is moving by ## degrees");
        break;
      }
      else if (incomingByte == 'X')
      {
        //send to the function of shapes
        Serial.println("The car is moving according to the shapes");
        break;
      }
      /////////////////////////////////
    }

  }

}
