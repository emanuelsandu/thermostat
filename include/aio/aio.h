#ifndef AIO_H
#define AIO_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "..\config.h"

int SensorInit();
int ReadRoomTemperature();

#endif