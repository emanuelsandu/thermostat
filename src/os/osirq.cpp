
#include "..\include\glob.h"

void OsTaskSoftIrq(void*)
{
    byte stateDebugLed=(byte)HIGH;
    byte stateDebugLedOld=(byte)LOW;

    // Infinite loop 
    while(1)
    {
       
        if(__DEBUG_MODE__){
        if(stateDebugLedOld==HIGH) stateDebugLed=LOW;
        else stateDebugLed=HIGH;
            digitalWrite(OsDebugTaskPin1, stateDebugLed);   // turn the LED on (HIGH is the voltage level)
            stateDebugLedOld=stateDebugLed;
            vTaskDelay( 500 / portTICK_PERIOD_MS ); // wait for one second
        }
    
    }
}