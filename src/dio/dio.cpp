#include"..\..\include\dio\dio.h"

Button2 ButtonPlus;
Button2 ButtonMinus;

unsigned long ButtonCounterPressedTime = 0;
unsigned long ElapsedTimeCounter = 0;

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

void ButtonCheck(Button2& btn)
{
  //ButtonPlus.loop();
  //ButtonMinus.loop();
}

void ButtonHandler(Button2& btn)
{
  switch(btn.getType())
  {
        case single_click:
            break;
        case double_click:
            //Serial.print("double ");
            break;
        case long_click:
            //Serial.print("long");
            break;
        case empty:
            return;
  }
}

void ButtonHandlerNext(Button2& btn)
{
/*   ButtonCounterPressedTime+=1;
  if(ButtonCounterPressedTime==2)
  {
    ElapsedTimeCounter=millis();
  } */
}

void ButtonHandlerNextPressed(Button2& btn)
{
/*   ButtonCounterPressedTime--;
  if (ButtonCounterPressedTime == 0) {
    if (ElapsedTimeCounter != 0) {
      Serial.print("Pressed for: ");
      Serial.print(millis() - ElapsedTimeCounter);
      Serial.println("ms"); 
    }
    ElapsedTimeCounter = 0;
  } */
}

int ReadButtonPlus()
{
  
  ButtonPlus.loop();
  // make the pushbutton's pin an input:
  pinMode(ButtonPlusPin, INPUT);
  
  int buttonState=0;

    buttonState = digitalRead(ButtonPlusPin);
    return buttonState;
}

int ReadButtonMinus()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonMinusPin, INPUT);
  
  int buttonState=0;

    buttonState = digitalRead(ButtonMinusPin);

  return buttonState;
}

int ReadButtonOk()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonOkPin, INPUT);
  
  int buttonState=0;

  //  buttonState = digitalRead(ButtonOkPin);

  return buttonState;
}

int ReadButtonCancel()
{
  // make the pushbutton's pin an input:
  pinMode(ButtonCancelPin, INPUT);
  
  int buttonState=0;

  //  buttonState = digitalRead(ButtonCancelPin);

  return buttonState;
}
