
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(2,0);
  lcd.print("hello, world!");
  delay(1000);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available()>0)
  {
    lcd.setCursor(1,1);
    lcd.print(Serial.readString());
  }
}
 