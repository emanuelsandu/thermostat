#ifndef OS_H
#define OS_H

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).
#include "..\config.h"
#include "..\ui\ui.h"
#include "..\aio\aio.h"
#include "..\com\com.h"

extern SemaphoreHandle_t xSerialSemaphore;
extern TaskHandle_t xTaskInit;
extern TaskHandle_t xTask10ms;
extern TaskHandle_t xTask100ms;
extern TaskHandle_t xTask1000ms; 

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