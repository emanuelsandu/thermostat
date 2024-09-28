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


extern unsigned long ButtonCounterPressedTime;
extern unsigned long ElapsedTimeCounter;

extern byte      Dio_ButtonPlus;
extern byte      Dio_ButtonMinus;
extern byte      Dio_ButtonCancel;
extern byte      Dio_ButtonSoftGP;


byte DioInit();
void DioButtonSetup();
void DioReadButtons();
byte DioReadButtonPlus();
byte DioReadButtonMinus();
byte DioReadButtonOk();
byte DioReadButtonCancel();


extern byte ButtonPlusPressedCounter;
extern byte ButtonPlusReleasedCounter;
extern byte ButtonPlusState;
extern byte ButtonPlusStatePrevious;
extern byte ButtonPlusEvent;
extern byte ButtonPlusEventPrevious;
extern byte ButtonMinusCounter;
extern byte ButtonMinusState;
extern byte ButtonMinusStatePrevious;
extern byte DelayNextRead;

#endif