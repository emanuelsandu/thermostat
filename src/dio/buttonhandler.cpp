#include"..\include\glob.h"

void DioReadButtons()
{
  ButtonPlus.loop();
  ButtonMinus.loop();
}

void DioButtonHandler(Button2& btn)
{ 
  if(btn==ButtonPlus){
    Dio_ButtonPlus=DioButtonHandlerReadClickType(btn);
  }
  if(btn==ButtonMinus){
    Dio_ButtonMinus=DioButtonHandlerReadClickType(btn);
  }
  
}

byte DioButtonHandlerReadClickType(Button2& btn)
{
    byte result;
    result=Dio_ButtonClear;
    switch(btn.getType())
    {
        case single_click:
            result=Dio_ButtonSingleClick;
            break;
        case double_click:
            result=Dio_ButtonDoubleClick;
            break;
        case triple_click:
            result=Dio_ButtonTripleClick;
            break;
        case long_click:
            result=Dio_ButtonLongClick;
            break;
        case empty:
            result=Dio_ButtonError;
            break;
        default:
            result=Dio_ButtonClear;
            break;
    }
    return result;
}

void DioButtonHandlerNext(Button2& btn)
{
    ButtonCounterPressedTime+=1;
    if(ButtonCounterPressedTime==2)
    {
      ElapsedTimeCounter=millis();
      Dio_ButtonSoftGP=Dio_ButtonOkClick;
    } 
}

void DioButtonHandlerNextPressed(Button2& btn)
{
    ButtonCounterPressedTime--;
    if (ButtonCounterPressedTime == 0) {
      if (ElapsedTimeCounter != 0) { 
      }
      ElapsedTimeCounter = 0;
    } 
}


#if (__DEBUG_MODE__==1)

byte DioReadButtonPlus()
{
  
  // make the pushbutton's pin an input:
  pinMode(DioButtonPlusPin, INPUT);
  
  byte buttonState=0;

    buttonState = digitalRead(DioButtonPlusPin);
    return buttonState;
}

byte DioReadButtonMinus()
{
  
  // make the pushbutton's pin an input:
  pinMode(DioButtonMinusPin, INPUT);
  
  byte buttonState=0;

    buttonState = digitalRead(DioButtonMinusPin);

  return buttonState;
}

byte DioReadButtonOk()
{
  byte buttonState=0;

  return buttonState;
}

byte DioReadButtonCancel()
{
  byte buttonState=0;

  return buttonState;
}

#endif