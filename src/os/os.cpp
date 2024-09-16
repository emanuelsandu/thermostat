#include "os/os.h"

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore;
TaskHandle_t xTaskInit;
TaskHandle_t xTask15ms;
TaskHandle_t xTask90ms;
TaskHandle_t xTask990ms;

int initApp=0;

void createTasks(){

    if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }

  // Now set up two Tasks to run independently.

/*  
  xTaskCreate(
    TaskInit
    ,  "Init"  // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL //Parameters for the task
    ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &xTaskInit ); //Task Handle
  */
  xTaskCreate(
    Task15ms
    ,  "15ms"  // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL //Parameters for the task
    ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &xTask15ms ); //Task Handle

  xTaskCreate(
    Task90ms
    ,  "90ms" // A name just for humans
    ,  128  // Stack size
    ,  NULL //Parameters for the task
    ,  2  // Priority
    ,  &xTask90ms ); //Task Handle

  xTaskCreate(
    Task990ms
    ,  "990ms" // A name just for humans
    ,  128  // Stack size
    ,  NULL //Parameters for the task
    ,  0  // Priority
    ,  &xTask990ms ); //Task Handle

  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}

void TaskInit( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  if(initMenu==0){
    for (;;) // A Task shall never return or exit.
    {
      DisplaySetup();

      vTaskDelay(10);  // one tick delay (15ms) in between reads for stability
    }
    //vTaskSuspend(NULL);

  }
}

void Task15ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;) // A Task shall never return or exit.
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {
      //Serial.println(buttonState);

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    vTaskDelay(1);  // one tick delay (15ms) in between reads for stability
  }
}

void Task90ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {      
      MenuHandling();

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    vTaskDelay(6);  // one tick delay (15ms) in between reads for stability
  }
}

void Task990ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {
      if(initApp==0)
      {
          PageSetup();
          NRF24Setup();
          DisplaySetup();
          delay(1000);
          
          initApp=1;
      }
      
      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    vTaskDelay(66);  // one tick delay (15ms) in between reads for stability
  }
}
