#include"..\..\include\dio\dio.h"

int GetButton();

int ReadButtonPlus()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonPlus, INPUT);
  
  int buttonState=0;

    buttonState = digitalRead(ButtonPlus);
    return buttonState;
}

int ReadButtonMinus()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonMinus, INPUT);
  
  int buttonState=0;

    buttonState = digitalRead(ButtonMinus);

  return buttonState;
}

int ReadButtonOk()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonOk, INPUT);
  
  int buttonState=0;

    buttonState = digitalRead(ButtonOk);

  return buttonState;
}

int ReadButtonCancel()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonCancel, INPUT);
  
  int buttonState=0;

    buttonState = digitalRead(ButtonCancel);

  return buttonState;
}