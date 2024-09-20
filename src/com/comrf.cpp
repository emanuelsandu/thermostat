#include "..\..\include\glob.h"


//nRF24L01 communication 2 ways Arduino B
RF24 NRF24COM=RF24(rf_ce_pin,rf_csn_pin); // CE, CSN
int ComRole=COM_ROLE_RX;

int iComRfInit()
{
    int result=0;
    bool tx,fail,rx;
    
    
    /* NRF24COM.whatHappened(tx,fail,rx);
    if(NRF24COM.isChipConnected()){
        DisplayMessage(VAL_TO_STR(__COM_STATUS_OK__));
        result=__COM_STATUS_OK__;
    }
    else{
        DisplayMessage(VAL_TO_STR(__COM_STATUS_NO_CHIP__));
        result=__COM_STATUS_NO_CHIP__;
    }
    if(fail){
        DisplayMessage(VAL_TO_STR(__COM_STATUS_GEN_FAIL__));
        result =__COM_STATUS_GEN_FAIL__;
    }
    */
    NRF24Setup();
    DisplayMessage(  strcat("INITIALIZING NRF24",VAL_TO_STR(__COM_STATUS_OK__))); 

    return result;
}

void NRF24Setup() {


    if(NRF24COM.begin()){                        //Starting  the radio communication

        if ( ComRole ==   COM_ROLE_TX )
        {
            NRF24COM.openWritingPipe(addresses[COM_ROLE_TX]);   //Setting  the address at which we will send the data
            NRF24COM.openReadingPipe(1,addresses[COM_ROLE_RX]); //Setting the address at which we will receive the data
            DisplayMessage("INITIALIZING NRF24 SET TX"); 
        }
        else
        {
            NRF24COM.openWritingPipe(addresses[COM_ROLE_RX]);
            NRF24COM.openReadingPipe(1,addresses[COM_ROLE_TX]);
            DisplayMessage("INITIALIZING NRF24 SET RX"); 
        }

        if ( ComRole == (int)COM_ROLE_TX )
            NRF24COM.startListening();

            
        DisplayMessage("INITIALIZING NRF24 LISTENING"); 

    }
    else
    {
        //set flag to check and attempt 5 retries in 1 minute every 24h/wakeup
        DisplayMessage(VAL_TO_STR(__COM_STATUS_GEN_FAIL__));
    }
    // We will be using the Ack Payload feature, so please enable it
    NRF24COM.enableAckPayload();
        DisplayMessage("INITIALIZING NRF24 ACK PAYLOAD"); 
    
    //You can set it as minimum or maximum depending on the distance between  the transmitter and receiver.
    NRF24COM.setPALevel(RF24_PA_HIGH);
        DisplayMessage("INITIALIZING NRF24 SET PA LEVEL"); 

    attachInterrupt(0/*interrupter*/,rf_irq_handler,FALLING);
    DisplayMessage("INITIALIZING NRF24 IRQ"); 

}

void NRF24Handler() 
{
/*     DisplayMessage("COM started");
    if(NRF24COM.isChipConnected())
    {
        DisplayMessage("COM connected");
        NRF24COM.startListening();                    //This sets the module as receiver
        if (NRF24COM.available())                     //Looking for incoming data
        {

            DisplayMessage("COM available");
            NRF24COM.read(NULL,  sizeof(NULL));
            
            NRF24COM.stopListening();                           //This sets the module  as transmitter

            NRF24COM.write("AA",  sizeof("AA"));   //Sending the data
            NRF24COM.closeReadingPipe(1);
            DisplayMessage("COM finished");
        }
        else
        {
            NRF24COM.stopListening();
            DisplayMessage("COM N/A");
        }
    }       
    DisplayMessage("COM NO CHIP");
 */
}



/**
 * The irq callback function called when the radio hw irq is raised.
 * It gives the semaphore.
 */
static void rf_irq_handler(void)
{
    static BaseType_t xHigherPriorityTaskWoken;
    /* Give the semaphore */
    xSemaphoreGiveFromISR(xRadioIrqSemaphore, &xHigherPriorityTaskWoken);
}

void radio_set_role(int newrole)
{
    if ( newrole == (int)COM_ROLE_TX )
    {
        xSemaphoreTake(xRadioMutex, portMAX_DELAY);
        ComRole = (int)COM_ROLE_TX;
        NRF24COM.openWritingPipe(addresses[COM_ROLE_TX]);   
        NRF24COM.openReadingPipe(1,addresses[COM_ROLE_RX]);
        NRF24COM.stopListening();
        xSemaphoreGive(xRadioMutex);
    }
    else if ( newrole == (int)COM_ROLE_RX )
    {
        // Become the primary receiver (pong back)
        xSemaphoreTake(xRadioMutex, portMAX_DELAY);
        ComRole = (int)COM_ROLE_RX;
        NRF24COM.openWritingPipe(addresses[COM_ROLE_RX]);
        NRF24COM.openReadingPipe(1,addresses[COM_ROLE_TX]);
        NRF24COM.startListening();
        xSemaphoreGive(xRadioMutex);
    }
}