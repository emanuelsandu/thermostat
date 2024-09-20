#include "..\include\glob.h"

// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only one Task is accessing this resource at any time.


SemaphoreHandle_t xSerialSemaphore;
TaskHandle_t tTaskInit;
TaskHandle_t tTaskOneCycle;
TaskHandle_t tTask100ms;
TaskHandle_t tTask1s;
TaskHandle_t tComSoftIrq;
TaskHandle_t tComRxTask;
TaskHandle_t tComTxTask;
TaskHandle_t tComStatus;
TaskHandle_t tDbgIn;

SemaphoreHandle_t xRadioIrqSemaphore;
SemaphoreHandle_t xRadioMutex;
SemaphoreHandle_t xConsoleMutex;
QueueHandle_t xPayloadQueue;
QueueHandle_t xStatusQueue;


int initApp=0;
int messageCount=0;
int iOsAppErr=0;

void vOsCreateTasks(){

    if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
    {
        xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
        if ( ( xSerialSemaphore ) != NULL )
        xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
    }
    DisplayMessage("OS STARTED"); 
      

     /*xTaskCreate(    vTaskOneCycle,       "15ms",  
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 0,   &tTaskOneCycle ); */
    /*xTaskCreate(    vTask100ms,          "100ms",  
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 0,   &tTask100ms ); 
                      
    xTaskCreate(    vTask1s,             "1s",  
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 0,   &tTask1s ); 
                      */
    xTaskCreate(    vRadioSoftIrqTask,  "ComSoftIrq",
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2,   &tComSoftIrq );
    /*xTaskCreate(    vReceiverTask,      "ComRxTask",
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2,   &tComRxTask );
    /*xTaskCreate(    vSenderTask,        "ComTxTask",
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2,   &tComTxTask );
    xTaskCreate(    vStatusTask,        "ComStatus",
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1,   &tComStatus);
                      */
    xTaskCreate(    vInputTask,         "DbgIn",
                      configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1,   &tDbgIn );
                      
    DisplayMessage("OS TASKS CREATED"); 

  // Now the Task scheduler, which takes over control of scheduling individual Tasks, is automatically started.
}

void OsInit(){
  

  iOsAppErr&=iDispInit();
  iOsAppErr&=iAioInit();
  iOsAppErr&=iDioInit();
  iOsAppErr&=iComInit();

  if(Serial.available())
    Serial.println(VAL_TO_STR(__OS_STATUS_OK__)) ;
  else
  DisplayMessage("SER_NA_INIOS_OK");
}

void vTaskInit( void *pvParameters __attribute__((unused)) )  // This is a Task.
{  
}

void vTaskOneCycle( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
  while(1) // A Task shall never return or exit.
  {
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) configBlockResTickPeriod ) == pdTRUE )
    {
      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }
    
    //vTaskDelay(Task10msPeriod/portTICK_PERIOD_MS);  // one tick delay (15ms) in between reads for stability
    vTaskDelay(configBlockResTickPeriod);
  }
}
void vSenderTask(void*)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    // How often to wait between sends.
    const TickType_t sendPeriod = 2000;

    /* Infinite task loop */
    while (1)
    {
        DisplayMessage("vSenderTask");
        /*
        if ( ComRole ==   (int)COM_ROLE_TX )
        {            
            // Take the time, and send it.
            payload_t payload('T',xLastWakeTime);

            xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
            //printf_P(PSTR("Now sending %u\r\n"),payload.value);
            xSemaphoreGive(xConsoleMutex);

            xSemaphoreTake(xRadioMutex, portMAX_DELAY);
            NRF24COM.stopListening();
            NRF24COM.startWrite( &payload, sizeof(payload),true );
            xSemaphoreGive(xRadioMutex);
        }
        */
        /* Block the task for the defined time */
        vTaskDelayUntil(&xLastWakeTime,
                        sendPeriod - (xLastWakeTime % sendPeriod) );
    }
}

