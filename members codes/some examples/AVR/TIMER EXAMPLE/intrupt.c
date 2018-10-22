#include <inttypes.h>           //short forms for various integer types
#include <avr/io.h>
#include <avr/interrupt.h>      //file to be included if using interrupts

#define XTAL        4000000L    // Crystal frequency in Hz
#define TIMER_CLOCK       2     // LED flashing frequency in 1Hz

static volatile uint8_t led;     // use volatile when variable is accessed from interrupts

ISR(TIMER1_COMPA_vect)    // handler for Output Compare 1 overflow interrupt
{
    PORTB = led;
    led <<= 1;                   // move to next LED 
    if (!led)                    // overflow: start with bit 0 again 
        led = 1;
}

int main(void)
{
    DDRB  = 0xff;                // use all pins on PortB for output 
    PORTB = 0xff;                // and turn off all LEDs
    TCCR1B = _BV(CS10) | _BV(CS11)  | _BV(WGM12); // prescaler=64, clear timer/counter on compareA match 
    OCR1A = ((XTAL/2/64/TIMER_CLOCK) - 1 );
    // enable Output Compare 1 overflow interrupt
    TIMSK  = _BV(OCIE1A);
    led = 1;                     // init variable representing the LED state 
    sei();                       // enable interrupts 
    for (;;) {}                  // loop forever   
}
