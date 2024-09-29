#include "..\..\include\glob.h"

#define UI_MainPage 0
#define UI_SettingsPage 1
#define UI_DebugPage 2

float UI_SetRoomTemperature;
short initUI=0;

byte UIActivePage=UI_MainPage;
byte UIActivePagePrevious=UI_MainPage;

void PageSetup()
{
    UI_SetRoomTemperature=21.5;
}

void UIMenuHandling()
{
    if(Dio_ButtonSoftGP==Dio_ButtonOkClick)
    {
        UIActivePage+=1;
    }
    
    if(UIActivePage>ThermostatDebugPageID || UIActivePage<ThermostatMainPageID)
        UIActivePage=ThermostatMainPageID;

        switch (UIActivePage)//ThermostatPage.ID)
        {
            case ThermostatMainPageID://ThermostatMenu.Main.ID:
                DisplayClear();
                UIMainPage();
                break;
            case ThermostatSettingsPageID://ThermostatMenu.Settings.ID:
                DisplayClear();
                UISettingsPage();
                break;
            case ThermostatDebugPageID:
                DisplayClear();
                UIDebugPage();
                break;
            default:
                DisplayClear();
                UIMainPage();
                break;
        }


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
    DisplayMessage("SETTINGS");
}

void UIDebugPage()
{
    DisplayMessage("DEBUG");
}
