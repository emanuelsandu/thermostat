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

  //TaskCreate( fCallName, stringName, stacksize, ?, prio, Handler)

  xTaskCreate(  Task10ms  ,  "10ms"  ,   128,  NULL,  1,  &xTask10ms   );
 
  xTaskCreate(  Task100ms ,  "100ms" ,   128,  NULL,  2,  &xTask100ms  ); 

  xTaskCreate(  Task1000ms,  "1000ms",   128,  NULL,  0,  &xTask1000ms ); 
    

  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}

void Task10ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  for (;;) // A Task shall never return or exit.
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {
      Serial.println("10mstask");

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    //vTaskDelay(Task10msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(1);
  }
}

void Task100ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  for (;;)
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {      
      MenuHandling();
      Serial.println("100mstask");

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    //vTaskDelay(Task100msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(7);
  }
}


void Task1000ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
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

          Serial.print("Task990\n");
          initApp=1;
      }

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    //vTaskDelay(Task1000msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(67);
  }
}