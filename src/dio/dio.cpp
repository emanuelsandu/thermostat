#include"..\include\glob.h"

Button2 ButtonPlus;
Button2 ButtonMinus;

unsigned long ButtonCounterPressedTime = 0;
unsigned long ElapsedTimeCounter = 0;

byte      Dio_ButtonPlus;
byte      Dio_ButtonMinus;
byte      Dio_ButtonCancel;
byte      Dio_ButtonSoftGP;

byte DioInit()
{
  DioButtonSetup();
  return 0;
}
