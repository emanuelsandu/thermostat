#include"..\include\disp\disp.h"

LiquidCrystal_I2C Display16x2(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

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

void DisplayWrite()
{
    Display16x2.setCursor(0,0);
    Display16x2.print("Set: ");
    Display16x2.setCursor(1,0);
    Display16x2.print("Room: ");
}