void vReceiverTask(void*)
{
    //payload_t payload;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t tickPeriod = 67;

    /* Infinite loop */
    while(1)
    {
        DisplayMessage("vReceiverTask");
        /* Wait until an element is received from the queue */
        /*
        if (xQueueReceive(xPayloadQueue, &payload, portMAX_DELAY))
        {
            xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
            //printf_P(PSTR("Got payload type=%02x value=%u\r\n"),payload.type,payload.value);
            xSemaphoreGive(xConsoleMutex);

            if ( payload.type == 'T' )
            {
                // Add an ack packet for the next time around.  This is a simple
                // packet counter
                payload_t ack('A',++messageCount);

                xSemaphoreTake(xRadioMutex, portMAX_DELAY);
                NRF24COM.writeAckPayload( 1, &ack, sizeof(ack) );
                xSemaphoreGive(xRadioMutex);

                xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
                //printf_P(PSTR("Sent ack value=%u\r\n"),ack.value);
                xSemaphoreGive(xConsoleMutex);
            }
        }
        */
        vTaskDelayUntil(&xLastWakeTime, tickPeriod);
    }
}

void vStatusTask(void*)
{
    int status;
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t tickPeriod = 67;

    /* Infinite loop */
    while (1)
    {
        DisplayMessage("vStatusTask");
        /* Wait until an element is received from the queue */
        /*
        if (xQueueReceive(xStatusQueue, &status, portMAX_DELAY))
        {
            xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
            printf_P(PSTR("Status: %S\r\n"),pgm_read_word(&status_str[status]));
            xSemaphoreGive(xConsoleMutex);
        }
        */
        vTaskDelayUntil(&xLastWakeTime, tickPeriod);

    }
}
void vInputTask(void*)
{
    TickType_t xLastWakeTime;
    const TickType_t tickPeriod = 67;
    xLastWakeTime = xTaskGetTickCount();

    /* Infinite loop */
    while (1)
    {
        DisplayMessage("vInputTask");
        /*
        if (Serial.available())
        {
            char c = toupper(Serial.read());
            if ( c == 'S' && ComRole == COM_ROLE_RX )
            {
                xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
                printf_P(PSTR("*** CHANGING TO SENDER ROLE -- PRESS 'R' TO SWITCH BACK\r\n"));
                xSemaphoreGive(xConsoleMutex);

                // Become the primary transmitter (ping out)
                radio_set_role(COM_ROLE_TX);
            }
            else if ( c == 'R' && ComRole == COM_ROLE_TX )
            {
                xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
                printf_P(PSTR("*** CHANGING TO RECEIVE ROLE -- PRESS 'S' TO SWITCH BACK\r\n"));
                xSemaphoreGive(xConsoleMutex);

                // Become the primary receiver (pong back)
                radio_set_role(COM_ROLE_RX);
            }
            else
            {
                printf_P(PSTR("Unknown: %c\r\n"),c);
            }
        }
        */
        //vTaskDelayUntil(&xLastWakeTime, tickPeriod);
        vTaskDelay(configBlockResTickPeriod*67);
    }
}

void vRadioSoftIrqTask(void*)
{
    bool tx,fail,rx;

    /* Infinite loop */
    while(1)
    {

        DisplayMessage("RadioSoftIrq");
        /* Block until the semaphore is given */
      
        /*
        xSemaphoreTake(xRadioIrqSemaphore, portMAX_DELAY);

        // Get the radio access semaphore for the whole time 
        xSemaphoreTake(xRadioMutex, portMAX_DELAY);
        
        // What happened?
        NRF24COM.whatHappened(tx,fail,rx);

        // Have we successfully transmitted?
        if ( tx )
        {
            comStatus status = TXOK;
            xQueueSendToBack(xStatusQueue, &status, 0);
        }

        // Have we failed to transmit?
        if ( fail )
        {
            comStatus status = TXFAIL;
            xQueueSendToBack(xStatusQueue, &status, 0);
        }

        // Transmitter can power down for now, because
        // the transmission is done.
        if ( ( tx || fail ) && ( ComRole == (int)COM_ROLE_TX ) )
            NRF24COM.powerDown();

        // Did we receive a message?
        if ( rx )
        {           
            // Get this payload and queue it
            payload_t payload;
            NRF24COM.read( &payload, sizeof(payload) );
            xQueueSendToBack(xPayloadQueue, &payload, 0);
        }

        // Done with the radio now.
        xSemaphoreGive(xRadioMutex);
        
        // Print the stack hi water mark
        xSemaphoreTake(xConsoleMutex, portMAX_DELAY);
        //printf_P(PSTR("Stack min: %u\r\n"),uxTaskGetStackHighWaterMark(NULL));
        xSemaphoreGive(xConsoleMutex);
        */
        
    }
}
