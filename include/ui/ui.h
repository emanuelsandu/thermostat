#ifndef UI_H
#define UI_H

#include "..\glob.h"
#include "..\disp\disp.h"

static int initMenu=0;

struct Page
{
    int ID;
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
};

#define ThermostatMainPageID 0
#define ThermostatSettingsPageID 1
#define ThermostatDebugPageID 2

//Page ThermostatPage;
//Menu ThermostatMenu;

void PageSetup();
void MenuHandling();
void UIMainPage();
void UISettingsPage();
void UIDebugPage();

#endif