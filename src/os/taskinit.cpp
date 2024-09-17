#include "os/os.h"

void CreateInitTask()
{

/*  
  xTaskCreate(
    TaskInit
    ,  "Init"  // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL //Parameters for the task
    ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &xTaskInit ); //Task Handle
  */

}

void TaskInit( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  if(initMenu==0){
    for (;;) // A Task shall never return or exit.
    {
      DisplaySetup();
          Serial.print("Task0\n");

      vTaskDelay(10);  // one tick delay (15ms) in between reads for stability
    }
    //vTaskSuspend(NULL);

  }
}