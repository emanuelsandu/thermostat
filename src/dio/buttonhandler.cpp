#include "..\include\glob.h"

byte ButtonPlusPressedCounter=0;
byte ButtonPlusReleasedCounter=0;
byte ButtonPlusState;
byte ButtonPlusStatePrevious=LOW;
byte ButtonPlusEvent=Dio_ButtonClear;
byte ButtonPlusEventPrevious=Dio_ButtonClear;

byte ButtonMinusPressedCounter=0;
byte ButtonMinusReleasedCounter=0;
byte ButtonMinusState;
byte ButtonMinusStatePrevious=LOW;
byte ButtonMinusEvent=Dio_ButtonClear;
byte ButtonMinusEventPrevious=Dio_ButtonClear;

void DioReadButtons()
{
}

byte DioReadButton(	byte *prevState, 
						byte *currState, 
						byte *pressedCounter, 
						byte *releasedCounter,
						byte *prevEvent,
						byte *currEvent)
{
  byte result;
  prevState=currState;

  if(digitalRead(DioButtonPlusPin)==HIGH)
  {
    if(prevState==LOW)
      *currState=RISING;
    else
      *currState=HIGH;
    result=Dio_ButtonClear;
  }
  else
  {
    if(*prevState==HIGH)
      *currState=FALLING;
    else
      *currState=LOW;
    result=Dio_ButtonClear;
  }
  
  if(*currState==HIGH)
  {
    *pressedCounter+=1;
    *releasedCounter=0;
  }

  if(*currState==LOW)
  {
    *pressedCounter=0;
    *releasedCounter+=1;
  }

  if(*pressedCounter>=255) *pressedCounter=254;
  if(*releasedCounter>=255) *releasedCounter=254;
  
  if(*currState==FALLING && *pressedCounter>50)
    result=Dio_ButtonClear;
  else
    if(*currState==FALLING && *pressedCounter>20)
      result=Dio_ButtonLongClick;
    else
      if(*currState==FALLING && *pressedCounter>2)
		  if(*prevEvent==Dio_ButtonSingleClick && *releasedCounter<5)
			  result=Dio_ButtonDoubleClick;
		  else
			  result=Dio_ButtonSingleClick;

	if (*releasedCounter<5)
		*prevEvent=result;
	else
		*prevEvent=Dio_ButtonClear;
	
  return result;
}

byte DioReadButtonPlus()
{
  byte result;
  result=DioReadButton(&ButtonPlusStatePrevious,&ButtonPlusState,
                        &ButtonPlusPressedCounter,&ButtonPlusReleasedCounter,
                        &ButtonPlusEventPrevious,&ButtonPlusEvent);
  return result;
}


byte DioReadButtonMinus()
{
  byte result;
  result=DioReadButton(&ButtonMinusStatePrevious,&ButtonMinusState,
                        &ButtonMinusPressedCounter,&ButtonMinusReleasedCounter,
                        &ButtonMinusEventPrevious,&ButtonMinusEvent);
  return result;
}

byte DioReadButtonOk()
{
    if(DioReadButtonPlus()==Dio_ButtonLongClick && DioReadButtonMinus()==Dio_ButtonLongClick )
      DisplayMessage("GPSoftBtn PRESSED");
}

byte DioReadButtonCancel()
{
}
