#ifndef AIO_H
#define AIO_H

#include "..\glob.h"
#include <OneWire.h>
#include <DallasTemperature.h>

int iAioInit();
int ReadRoomTemperature();
bool bRoomTemperatureChanged();

#endif