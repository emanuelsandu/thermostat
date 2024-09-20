#include "os/os.h"


void vTask100ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  while(1)
  {
    DisplayMessage("TASK100MS"); 
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {      
      //MenuHandling();
      //NRF24Handler();

      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

    //vTaskDelay(Task100msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(configBlockResTickPeriod*7);
  }
}
