#ifndef DISP_H
#define DISP_H

//https://arduinogetstarted.com/tutorials/arduino-lcd-i2c

#include "..\glob.h"
#include <LiquidCrystal_I2C.h>


#define FirstRow 0
#define SecondRow 1
#define CursorStart0 0

#define degC char(223)+"C"


extern byte DispHeatingSymbolActive;

short DispInit();
void DisplaySetup();
void DisplayClear();
void DisplayWriteMainPage();
void DisplayMessage(const char *cDispMsgBuf);
void DisplayMessageRow2(const char *cDispMsgBuf);
void DisplayHeatingSymbol();
void DisplayClearHeatingSymbol();

void DisplayComStatusSymbol();

#endif