#include <avr/io.h>
#include <avr/interrupt.h>

byte ledPin = 9;

void setup(void)
{
  Serial.begin( 9600 );
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);    // Enable pullup resistor
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  EICRA |= (1 << ISC01);    // Trigger on falling edge
  EIMSK |= (1 << INT0);     // Enable external interrupt INT0
  sei();                    // Enable global interrupts
}

ISR(INT0_vect)
{
  digitalWrite(13, !digitalRead(13));    // Toggle LED on pin 13
  Serial.println("Interrupted!");
}

void loop(void)
{
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }

  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5){
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}
