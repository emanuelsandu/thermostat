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
#include "..\include\util\util.h"


#define VAL_TO_STR(argvaltostr) #argvaltostr

#define FEATURE_ENABLE            0
#define __DEBUG_MODE__            1



#ifdef __AVR_ATmega328P__

#define _RESERVED_PIN_RX_         0
#define _RESERVED_PIN_TX_         1
#define ComRfCEPin                2
#define ComRfCSNPin               3
#define ComRfIRQPin               4
#define AioTemperatureSensorPin   5
#define DioButtonPlusPin          6
#define DioButtonMinusPin         7
#define OsDebugTaskPin1           8
#define OsDebugTaskPin2           9
#define OsDebugTaskPin3           10
#define _RESERVED_ComRfSSPin_     10
#define _RESERVED_ComRfMOSIPin_   11
#define _RESERVED_ComRfMISOPin_   12
#define _RESERVED_ComRfSCKPin_    13

#endif __AVR_ATmega328P__

#define INCREMENT_ONE             1
#define INCREMENT_POINT_FIVE      0.5
#define INCREMENT_POINT_ONE       0.1
#define TEMP_DELTA_HEATING_ON     0.5
#define TEMP_DELTA_HEATING_OFF    0.3

struct payload_t
{
    char type;
    short value;

    payload_t(void): type(0), value(0) {}
    payload_t( char _type, short _value ): type(_type), value(_value) {}
} __attribute__ ((packed));


typedef enum comStatus { TXOK=0, TXFAIL, NONE,  INVALID } eComStatus;

#endif