#ifndef DISP_H
#define DISP_H

#include <LiquidCrystal_I2C.h>
#include "..\glob.h"

#define FirstRow 0
#define SecondRow 1
#define CursorStart0 0

void DisplaySetup();
void DisplayClear();
void DisplayWrite();

#endif