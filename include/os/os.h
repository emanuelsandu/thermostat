
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\glob.h"
#include "..\ui\ui.h"
#include "..\aio\aio.h"
#include "..\com\com.h"

#define configBlockResTickPeriod 1

#define Task10msPeriod      10
#define Task100msPeriod     100
#define Task1000msPeriod    1000


// define two Tasks for DigitalRead & AnalogRead
void OsInit();
void TaskInit( void *pvParameters );
void TaskOneCycle( void *pvParameters );
void Task100ms( void *pvParameters );
void Task1s( void *pvParameters );
void createTasks();
