
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\glob.h"

// define two Tasks for DigitalRead & AnalogRead
void TaskDigitalRead( void *pvParameters );
void TaskTxDataRF( void *pvParameters );
void TaskRxDataRF( void *pvParameters );
void TaskDisplayData( void *pvParameters );
void createTasks();
