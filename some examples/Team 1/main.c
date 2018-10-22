#define F_CPU 16000000UL //16 MHz

#define DDR_MOTOR DDRB
#define PORT_MOTOR PORTB
#define UART_H_

#define BIT_SET(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define BIT_CLEAR(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define BIT_CHECK(ADDRESS,BIT) (ADDRESS & (1<<BIT))
#define BIT_FLIP(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))

#include <avr/io.h>

void UART_init(int baud);
void UARD_send_char(char data);
char UARD_receive_char();
  
int8_t in1, in2, in3, in4;
// Right Side Motors
int8_t enA = 9;
int8_t in1 = 1;
int8_t in2 = 2;

// Left Side Motors
int8_t enB = 3;
int8_t in3 = 3;
int8_t in4 = 4;


#include <util/delay.h>

int main(void)
{
	UART_init (9600) ; //initializing the receiver
	char C ;
	BIT_SET(DDR_MOTOR,in1);		//make AVR's pins output
	BIT_SET(DDR_MOTOR,in2);
	BIT_SET(DDR_MOTOR,in3);
	BIT_SET(DDR_MOTOR,in4);
	while(1)
	{
		C = UARD_receive_char(); //receiving a character
		switch ('R'){
		case 'F' ://Forward
		BIT_SET(PORT_MOTOR,in1);
		BIT_CLEAR(PORT_MOTOR,in2);
		BIT_SET(PORT_MOTOR,in3);
		BIT_CLEAR(PORT_MOTOR,in4);
		
		case 'B' : //Backward
		BIT_CLEAR(PORT_MOTOR,in1);
		BIT_SET(PORT_MOTOR,in2);
		BIT_CLEAR(PORT_MOTOR,in3);
		BIT_SET(PORT_MOTOR,in4);
		
		case 'R': //Right
		BIT_CLEAR(PORT_MOTOR,in1);
		BIT_SET(PORT_MOTOR,in2);
		BIT_SET(PORT_MOTOR,in3);
		BIT_CLEAR(PORT_MOTOR,in4);
		
		case 'L' : //Left
		BIT_CLEAR(PORT_MOTOR,in3);
		BIT_CLEAR(PORT_MOTOR,in2);
		BIT_SET(PORT_MOTOR,in4);
		BIT_SET(PORT_MOTOR,in1);
		
		default:
		BIT_CLEAR(PORT_MOTOR,in1);
		BIT_CLEAR(PORT_MOTOR,in2);
		BIT_CLEAR(PORT_MOTOR,in3);
		BIT_CLEAR(PORT_MOTOR,in4);
		
	}
	}
	
	return 0;
}





void UART_init(int baud)
{
	uint16_t UBRR_Value = (F_CPU / (16L * baud)) -1;
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value >> 8);
	UCSRB = (1 << RXEN) | (1 << TXEN); //enable transmitting and receiving
	UCSRC = (3 << UCSZ0); //8-bits
}
void UARD_send_char(char data)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = data;
}
char UARD_receive_char()
{
	while (!(UCSRA & (1 << RXC)));
	return UDR;
}

