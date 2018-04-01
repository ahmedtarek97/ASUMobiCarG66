int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte count;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
}

void loop() {
    dispBinary(count++);
    delay(1000);

}

void dispBinary(byte n)
{
    for (byte i=0; i<8; i++) {
        digitalWrite(ledPins[i], n & 1);
        n /= 2;
    }}
