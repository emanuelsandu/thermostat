#include "..\include\aio\aio.h"


// GPIO where the DS18B20 is connected to
const int oneWireBus = TemperatureSensor;     

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature TempSensor=DallasTemperature(&oneWire);

int ReadTemperature()
{
    int roomTemp;
    TempSensor.requestTemperatures();
    roomTemp=(int)(TempSensor.getTempCByIndex(0));
    return roomTemp;
}