#include "..\..\include\glob.h"
#include "..\..\include\com\comrf.h"

//nRF24L01 communication 2 ways Arduino B
RF24 NRF24COM=RF24(ComRfCEPin,ComRfCSNPin); // CE, CSN
short ComRole=COM_ROLE_RX;

short iComRfInit()
{
    short result=0;
    bool tx,fail,rx;
    
    
    /* NRF24COM.whatHappened(tx,fail,rx);
    if(NRF24COM.isChipConnected()){
        //DisplayMessage(VAL_TO_STR(__COM_STATUS_OK__));
        result=__COM_STATUS_OK__;
    }
    else{
        //DisplayMessage(VAL_TO_STR(__COM_STATUS_NO_CHIP__));
        result=__COM_STATUS_NO_CHIP__;
    }
    if(fail){
        //DisplayMessage(VAL_TO_STR(__COM_STATUS_GEN_FAIL__));
        result =__COM_STATUS_GEN_FAIL__;
    }
    */
    NRF24Setup();

    return result;
}



void NRF24Setup() {


    if(NRF24COM.begin()){                        //Starting  the radio communication

        if ( ComRole ==   COM_ROLE_TX )
        {
            NRF24COM.openWritingPipe(addresses[COM_ROLE_TX]);   //Setting  the address at which we will send the data
            NRF24COM.openReadingPipe(1,addresses[COM_ROLE_RX]); //Setting the address at which we will receive the data
        }
        else
        {
            NRF24COM.openWritingPipe(addresses[COM_ROLE_RX]);
            NRF24COM.openReadingPipe(1,addresses[COM_ROLE_TX]);
        }

        if ( ComRole == (int)COM_ROLE_TX )
            NRF24COM.startListening();

    }
    else
    {
        //set flag to check and attempt 5 retries in 1 minute every 24h/wakeup
        //DisplayMessage(VAL_TO_STR(__COM_STATUS_GEN_FAIL__));
    }
    // We will be using the Ack Payload feature, so please enable it
    NRF24COM.enableAckPayload();
    
    //You can set it as minimum or maximum depending on the distance between  the transmitter and receiver.
    NRF24COM.setPALevel(RF24_PA_HIGH);


}

void NRF24Handler() 
{
/*     //DisplayMessage("COM started");
    if(NRF24COM.isChipConnected())
    {
        //DisplayMessage("COM connected");
        NRF24COM.startListening();                    //This sets the module as receiver
        if (NRF24COM.available())                     //Looking for incoming data
        {

            //DisplayMessage("COM available");
            NRF24COM.read(NULL,  sizeof(NULL));
            
            NRF24COM.stopListening();                           //This sets the module  as transmitter

            NRF24COM.write("AA",  sizeof("AA"));   //Sending the data
            NRF24COM.closeReadingPipe(1);
            //DisplayMessage("COM finished");
        }
        else
        {
            NRF24COM.stopListening();
            //DisplayMessage("COM N/A");
        }
    }       
    //DisplayMessage("COM NO CHIP");
 */
    NRF24Tx(RequestType);
}


void NRF24Tx(byte msg)
{

}

/**
 * The irq callback function called when the radio hw irq is raised.
 * It gives the semaphore.
 */
#if FEATURE_ENABLE==1
void radio_set_role(short newrole)
{
    if ( newrole == (int)COM_ROLE_TX )
    {
        xSemaphoreTake(xMutex /*xRadioMutex*/, portMAX_DELAY);
        ComRole = (int)COM_ROLE_TX;
        NRF24COM.openWritingPipe(addresses[COM_ROLE_TX]);   
        NRF24COM.openReadingPipe(1,addresses[COM_ROLE_RX]);
        NRF24COM.stopListening();
        xSemaphoreGive(xMutex /*xRadioMutex*/);
    }
    else if ( newrole == (int)COM_ROLE_RX )
    {
        // Become the primary receiver (pong back)
        xSemaphoreTake(xMutex /*xRadioMutex*/, portMAX_DELAY);
        ComRole = (int)COM_ROLE_RX;
        NRF24COM.openWritingPipe(addresses[COM_ROLE_RX]);
        NRF24COM.openReadingPipe(1,addresses[COM_ROLE_TX]);
        NRF24COM.startListening();
        xSemaphoreGive(xMutex /*xRadioMutex*/);
    }
}

#endif FEATURE_ENABLE