#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>

#define enable            5
#define registerselection 6

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);

static volatile int pulse = 0;
static volatile int i = 0;

int main(void)
{
    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRD = 0b11111011;
    _delay_ms(50);
    
    GICR|=(1<<INT0);
    MCUCR|=(1<<ISC00);
    
    TCCR1A = 0;
    
    int16_t COUNTA = 0;
    char SHOWA [16];
    

    send_a_command(0x01); //Clear Screen 0x01 = 00000001
    _delay_ms(50);
    send_a_command(0x38);
    _delay_ms(50);
    send_a_command(0b00001111);
    _delay_ms(50);
    
    sei();
    
    while(1)
    {
        PORTD|=(1<<PIND0);
        _delay_us(15);
        PORTD &=~(1<<PIND0);
        
        COUNTA = pulse/58;
        send_a_string ("CIRCUIT DIGEST");
        send_a_command(0x80 + 0x40 + 0);
        send_a_string ("DISTANCE=");
        itoa(COUNTA,SHOWA,10);
        send_a_string(SHOWA);
        send_a_string ("cm    ");
        send_a_command(0x80 + 0);

    }
}

ISR(INT0_vect)
{
    if (i==1)
    {
        TCCR1B=0;
        pulse=TCNT1;
        TCNT1=0;
        i=0;
    }
    if (i==0)
    {
        TCCR1B|=(1<<CS10);
        i=1;
    }
}

void send_a_command(unsigned char command)
{
    PORTB = command;
    PORTD &= ~ (1<<registerselection);
    PORTD |= 1<<enable;
    _delay_ms(8);
    PORTD &= ~1<<enable;
    PORTB = 0;
}

void send_a_character(unsigned char character)
{
    PORTB = character;
    PORTD |= 1<<registerselection;
    PORTD |= 1<<enable;
    _delay_ms(8);
    PORTD &= ~1<<enable;
    PORTB = 0;
}
void send_a_string(char *string_of_characters)
{
    while(*string_of_characters > 0)
    {
        send_a_character(*string_of_characters++);
    }
}
