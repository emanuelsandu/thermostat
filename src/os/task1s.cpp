#include "os/os.h"

void vTask1s( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  while(1)
  {
    DisplayMessage("TASK1S"); 
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {
      //check temperature, update only on change
      //move this to another function to check for temperature changes
      //update UI to do this
      MenuHandling();
      

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    //vTaskDelay(Task1000msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(configBlockResTickPeriod*12);
  }
}

