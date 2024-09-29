#include"..\include\glob.h"


DioButton DioButtonPlus;
DioButton DioButtonMinus;

void DioButtonSetup()
{
    DioButtonPlus.Init(DioButtonPlusPin);
    DioButtonMinus.Init(DioButtonMinusPin);
}
