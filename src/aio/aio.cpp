#include"..\include\glob.h"


// GPIO where the DS18B20 is connected to
const int oneWireBus = TemperatureSensorPin;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

int iRoomTemperatureOld=0;

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature TempSensor = DallasTemperature(&oneWire);
int iAioInit(){
    DisplayMessageRow2("AIO_INIT_OK");
    return 0;
}

int ReadRoomTemperature()
{
    int roomTemp;
    TempSensor.requestTemperatures();
    roomTemp = (int)(TempSensor.getTempCByIndex(0));
    return roomTemp;
}


bool bRoomTemperatureChanged()
{
    bool result=false;
    if(ReadRoomTemperature()!=iRoomTemperatureOld) 
    {
        result=true;
    }
    iRoomTemperatureOld = ReadRoomTemperature();
    return result;
}
/* 
class cTempSensor{
    DallasTemperature TempSensor=DallasTemperature(&oneWire);

    int ReadRoomTemperature()
    {
        int roomTemp;
        TempSensor.requestTemperatures();
        roomTemp=(int)(TempSensor.getTempCByIndex(0));
        return roomTemp;
    }
};

cTempSensor RoomTemperatureSensor; */