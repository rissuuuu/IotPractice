#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
void setup() {
  
lcd.begin();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Rishav Paudel");
lcd.setCursor(0,1);
lcd.print("********");
lcd.setCursor(12,1);
lcd.print("Its your name");
}

void loop() {

}
