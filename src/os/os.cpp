#include "os/os.h"


// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only one Task is accessing this resource at any time.
#if !defined(xSerialSemaphore)
SemaphoreHandle_t xSerialSemaphore;
#endif
#if !defined(xTaskInit)
TaskHandle_t xTaskInit;
#endif
#if !defined(xTask10ms)
TaskHandle_t xTask10ms;
#endif
#if !defined(xTask100ms)
TaskHandle_t xTask100ms;
#endif
#if !defined(xTask1000ms)
TaskHandle_t xTask1000ms; 
#endif


int initApp=0;

void createTasks(){


  if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }

  Create10msTask();
  Create100msTask();
  Create1000msTask();
    

  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}


