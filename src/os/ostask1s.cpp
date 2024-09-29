#include "os/os.h"

void OsTask1s( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

  byte Counter60sFlag=0;
  byte stateDebugLed=(byte)HIGH;
  byte stateDebugLedOld=(byte)LOW;

  while(1)
  {
   
    if(__DEBUG_MODE__){
      if(stateDebugLedOld==HIGH) stateDebugLed=LOW;
      else stateDebugLed=HIGH;
        digitalWrite(OsDebugTaskPin2, stateDebugLed);   // turn the LED on (HIGH is the voltage level)
        stateDebugLedOld=stateDebugLed;
        vTaskDelay( Task1000msPeriod / portTICK_PERIOD_MS ); // wait for one second
    }
   
    if(Counter60sFlag>=60 )
    {
      Counter60sFlag=0;
      AioReadSensors();
    }
    else{
      Counter60sFlag+=1;
    }

    UIMenuHandling();

    //vTaskDelay(Task1000msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
  }
  
} 
 
