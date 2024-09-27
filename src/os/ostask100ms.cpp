#include "os/os.h"



void OsTask100ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
{

    byte stateDebugLed=(byte)HIGH;
    byte stateDebugLedOld=(byte)LOW;
    
    while(1)
    {
        if(__DEBUG_MODE__){
          if(stateDebugLedOld==HIGH) stateDebugLed=LOW;
          else stateDebugLed=HIGH;
            digitalWrite(OsDebugTaskPin3, stateDebugLed);   // turn the LED on (HIGH is the voltage level)
            stateDebugLedOld=stateDebugLed;
            vTaskDelay( Task100msPeriod / portTICK_PERIOD_MS ); // wait for one second
        }
        
      //Dio_ButtonPlus=DioReadButtonPlus();


      //vTaskDelay(Task100msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    }
} 

