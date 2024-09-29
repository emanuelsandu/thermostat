#ifndef DIO__H
#define DIO_H

#include "..\glob.h"


#define ButtonLongPressTime_ms  3000

#define Dio_ButtonClear         0
#define Dio_ButtonSingleClick   1
#define Dio_ButtonDoubleClick   2
#define Dio_ButtonTripleClick   3
#define Dio_ButtonLongClick     10
#define Dio_ButtonStuck         254
#define Dio_ButtonError         255

#define Dio_ButtonOkClick   1
#define Dio_ButtonDelClick   2

#define Task50ms_Cycle1s 20 // 20*50=1000ms
#define ShortPressCycles_50ms 1
#define LongPressCycles_50ms 1*Task50ms_Cycle1s
#define ButtonStuckCycles_50ms 10*Task50ms_Cycle1s
#define ButtonClearCycles_50ms 2 


extern byte      Dio_ButtonPlus;
extern byte      Dio_ButtonMinus;
extern byte      Dio_ButtonCancel;
extern byte      Dio_ButtonSoftGP;

class DioButton
{
  public:
    unsigned short ButtonPressedCounter;
    unsigned short ButtonReleasedCounter;
    byte ButtonState;
    byte ButtonStatePrevious;
    byte ButtonEvent;
    byte ButtonEventPrevious;
    uint8_t ButtonPin;
    byte ReadButton();
    void Init(uint8_t btnPin);
};


extern DioButton DioButtonPlus;
extern DioButton DioButtonMinus;

byte DioInit();
void DioButtonSetup();
void DioReadButtons();
byte DioReadButtonPlus();
byte DioReadButtonMinus();
byte DioReadButtonSoftGP();
byte DioReadButtonCancel();


#endif