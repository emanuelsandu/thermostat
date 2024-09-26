#include "..\include\glob.h"

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only one Task is accessing this resource at any time.

SemaphoreHandle_t xMutex /*xSerialSemaphore*/;
//SemaphoreHandle_t xMutex /*xRadioIrqSemaphore*/;
//SemaphoreHandle_t xMutex /*xRadioMutex*/;
//SemaphoreHandle_t xMutex /*xConsoleMutex*/;
QueueHandle_t xPayloadQueue;
QueueHandle_t xStatusQueue;

TaskHandle_t tTask100ms;
TaskHandle_t tTask1s;
TaskHandle_t tSoftIrq;


byte initApp=0;
short messageCount=0;
byte iOsAppErr=0;


void OsCreateTasks(){

    //DisplayMessage("OS STARTED"); 
    
    
    xTaskCreate(    OsTask100ms,     "100ms",      128, NULL, tskIDLE_PRIORITY + 1,   &tTask100ms );
                     
    xTaskCreate(    OsTask1s,        "1s",         128, NULL, tskIDLE_PRIORITY + 2,   &tTask1s ); 
                      
    xTaskCreate(    OsTaskSoftIrq,   "ComSoftIrq", 128, NULL, tskIDLE_PRIORITY + 0,   &tSoftIrq );

  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}