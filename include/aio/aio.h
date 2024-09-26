#ifndef AIO_H
#define AIO_H


/*      INCLUDES     */
#include "..\glob.h"
#include "..\include\util\util.h"
#include <OneWire.h>
#include <DallasTemperature.h>


/*      DEFINES     */
#define __AIO_OK__ 0
#define __AIO_SENSOR_DISCONNECTED__ 255

#define Aio_SensorDisconnectedThreshold -125


/*      VARIABLES     */
extern bool     Aio_ActualRoomTemperatureChanged;
extern float    Aio_ActualRoomTemperature;
extern float  Aio_fActualRoomTemperature;


/*      FUNCTIONS     */
byte AioInit();
byte AioDiag();
void AioReadSensors();

void ReadRoomTemperature();
bool RoomTemperatureChanged(short newRoomTemp);


#endif