//this code in case the app can not differentiate between different phases internally including phase 3
char phase;//to get the phase
char dataChar;
int dataInt, fwdDist;

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

//speed of moving
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
    Serial.print(phase);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(2000);

    if (distance < 15)
    {
      Stop();
      //we can add buzzer here
    }
    //phase 1
    if (phase == 'P') //this if statement will make the car move according to phase 1
    {
      delay(2000);
      while (1)
      {
        if (Serial.available() > 0)
        {
          dataChar = Serial.read();
          Serial.print(dataChar);
          speed = 250;
          switch (dataChar)
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

            default: //If bluetooth module receives any value not listed above, both motors turn off
              //or we will make a button send X to exit the phase
              Stop();
          }

        }
        if (dataChar == 'N');
        {
          break;
        }
      }
    }
    dataChar = 'S'; //to change value of data from previous step//or we can make the value of data=phase
    //phase 2
        else if(phase == 'T') //this if statement will make the car move according to phase 2
    {
      delay (2000);
      speed = 50;
      while (1)
      {
        if (Serial.available() > 0)
        {
          dataChar = Serial.read();
          Serial.print(dataChar);
        }
        if (dataChar == 'N');
        {
          break;
        }
        LineTracking(speed);
      }
    }


    //phase 3
    else if(phase == 'M')
    {
      dataInt == Serial.read();
      Serial.print(dataInt);
      //it depends on encoder cycles
      speed = 75;
      fwdDist = dataInt / 5 * 1000;
      Forward(speed);
      delay(fwdDist);
    }

    else if(phase == 'D')
    {
      dataInt == Serial.read();
      Serial.print(dataInt);
      //it depends on angle and what we are going to use
      speed = 75;
      fwdDist = dataInt / 10 * 500;
      Right(speed);
      delay(fwdDist);
    }


    else if(phase == 'X')
    {
      //move in infinite shape waiting 25 seconds and then move in rectangle waiting 25 seconds and then move in circle waiting 25 seconds
    }

  }
}
