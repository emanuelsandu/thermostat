#ifndef DIO__H
#define DIO_H

#include <Button2.h>
#include "..\config.h"


void ButtonInit();
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