#include"..\include\glob.h"

void DioButtonSetup()
{
  ButtonPlus.begin(DioButtonPlusPin);
  ButtonMinus.begin(DioButtonMinusPin);

  ButtonPlus.setClickHandler(DioButtonHandler);
  ButtonPlus.setDoubleClickHandler(DioButtonHandler);
  ButtonPlus.setLongClickDetectedHandler(DioButtonHandler);
  ButtonPlus.setPressedHandler(DioButtonHandlerNext);
  ButtonPlus.setReleasedHandler(DioButtonHandlerNextPressed);
  ButtonPlus.setLongClickTime(ButtonLongPressTime_ms);

  ButtonMinus.setClickHandler(DioButtonHandler);
  ButtonMinus.setDoubleClickHandler(DioButtonHandler);
  ButtonMinus.setLongClickDetectedHandler(DioButtonHandler);
  ButtonMinus.setPressedHandler(DioButtonHandlerNext);
  ButtonMinus.setReleasedHandler(DioButtonHandlerNextPressed);
  ButtonMinus.setLongClickTime(ButtonLongPressTime_ms);
}
