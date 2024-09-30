#include"..\include\glob.h"

byte RequestType=0;

short ComInit(){

    short result;

    //Serial.begin(9600);

    result&=iComRfInit();

    //DisplayMessage( strcat("INITIALIZING...", VAL_TO_STR(__COM_STATUS_OK__) + result));

    return result;
}

void ComHandler()
{
    ComMessageHandler();
    //NRF24Handler();
}

void ComMessageHandler()
{

    if(UIRequestHeating==1)
    {
        RequestType=UIRequestHeating;
    }
    else
    {
        RequestType=UIRequestHeating;
    }

}

void ComTx()
{
    

}

void ComRx()
{

}