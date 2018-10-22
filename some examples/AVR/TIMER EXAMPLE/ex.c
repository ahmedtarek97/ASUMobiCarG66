int main(void) {

  uint8_t i=0;
  LED_DDR = 0xff;             

  while (1) {

    while (i < 7) {
      LED_PORT = (1 << i);               
      _delay_ms(DELAYTIME);                                  
      i = i + 1;                               /* move to the next LED */
    }

    while (i > 0) {
      LED_PORT = (1 << i);                 
      _delay_ms(DELAYTIME);                                   
      i = i - 1;                         
    }

  }                                                  
  return 0;
}
