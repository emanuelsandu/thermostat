#include "..\..\include\glob.h"

#define UI_MainPage 0
#define UI_SettingsPage 1
#define UI_DebugPage 2

float UI_SetRoomTemperature;
short initUI=0;
byte UIActivePage=UI_MainPage;

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

void UIAlterRoomTemperature()
{
    float alterValue;

    if(Dio_ButtonPlus==Dio_ButtonSingleClick || Dio_ButtonMinus==Dio_ButtonSingleClick)
        alterValue=0.5;
    else
        alterValue=3;

    if(UIActivePage==UI_MainPage &&
        Dio_ButtonPlus<Dio_ButtonLongClick && Dio_ButtonMinus<Dio_ButtonLongClick)
            UI_SetRoomTemperature=UI_SetRoomTemperature+alterValue*((float)(Dio_ButtonPlus-Dio_ButtonMinus));
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
