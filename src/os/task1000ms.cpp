#include "os/os.h"

void Create1000msTask()
{

  xTaskCreate(  Task1000ms,  "1000ms",   128,  NULL,  0,  &xTask1000ms ); 

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