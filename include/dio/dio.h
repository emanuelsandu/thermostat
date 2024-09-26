#ifndef DIO__H
#define DIO_H

#include "..\glob.h"
#include <Button2.h>


#define ButtonLongPressTime_ms  3000

#define Dio_ButtonClear         0
#define Dio_ButtonSingleClick   1
#define Dio_ButtonDoubleClick   2
#define Dio_ButtonTripleClick   3
#define Dio_ButtonLongClick     10
#define Dio_ButtonError         255

#define Dio_ButtonOkClick   1

extern Button2 ButtonPlus;
extern Button2 ButtonMinus;

extern unsigned long ButtonCounterPressedTime;
extern unsigned long ElapsedTimeCounter;

extern byte      Dio_ButtonPlus;
extern byte      Dio_ButtonMinus;
extern byte      Dio_ButtonCancel;
extern byte      Dio_ButtonSoftGP;


byte DioInit();
void DioButtonSetup();
void DioReadButtons();
void DioButtonHandler(Button2& btn);
void DioButtonHandlerNext(Button2& btn);
void DioButtonHandlerNextPressed(Button2& btn);
byte DioReadButtonPlus();
byte DioReadButtonMinus();
byte DioReadButtonOk();
byte DioReadButtonCancel();
byte DioButtonHandlerReadClickType(Button2& btn);



#endif