
#ifndef COMRF_H
#define COMRF_H


#include "..\..\include\glob.h"
#include <nRF24L01.h>
#include <RF24.h>

/* Hardware Setup */

#ifdef __AVR_ATmega328P__
// Kind of a hack to experiment with this sketch on 328
const int rf_ce_pin = 9; 
const int rf_csn_pin = 10;
const int rf_irq_pin = 0;
#endif


extern RF24 NRF24COM;//=RF24(rf_ce_pin,rf_csn_pin); // CE, CSN

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

extern int ComRole;

int iComRfInit();
void NRF24Setup();
void NRF24Handler();

static void rf_irq_handler(void);
void radio_set_role(int newrole);

#endif