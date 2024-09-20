#ifndef GLOB_H
#define GLOB_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\include\aio\aio.h"
#include "..\include\com\com.h"
#include "..\include\dio\dio.h"
#include "..\include\disp\disp.h"
#include "..\include\os\os.h"
#include "..\include\ui\ui.h"

#define VAL_TO_STR(argvaltostr) #argvaltostr

#define TemperatureSensorPin      2
#define ButtonPlusPin             5
#define ButtonMinusPin            6
#define ButtonOkPin               7
#define ButtonCancelPin           8

#ifndef PSTR
#define PSTR(s)                                                                \
  (__extension__({                                                             \
    static const char __c[] PROGMEM = (s);                                     \
    &__c[0];                                                                   \
  }))
#endif PSTR
struct payload_t
{
    char type;
    int value;

    payload_t(void): type(0), value(0) {}
    payload_t( char _type, int _value ): type(_type), value(_value) {}
} __attribute__ ((packed));


typedef enum comStatus { TXOK=0, TXFAIL, NONE,  INVALID } eComStatus;
 
#endif