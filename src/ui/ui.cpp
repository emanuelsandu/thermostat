#include "..\..\include\glob.h"

#define UI_MainPage 0
#define UI_SettingsPage 1
#define UI_DebugPage 2

float UI_SetRoomTemperature;
float UI_SetRoomTemperaturePrevious;
short initUI=0;

byte UIActivePage=UI_MainPage;
byte UIActivePagePrevious=UI_MainPage;

byte UIRequestHeating=0;

void PageSetup()
{
    UI_SetRoomTemperature=21.5;
}

byte UIUpdateDisplayEvent()
{
    byte result;
    if(Dio_ButtonPlus!=Dio_ButtonClear || Dio_ButtonPlus!= Dio_ButtonError ||
       Dio_ButtonMinus!=Dio_ButtonClear || Dio_ButtonMinus!= Dio_ButtonError || 
       Dio_ButtonSoftGP!=Dio_ButtonClear || Dio_ButtonSoftGP!= Dio_ButtonError || 
       UI_SetRoomTemperature!=UI_SetRoomTemperaturePrevious)
       result=1;
    else
        result=0;
    return result;
}

void UIUpdateDisplay()
{
    
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

void UIMenuHandling()
{
    UIActivePagePrevious=UIActivePage;

    if(Dio_ButtonSoftGP==Dio_ButtonOkClick)
    {
        UIActivePage+=1;
    }
    
    if(UIActivePage>ThermostatDebugPageID || UIActivePage<ThermostatMainPageID)
        UIActivePage=ThermostatMainPageID;

    if(UIActivePagePrevious!=UIActivePage  )
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

    UI_SetRoomTemperaturePrevious=UI_SetRoomTemperature;

    if(Dio_ButtonPlus==Dio_ButtonSingleClick || Dio_ButtonMinus==Dio_ButtonSingleClick)
        alterValue=0.5;
    else
        alterValue=3;

    if(UIActivePage==UI_MainPage &&
        Dio_ButtonPlus<Dio_ButtonLongClick && Dio_ButtonMinus<Dio_ButtonLongClick)
            UI_SetRoomTemperature=UI_SetRoomTemperature+alterValue*((float)(Dio_ButtonPlus-Dio_ButtonMinus));
}

void UIHeatControl()
{
    if(UI_SetRoomTemperature<=Aio_ActualRoomTemperature-TEMP_DELTA_HEATING_OFF)
    {

        UIRequestHeating=0;
        if(UIActivePage==UI_MainPage)
            DisplayClearHeatingSymbol();
    }
    else if(UI_SetRoomTemperature>Aio_ActualRoomTemperature+TEMP_DELTA_HEATING_ON )
    {
        
        UIRequestHeating=1;

        if(UIActivePage==UI_MainPage)
            DisplayHeatingSymbol();

    }
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
