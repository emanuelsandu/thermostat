#include "os/os.h"

void Create100msTask()
{
  xTaskCreate(  Task100ms ,  "100ms" ,   128,  NULL,  2,  &xTask100ms  ); 
    
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