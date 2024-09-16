
#include "..\..\include\com\comrf.h"

//nRF24L01 communication 2 ways Arduino B

RF24 NRF24COM=RF24(9, 10); // CE, CSN
const byte  addresses [][6] = {"00001", "00002"};    //Setting the two addresses. One for  transmitting and one for receiving

boolean  button_stateA = 0;
boolean button_stateB = 0;

void NRF24Setup() {
  NRF24COM.begin();                            //Starting  the radio communication
  NRF24COM.openWritingPipe(addresses[0]);      //Setting  the address at which we will send the data
  NRF24COM.openReadingPipe(1, addresses[1]);   //Setting the address at which we will receive the data
  NRF24COM.setPALevel(RF24_PA_HIGH);            //You can set it as minimum or maximum depending on the distance between  the transmitter and receiver.
}

void NRF24Handler() 
{
  NRF24COM.startListening();                    //This sets the module as receiver
  if (NRF24COM.available())                     //Looking for incoming data
  {

    NRF24COM.read(&button_stateA,  sizeof(button_stateA));
     
    NRF24COM.stopListening();                           //This sets the module  as transmitter
    button_stateB = 0;///digitalRead(button_pinB);
    
    NRF24COM.write(&button_stateB,  sizeof(button_stateB));   //Sending the data
  } 
}