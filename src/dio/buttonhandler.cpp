#include "..\include\glob.h"



void DioReadButtons()
{
  Dio_ButtonPlus=DioButtonPlus.ReadButton();
  Dio_ButtonMinus=DioButtonMinus.ReadButton();
  Dio_ButtonSoftGP=DioReadButtonSoftGP();
}

void DioButton::Init(uint8_t btnPin)
{
    ButtonPin=btnPin;

    ButtonEvent=Dio_ButtonClear;
    ButtonEventPrevious=Dio_ButtonClear;

    ButtonPressedCounter=0;
    ButtonReleasedCounter=0;

    ButtonState=LOW;
    ButtonStatePrevious=LOW;

    pinMode(ButtonPin,INPUT);
}

byte DioButton::ReadButton()
{
  byte result;
  ButtonStatePrevious=ButtonState;


  if(digitalRead(ButtonPin)==HIGH)
  {
    if(ButtonStatePrevious==LOW)
      ButtonState=RISING;
    else
      ButtonState=HIGH;
    result=Dio_ButtonClear;
  }
  else
  {
    if(ButtonStatePrevious==HIGH)
      ButtonState=FALLING;
    else
      ButtonState=LOW;
    result=Dio_ButtonClear;
  }
  
  if(ButtonState==HIGH)
  {
    ButtonPressedCounter+=1;
    ButtonReleasedCounter=0;
  }

  if(ButtonState==LOW)
  {
    ButtonPressedCounter=0;
    ButtonReleasedCounter+=1;
  }

  if(ButtonPressedCounter>=1024) ButtonPressedCounter=1023;
  if(ButtonReleasedCounter>=1024) ButtonReleasedCounter=1023;
  
  if( ButtonState==FALLING )
  {
    if( ButtonPressedCounter>=ButtonStuckCycles_50ms )
      result=Dio_ButtonClear;
    else
      if( ButtonPressedCounter>=LongPressCycles_50ms )
        result=Dio_ButtonLongClick;
      else
        if( ButtonPressedCounter>=ShortPressCycles_50ms )
          if( ButtonEventPrevious==Dio_ButtonSingleClick && ButtonReleasedCounter<=ButtonClearCycles_50ms )
            result=Dio_ButtonDoubleClick;
          else
            result=Dio_ButtonSingleClick;
  }

	if (ButtonReleasedCounter<ButtonClearCycles_50ms)
		ButtonEventPrevious=result;
	else
		ButtonEventPrevious=Dio_ButtonClear;
	
  return result;
}

byte DioReadButtonPlus()
{
  byte result;
  result=DioButtonPlus.ReadButton();
  return result;
}


byte DioReadButtonMinus()
{
  byte result=Dio_ButtonClear;
  result=DioButtonMinus.ReadButton();
  return result;
}

byte DioReadButtonSoftGP()
{
  byte result=Dio_ButtonClear;
  if( Dio_ButtonPlus==Dio_ButtonLongClick )
    result=Dio_ButtonOkClick;  
  //if( Dio_ButtonMinus==Dio_ButtonLongClick )
  //  result=Dio_ButtonDelClick;  
  return result;
}

byte DioReadButtonCancel()
{
}
