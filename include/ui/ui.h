#ifndef UI_H
#define UI_H

#include "..\glob.h"
#include "..\disp\disp.h"

//static short initMenu=0;

/* struct Page
{
    short ID;
    char* Name;
    //char* DataRow1;
    //char* DataRow2;
};

struct Menu
{
    Page CurrentPage;
    Page Main;
    Page Settings;
    Page Debug;
}; */

#define ThermostatMainPageID 0
#define ThermostatSettingsPageID 1
#define ThermostatDebugPageID 2

//Page ThermostatPage;
//Menu ThermostatMenu;


extern float UI_SetRoomTemperature;
extern float UI_SetRoomTemperaturePrevious;

void UIInit();
void PageSetup();
void UIMenuHandling();
void UIMainPage();
void UISettingsPage();
void UIDebugPage();
void UIAlterRoomTemperature();
byte UIUpdateDisplayEvent();
void UIUpdateDisplay();

#endif