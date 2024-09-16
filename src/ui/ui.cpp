#include "..\..\include\ui\ui.h"

void PageSetup()
{
    /*
    
    
    ThermostatMenu.CurrentPage.ID=0;
    
    ThermostatMenu.Main.ID=0;
    //ThermostatMenu.Main.Name="MainPage";
    
    ThermostatMenu.Settings.ID=1;
    //ThermostatMenu.Settings.Name="Settings";

    ThermostatMenu.Debug.ID=99;
    //ThermostatMenu.Debug.Name="Debug";

    ThermostatPage.ID=0;
    */
}

void MenuHandling()
{
    if(initMenu==0)
    {
        PageSetup();
        DisplaySetup();
        
        initMenu=1;
    }

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

void UIMainPage()
{
    //String DisplayRow1;
    //char* DisplayRow2;

    //DisplayRow1="Set: ";
    //DisplayRow2="Room: ";
    DisplayWrite();
}

void UISettingsPage()
{

}

void UIDebugPage()
{

}
