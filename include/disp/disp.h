#ifndef DISP_H
#define DISP_H

#include <LiquidCrystal_I2C.h>
#include "..\config.h"

void DisplayInit();
void DisplaySetup();
void DisplayClear();
void DisplayWrite(int setTemp);

#endif