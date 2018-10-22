int ledPins[] = {2,3,4,5,6,7,8,9}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9
 
/*
 * setup() - this function runs once when you turn your Arduino on
 * We the three control pins to outputs
 */
void setup()
{
  
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 8; i++){         //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
}
 
 
void loop()                     // run over and over again
{
  //oneAfterAnotherLoop();   //does the same as oneAfterAnotherNoLoop but with 
                             //much less typing
  //oneOnAtATime();          //this will turn one LED on then turn the next one
                             //on turning the 
                             //former off (one LED will look like it is scrolling 
                             //along the line
  //inAndOut();              //lights the two middle LEDs then moves them out then back 
                             //in again
  for (int i=0; i<256; i++) {
    showBinNumber(i);
    delay(1000);
  }
}

void showBinNumber(int num) {
  for (int i=0; i<8; i++) {
    if (num%2)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);
    num/=2;
  } 
}
