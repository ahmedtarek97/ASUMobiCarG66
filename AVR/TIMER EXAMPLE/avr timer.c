#include <avr/io.h>
#include <avr/interrupt.h>
 
#define LEDPIN 2
 ISR(TIMER1_COMPA_vect)
{
    digitalWrite(LEDPIN, !digitalRead(LEDPIN));
}

void setup()
{
    pinMode(LEDPIN, OUTPUT);
 
    // initialize Timer1
    cli();          
    TCCR1A = 0;     
    TCCR1B = 0;     
    OCR1A = 15624;

    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1 << OCIE1A);

    sei();
}
 
void loop()
{
  
}
