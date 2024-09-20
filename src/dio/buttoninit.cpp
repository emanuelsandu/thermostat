#include"..\include\glob.h"

void ButtonSetup()
{
  ButtonPlus.begin(ButtonPlusPin);
  ButtonMinus.begin(ButtonMinusPin);

  ButtonPlus.setClickHandler(ButtonHandler);
  ButtonPlus.setDoubleClickHandler(ButtonHandler);
  ButtonPlus.setLongClickDetectedHandler(ButtonHandler);
  //ButtonPlus.setPressedHandler(ButtonHandlerNext);
  //ButtonPlus.setReleasedHandler(ButtonHandlerNextPressed);
  ButtonPlus.setLongClickTime(ButtonLongPressTime_ms);

  ButtonMinus.setClickHandler(ButtonHandler);
  ButtonMinus.setDoubleClickHandler(ButtonHandler);
  ButtonMinus.setLongClickDetectedHandler(ButtonHandler);
  //ButtonMinus.setPressedHandler(ButtonHandlerNext);
  //ButtonMinus.setReleasedHandler(ButtonHandlerNextPressed);
  ButtonMinus.setLongClickTime(ButtonLongPressTime_ms);
}
