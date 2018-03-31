float temp;
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
 float read=analogRead(A0);
 read=read*5000/1024;
  temp=(read-500)/10;//sensitivity
  lcd.setCursor(4, 1);
  lcd.print("temp=");
  lcd.print(temp);
  lcd.print("C");
  
}
 