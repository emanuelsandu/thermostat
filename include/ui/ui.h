#ifndef UI_H
#define UI_H

#include "..\config.h"
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


//Page ThermostatPage;
//Menu ThermostatMenu;

void PageSetup();
void MenuHandling();
void UIInit();
void UIMainPage(int setTemp);
void UISettingsPage();
void UIDebugPage();

#endif