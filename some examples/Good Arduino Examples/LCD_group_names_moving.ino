

#include <LiquidCrystal.h>
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);

}

void loop() {

  lcd.setCursor(2, 0);
  lcd.print("ASUMobiCarG66");
  delay(1000);
  lcd.setCursor(5, 1);
  lcd.print("AHMADS");
  delay(1000);

  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear();
  /*****************************/
  lcd.setCursor(3, 0);
  lcd.print("ABDELSALAM");
  delay(1000);
  lcd.setCursor(5, 1);
  lcd.print("TALAAT");
  delay(1000);
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear();
  /************************/
  lcd.setCursor(6, 0);
  lcd.print("TAREK");
  delay(1000);
  lcd.setCursor(6, 1);
  lcd.print("GALAL");
  delay(1000);
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear();
  /********************/
  lcd.setCursor(6, 0);
  lcd.print("SAYED");
  delay(1000);
  lcd.setCursor(6, 1);
  lcd.print("NASR");
  delay(1000);
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear();
  /******************/
  lcd.setCursor(5, 0);
  lcd.print("KHALED");
  delay(1000);
  lcd.setCursor(6, 1);
  lcd.print("ALI");
  delay(1000);
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear();
  /**********************/

  lcd.setCursor(4, 0);
  lcd.print("SHERIEF");
  delay(1000);
  lcd.setCursor(2, 1);
  lcd.print("ELSHERIEF");
  delay(1000);
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int positionCounter = 0; positionCounter < 14; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(150);
  }
  delay(1000);
  lcd.clear();

}


