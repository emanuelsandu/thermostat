#include "os/os.h"



void OsTask50ms( void *pvParameters __attribute__((unused)) )  // This is a Task.
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
        }
      DioReadButtons();
      
      UI_SetRoomTemperature+=(float)DioReadButtonPlus();
      UI_SetRoomTemperature-=(float)DioReadButtonMinus();

      //vTaskDelay(Task50msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
      vTaskDelay(Task50msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    }
} 

