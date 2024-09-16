#include "..\..\include\ui\ui.h"
#include "..\..\include\dio\dio.h"

int temp=0;
int initUI=0;

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



    if(ReadButtonPlus() || initUI==0)
    {
        temp=temp+ReadButtonPlus();
        if(temp>30) temp=30;
            
        switch (0 )//ThermostatPage.ID)
        {
        case ThermostatMainPageID://ThermostatMenu.Main.ID:
            DisplayClear();
            UIMainPage(temp);
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

void UIMainPage(int setTemp)
{
    //String DisplayRow1;
    //char* DisplayRow2;

    //DisplayRow1="Set: ";
    //DisplayRow2="Room: ";
    DisplayWrite(setTemp);
}

void UISettingsPage()
{

}

void UIDebugPage()
{

}
