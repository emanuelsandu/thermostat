#include "os/os.h"

void Create10msTask()
{
  //TaskCreate( fCallName, stringName, stacksize, ?, prio, Handler)

  xTaskCreate(  Task10ms  ,  "10ms"  ,   128,  NULL,  1,  &xTask10ms   );    

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
