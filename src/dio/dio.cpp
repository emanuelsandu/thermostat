#include"..\include\glob.h"


unsigned long ButtonCounterPressedTime = 0;
unsigned long ElapsedTimeCounter = 0;

byte      Dio_ButtonPlus;
byte      Dio_ButtonMinus;
byte      Dio_ButtonCancel;
byte      Dio_ButtonSoftGP;

byte DioInit()
{
  //DioButtonSetup();
  pinMode(DioButtonPlusPin, INPUT);
  pinMode(DioButtonMinusPin, INPUT);
  return 0;
}
