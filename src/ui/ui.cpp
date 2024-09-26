#include "..\..\include\glob.h"

float UI_SetRoomTemperature;
short initUI=0;

void PageSetup()
{
    UI_SetRoomTemperature=21.5;
}

void MenuHandling()
{
    short tempdata;

    if(Dio_ButtonPlus || Dio_ButtonMinus || initUI==0)
    {

        tempdata=UIIncreaseTemp(Dio_ButtonPlus);
        tempdata=UIDecreaseTemp(Dio_ButtonMinus);

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
            UI_SetRoomTemperature=UI_SetRoomTemperature;
            break;
        default:
            UI_SetRoomTemperature=UI_SetRoomTemperature;
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
            UI_SetRoomTemperature=UI_SetRoomTemperature;
            break;
        default:
            UI_SetRoomTemperature=UI_SetRoomTemperature;
            break;

    }
    if(UI_SetRoomTemperature<10) UI_SetRoomTemperature=10;
    return result;
}

void UIMainPage()
{
    //String DisplayRow1;
    //char* DisplayRow2;

    //DisplayRow1="Set: ";
    //DisplayRow2="Room: ";
    DisplayWriteMainPage(UI_SetRoomTemperature);
}

void UISettingsPage()
{

}

void UIDebugPage()
{

}
