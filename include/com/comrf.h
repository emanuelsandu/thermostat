
#ifndef COMRF_H
#define COMRF_H

/* 
* https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
* https://projecthub.arduino.cc/tmekinyan/how-to-use-the-nrf24l01-module-with-arduino-813957
* https://randomnerdtutorials.com/nrf24l01-2-4ghz-rf-transceiver-module-with-arduino/
* https://projecthub.arduino.cc/lightthedreams/nrf24l01-for-communication-1-way-and-2-way-4da921
*/

#include "..\..\include\glob.h"
#include <nRF24L01.h>
#include <RF24.h>

/* Hardware Setup */



extern RF24 NRF24COM;//=RF24(ComRfCEPin,ComRfCSNPin); // CE, CSN

// The debug-friendly names of those roles
const char role_friendly_name_0[] PROGMEM = "invalid";
const char role_friendly_name_1[] PROGMEM = "Sender";
const char role_friendly_name_2[] PROGMEM = "Receiver";
const char* const role_friendly_name[] PROGMEM = {
role_friendly_name_0,
role_friendly_name_1,
role_friendly_name_2,
};

//
// Status messages
//

const char status_str_0[] PROGMEM = "None";
const char status_str_1[] PROGMEM = "Send OK";
const char status_str_2[] PROGMEM = "Send Failed";
const char status_str_3[] PROGMEM = "*** INVALID ***";
const char* const status_str[] PROGMEM = { 
status_str_0,
status_str_1,
status_str_2,
status_str_3,
};

// Single radio pipe address for the 2 nodes to communicate.
const byte  addresses [][6] = {"00001", "00002"};    //Setting the two addresses. One for  transmitting and one for receiving

extern short ComRole;

short iComRfInit();
void NRF24Setup();
void NRF24Handler();
void NRF24Tx(byte msg);

extern void radio_set_role(short newrole);

void radio_set_role(short newrole);

#endif