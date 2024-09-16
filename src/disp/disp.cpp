#include"..\include\disp\disp.h"

LiquidCrystal_I2C Display16x2=LiquidCrystal_I2C(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void DisplaySetup()
{
    Display16x2.init();
    Display16x2.backlight();
    Display16x2.noCursor();
    Display16x2.noBlink();
}

void DisplayClear()
{
    Display16x2.clear();
}

void DisplayWrite(int setTemp)
{
    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("Set: ");
    Display16x2.print(setTemp);
    Display16x2.setCursor(CursorStart0,SecondRow);
    Display16x2.print("Room: ");
}
