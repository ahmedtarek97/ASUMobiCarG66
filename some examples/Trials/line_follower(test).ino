/Define Pins

int ENA = 3; //Enable Pin of the Right Motor (must be PWM)
int IN1 = 1; //Control Pin
int IN2 = 2;

int ENB = 6; //Enable Pin of the Left Motor (must be PWM)
int IN3 = 4;
int IN4 = 5;

//Speed of the Motors
#define ENASpeed 100 
#define ENBSpeed 100

int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  
}

void loop(){

  //Use analogWrite to run motor at adjusted speed
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);

  //Read the Sensor if HIGH (BLACK Line) or LOW (WHITE Line)
  Sensor1 = digitalRead(8);
  Sensor2 = digitalRead(9);
  Sensor3 = digitalRead(10);
  Sensor4 = digitalRead(11);

  //Set conditions for FORWARD, LEFT and RIGHT

  if(Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == LOW && Sensor1 == LOW){

    //Turn LEFT
    //motor A Backward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //motor B Forward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  else if (Sensor4 == LOW && Sensor3 == LOW && Sensor2 == HIGH && Sensor1 == HIGH){

    //Turn RIGHT
    //motor A Forward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //motor B Backward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  else{

    //if(Sensor4 == LOW && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == LOW

    //FORWARD
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}

