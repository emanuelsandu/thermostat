#ifndef OS_H
#define OS_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\config.h"
#include "..\ui\ui.h"
#include "..\aio\aio.h"
#include "..\com\com.h"


// define two Tasks for DigitalRead & AnalogRead
void TaskInit( void *pvParameters );
void Task10ms( void *pvParameters );
void Task100ms( void *pvParameters );
void Task1000ms( void *pvParameters );

void CreateInitTask();
void Create10msTask();
void Create100msTask();
void Create1000msTask();

void createTasks();

#endif