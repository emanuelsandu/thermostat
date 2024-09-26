#include"..\include\glob.h"

LiquidCrystal_I2C Display16x2=LiquidCrystal_I2C(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

short DispInit(){

    Display16x2.init();
    Display16x2.backlight();
    Display16x2.noCursor();
    Display16x2.noBlink();
    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("INITIALIZING...");

    return 0;
}

void DisplaySetup()
{
    Display16x2.init();
    Display16x2.backlight();
    Display16x2.noCursor();
    Display16x2.noBlink();
    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("INITIALIZING...");
}

void DisplayClear()
{
    Display16x2.clear();
}

void DisplayWriteMainPage(float setTemp)
{
    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("Set: ");
    //Display16x2.print(String(setTemp.intPart,DEC) + "." + String(setTemp.fractPart,DEC));
    Display16x2.print(String(UI_SetRoomTemperature,1));
    Display16x2.setCursor(CursorStart0,SecondRow);
    Display16x2.print("Room: ");
    Display16x2.print(String(Aio_ActualRoomTemperature,1) );
}

void DisplayMessage(const char *cDispMsgBuf){
    String message;
    message+=cDispMsgBuf;
    DisplayClear();
    Display16x2.setCursor(CursorStart0,FirstRow);
    short max_len;
    max_len=message.length();
    if(max_len>32) max_len=32;

    if(message.length()<=16)
        Display16x2.print(message);
    else{
        Display16x2.print(message.substring(0,16));
        Display16x2.setCursor(CursorStart0,SecondRow);
        Display16x2.print(message.substring(16,max_len));
    }
};

void DisplayMessageRow2(const char *cDispMsgBuf){
    DisplayClear();
    Display16x2.setCursor(CursorStart0,SecondRow);
    Display16x2.print(cDispMsgBuf);
    
};