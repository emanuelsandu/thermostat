#include"..\include\glob.h"

int iComInit(){

    int result;

    if ( xRadioMutex == NULL )  
    {
        xRadioMutex = xSemaphoreCreateMutex();  
        if ( ( xRadioMutex ) != NULL )
        xSemaphoreGive( ( xRadioMutex ) );  
        DisplayMessage( "INITIALIZING RADIO MUTX");
    }
    else
    {
        result&=__COM_STATUS_GEN_FAIL__;
    }

    if ( xConsoleMutex == NULL )  
    {
        xConsoleMutex = xSemaphoreCreateMutex();  
        if ( ( xConsoleMutex ) != NULL )
        xSemaphoreGive( ( xConsoleMutex ) ); 
        DisplayMessage( "INITIALIZING CONSOLE MUTX"); 
    }
    else{
        result&=__COM_STATUS_GEN_FAIL__;
    }

    /* Create the Semaphore for synchronization between hw & softirq */
    if ( xRadioIrqSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
    {
        vSemaphoreCreateBinary( xRadioIrqSemaphore);
        DisplayMessage( "INITIALIZING IRQ MUTX"); 
    }
    else{
        result&=__COM_STATUS_GEN_FAIL__;
    }

    /* Create the Payload Queue which carries messages received from the radio */
    xPayloadQueue = xQueueCreate( 5, sizeof(payload_t) );
        DisplayMessage( "INITIALIZING PLQU MUTX"); 

    /* Create the Status Queue which carries status received from the radio */
    xStatusQueue = xQueueCreate( 5, sizeof(int) );
        DisplayMessage( "INITIALIZING STSQU MUTX"); 

    result&=iComRfInit();

    if(Serial.available())
        Serial.println(VAL_TO_STR(__COM_STATUS_OK__) + result) ;
    DisplayMessage( strcat("INITIALIZING...", VAL_TO_STR(__COM_STATUS_OK__) + result));

    return result;
}