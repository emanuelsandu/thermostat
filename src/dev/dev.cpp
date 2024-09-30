
#include"..\include\glob.h"



void DevInitDevices(){

    pinMode(A0,OUTPUT); //display
    pinMode(A1,OUTPUT); //nrf
    pinMode(A2,OUTPUT); //button+
    pinMode(A3,OUTPUT); //button-
    //A4, A5 reserved
    pinMode(A6,OUTPUT); //temp sensor
}

void DeviceManager(){
    digitalWrite(A0,HIGH);
    digitalWrite(A1,HIGH);
    digitalWrite(A2,HIGH);
    digitalWrite(A3,HIGH);
    //A4, A5 reserved
    digitalWrite(A6,HIGH);
}