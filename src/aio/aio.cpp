#include"..\include\glob.h"


// GPIO where the DS18B20 is connected to
const short AioOneWireBusTempSensor = AioTemperatureSensorPin;     

// Setup a oneWire instance to communicate with any AioOneWireTempSensor devices
OneWire AioOneWireTempSensor(AioOneWireBusTempSensor);

short  RoomTemperatureOld=0;
float  Aio_ActualRoomTemperature;
bool Aio_ActualRoomTemperatureChanged;


// Pass our AioOneWireTempSensor reference to Dallas Temperature sensor
DallasTemperature AioTempSensor = DallasTemperature(&AioOneWireTempSensor);


byte AioInit(){
    return 0;
}

byte AioDiag()
{   
    byte _err_aio;
    _err_aio=__AIO_OK__;
    if(short(Aio_ActualRoomTemperature)<Aio_SensorDisconnectedThreshold)
        _err_aio=__AIO_SENSOR_DISCONNECTED__;
    return _err_aio;
}

void AioReadSensors()
{
    ReadRoomTemperature();
    Aio_ActualRoomTemperatureChanged=RoomTemperatureChanged(short(Aio_ActualRoomTemperature));
}

void ReadRoomTemperature()
{
    AioTempSensor.requestTemperatures();
    Aio_ActualRoomTemperature = AioTempSensor.getTempCByIndex(0);
}


bool RoomTemperatureChanged(short newRoomTemp)
{
    bool result=false;
    if(newRoomTemp!=RoomTemperatureOld) 
    {
        result=true;
    }
    RoomTemperatureOld = newRoomTemp;
    return result;
}
/* 
class cTempSensor{
    DallasTemperature AioTempSensor=DallasTemperature(&AioOneWireTempSensor);

    void ReadRoomTemperature()
    {
        short roomTemp;
        AioTempSensor.requestTemperatures();
        roomTemp=(int)(AioTempSensor.getTempCByIndex(0));
        return roomTemp;
    }
};

cTempSensor RoomTemperatureSensor; */