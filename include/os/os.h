
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\glob.h"
#include "..\ui\ui.h"
#include "..\aio\aio.h"
#include "..\com\com.h"

#define configBlockResTickPeriod 6

// define two Tasks for DigitalRead & AnalogRead
void TaskInit( void *pvParameters );
void Task15ms( void *pvParameters );
void Task90ms( void *pvParameters );
void Task990ms( void *pvParameters );
void createTasks();
