#ifndef DISP_H
#define DISP_H

#include "..\glob.h"
#include <LiquidCrystal_I2C.h>

#define FirstRow 0
#define SecondRow 1
#define CursorStart0 0

#define degC char(223)+"C"

short DispInit();
void DisplaySetup();
void DisplayClear();
void DisplayWriteMainPage();
void DisplayMessage(const char *cDispMsgBuf);
void DisplayMessageRow2(const char *cDispMsgBuf);


#endif