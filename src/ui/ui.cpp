#include "..\..\include\glob.h"

float UI_SetRoomTemperature;
short initUI=0;

void PageSetup()
{
    UI_SetRoomTemperature=21.5;
}

void MenuHandling()
{
/* 
    if(Dio_ButtonPlus!=Dio_ButtonError && Dio_ButtonPlus!=Dio_ButtonClear  
        || 
        Dio_ButtonMinus!=Dio_ButtonError && Dio_ButtonMinus!=Dio_ButtonClear   
        || 
        initUI==0) */
    {


        switch (0 )//ThermostatPage.ID)
        {
        case ThermostatMainPageID://ThermostatMenu.Main.ID:
            DisplayClear();
            UIMainPage();
            break;
        case ThermostatSettingsPageID://ThermostatMenu.Settings.ID:
            DisplayClear();
            break;
        case ThermostatDebugPageID:
            DisplayClear();
            break;
        default:
            DisplayClear();
            //DisplayMainPage();
            break;
        }

    }

    if(initUI==0) initUI=1;


}

byte UIIncreaseTemp(byte tempData)
{
    byte result;
    switch(tempData)
    {
        case Dio_ButtonSingleClick:
            UI_SetRoomTemperature+=0.5;
            break;
        case Dio_ButtonDoubleClick:
            UI_SetRoomTemperature+=1;
            break;
        case Dio_ButtonTripleClick:
            UI_SetRoomTemperature+=3;
            break;
        case Dio_ButtonError:
            break;
        default:
            break;

    }
    if(UI_SetRoomTemperature>30) UI_SetRoomTemperature=30;
    return result;
}

byte UIDecreaseTemp(byte tempData)
{
    byte result;
    switch(tempData)
    {
        case Dio_ButtonSingleClick:
            UI_SetRoomTemperature-=0.5;
            break;
        case Dio_ButtonDoubleClick:
            UI_SetRoomTemperature-=1;
            break;
        case Dio_ButtonTripleClick:
            UI_SetRoomTemperature-=3;
            break;
        case Dio_ButtonError:
            break;
        default:
            break;

    }
    if(UI_SetRoomTemperature<10) UI_SetRoomTemperature=10;
    return result;
}

void UIMainPage()
{
    DisplayWriteMainPage();
}

void UISettingsPage()
{

}

void UIDebugPage()
{

}
