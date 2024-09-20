#include"..\include\glob.h"

Button2 ButtonPlus;
Button2 ButtonMinus;

unsigned long ButtonCounterPressedTime = 0;
unsigned long ElapsedTimeCounter = 0;

int iDioInit()
{
  ButtonSetup();
  DisplayMessageRow2("DIO_INIT_OK");
  return 0;
}
