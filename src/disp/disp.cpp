#include"..\include\glob.h"

LiquidCrystal_I2C Display16x2=LiquidCrystal_I2C(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

byte DispHeatingSymbolActive;
byte RisingDoubleArrowInv[] = {
  0x1F,
  0x1B,
  0x15,
  0x0E,
  0x1B,
  0x15,
  0x0E,
  0x1F
};

short DispInit(){

    Display16x2.init();
    Display16x2.backlight();
    Display16x2.noCursor();
    Display16x2.noBlink();
    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("INITIALIZING...");

    DispHeatingSymbolActive=0;
    Display16x2.createChar(0,RisingDoubleArrowInv);

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
    DispHeatingSymbolActive=0;
}

void DisplayClear()
{
    Display16x2.clear();
}

void DisplayWriteMainPage()
{
    String alignSpaces=" ";

    if(UI_SetRoomTemperature<10 && Aio_ActualRoomTemperature>10)
        alignSpaces="  ";
    else
        alignSpaces=" ";

    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("Set: ");
    //Display16x2.print(String(setTemp.intPart,DEC) + "." + String(setTemp.fractPart,DEC));
    Display16x2.print(alignSpaces + String(UI_SetRoomTemperature,1) + degC);
    Display16x2.setCursor(CursorStart0,SecondRow);
    Display16x2.print("Room: ");
    Display16x2.print(String(Aio_ActualRoomTemperature,1) + degC );
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

void DisplayHeatingSymbol()
{
    Display16x2.setCursor(15,FirstRow);
    Display16x2.write(0);
    Display16x2.setCursor(15,SecondRow);
    Display16x2.print("H");
    DispHeatingSymbolActive=1;
}

void DisplayClearHeatingSymbol()
{
    Display16x2.setCursor(15,FirstRow);
    Display16x2.print("");
    Display16x2.setCursor(15,SecondRow);
    Display16x2.print("");
    DispHeatingSymbolActive=0;
}