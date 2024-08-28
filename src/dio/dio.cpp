#include"..\..\include\dio\dio.h"


void ReadButtonPlus()
{
  
  // make the pushbutton's pin an input:
  pinMode(ButtonPlus, INPUT);
  
  int buttonState;

    buttonState = digitalRead(ButtonPlus);
}