#include "..\include\glob.h"

static void irq_handler_com(void);
static void irq_handler_dio(void);

void OsInit(){

    iOsAppErr&=DispInit();
    iOsAppErr&=AioInit();
    iOsAppErr&=DioInit();
    iOsAppErr&=ComInit();
    iOsAppErr&=OsAddHandlers();


    //DisplayClear();

    pinMode(OsDebugTaskPin1, OUTPUT);
    pinMode(OsDebugTaskPin2, OUTPUT);
    pinMode(OsDebugTaskPin3, OUTPUT);


}

byte OsAddHandlers(){
    
    byte result;


    if ( xMutex /*xSerialSemaphore*/ == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
    {
        xMutex /*xSerialSemaphore*/ = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
        if ( ( xMutex /*xSerialSemaphore*/ ) != NULL )
        xSemaphoreGive( ( xMutex /*xSerialSemaphore*/ ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
        result&=__COM_STATUS_OK__;
    }
    else
    {
        result&=__COM_STATUS_GEN_FAIL__;
    }
    
   
    /* Create the Payload Queue which carries messages received from the radio */
    xPayloadQueue = xQueueCreate( 5, sizeof(payload_t) );
        //DisplayMessage( "INITIALIZING PLQU MUTX"); 

    /* Create the Status Queue which carries status received from the radio */
    xStatusQueue = xQueueCreate( 5, sizeof(int) );
        //DisplayMessage( "INITIALIZING STSQU MUTX"); 

    attachInterrupt(0,irq_handler_com,FALLING);
    attachInterrupt(0,irq_handler_dio,RISING);
    attachInterrupt(0,irq_handler_dio,FALLING);

    return result;
}

static void irq_handler_com(void)
{
    static BaseType_t xHigherPriorityTaskWoken;
    /* Give the semaphore */
    //xSemaphoreGiveFromISR(xMutex /*xRadioIrqSemaphore*/, &xHigherPriorityTaskWoken);
}

static void irq_handler_dio(void)
{
    static BaseType_t xHigherPriorityTaskWoken;
    /* Give the semaphore */
    //xSemaphoreGiveFromISR(xMutex /*xRadioIrqSemaphore*/, &xHigherPriorityTaskWoken);
    //DioReadButtons();
    //xSemaphoreGiveFromISR(xMutex, &xHigherPriorityTaskWoken);
}

    