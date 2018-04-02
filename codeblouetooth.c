#define F_CPU 16000000UL //16 MHz

#define DDR_MOTOR DDRB
#define PORT_MOTOR PORTB
#define UART_H_





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

