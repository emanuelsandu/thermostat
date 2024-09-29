#ifndef COM_H
#define COM_H

#include <SPI.h>
#include"..\com\comrf.h"


#define __COM_STATUS_OK__ 0
#define __COM_STATUS_NO_CHIP__ 1
#define __COM_STATUS_GEN_FAIL__ 255

#define COM_ROLE_TX 0
#define COM_ROLE_RX 1

extern byte RequestType;

short ComInit();
void ComHandler();
void ComTx();
void ComRx();
void ComMessageHandler();

#endif