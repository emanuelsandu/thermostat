#include"..\include\glob.h"



byte      Dio_ButtonPlus;
byte      Dio_ButtonMinus;
byte      Dio_ButtonSoftGP;

byte DioInit()
{
  DioButtonSetup();
  return 0;
}
