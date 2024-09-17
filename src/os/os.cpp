#include "os/os.h"

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore;
TaskHandle_t xTaskInit;
TaskHandle_t xTaskOneCycle;
TaskHandle_t xTask100ms;
TaskHandle_t xTask1s;

int initApp=0;

void createTasks(){

    if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }

  xTaskCreate(    TaskOneCycle,   "15ms"  ,  128, NULL,  1,   &xTaskOneCycle ); //Task Handle
  xTaskCreate(    Task100ms,      "100ms" ,  128, NULL,  2,   &xTask100ms ); //Task Handle
  xTaskCreate(    Task1s,         "1s"    ,  128, NULL,  0,   &xTask1s ); //Task Handle

  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}

void TaskInit( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  if(initMenu==0){
    for (;;) // A Task shall never return or exit.
    {
      DisplaySetup();

      vTaskDelay(Task10msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    }
    //vTaskSuspend(NULL);

  }
}

void TaskOneCycle( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;) // A Task shall never return or exit.
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {
      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }
    //vTaskDelay(Task10msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(configBlockResTickPeriod);
  }
}

void Task100ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {      
      MenuHandling();

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    //vTaskDelay(Task100msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(configBlockResTickPeriod*7);
  }
}

void Task1s( void *pvParameters __attribute__((unused)) )  // This is a Task.
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

    //vTaskDelay(Task1000msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(configBlockResTickPeriod*12);
  }
}
