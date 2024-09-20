#ifndef DIO__H
#define DIO_H

#include "..\glob.h"
#include <Button2.h>

#define ButtonLongPressTime_ms 3000

extern Button2 ButtonPlus;
extern Button2 ButtonMinus;

extern unsigned long ButtonCounterPressedTime;
extern unsigned long ElapsedTimeCounter;

int iDioInit();
void ButtonSetup();
void ButtonCheck(Button2& btn);
void ButtonHandler(Button2& btn);
void ButtonHandlerNext(Button2& btn);
void ButtonHandlerNextPressed(Button2& btn);
int ReadButtonPlus();
int ReadButtonMinus();
int ReadButtonOk();
int ReadButtonCancel();

#endif