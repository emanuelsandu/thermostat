#include"..\include\glob.h"

//https://arduinogetstarted.com/tutorials/arduino-lcd-i2c
LiquidCrystal_I2C Display16x2=LiquidCrystal_I2C(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

#define DispHeatingSymbolRow FirstRow
#define DispHeatingSymbolCol 15
#define DispBatteryStatusSymbolRow FirstRow
#define DispBatteryStatusSymbolCol 14
#define DispComStatusSymbolRow SecondRow
#define DispComStatusSymbolCol 14

byte DispHeatingSymbolActive;
byte RisingDoubleArrowInv[] = {  0x1F,  0x1B,  0x15,  0x0E,  0x1B,  0x15,  0x0E,  0x1F };
uint8_t Battery1Char[] = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t Battery2Char[] = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x1f, 0x1f};
uint8_t Battery3Char[] = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x1f, 0x1f, 0x1f};
uint8_t Battery4Char[] = {0x0e, 0x1b, 0x11, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};
uint8_t ComConnectionUnavailable[] = {0x00, 0x11, 0x0a, 0x04, 0x0e, 0x15, 0x04, 0x04};
uint8_t ComConnectionAvailable[] = {0x00, 0x00, 0x1f, 0x15, 0x0e, 0x04, 0x04, 0x04};
uint8_t ComConnectionActive[] = {0x15, 0x00, 0x1f, 0x15, 0x0e, 0x04, 0x04, 0x04};

short DispInit(){

    Display16x2.init();
    Display16x2.backlight();
    Display16x2.noCursor();
    Display16x2.noBlink();
    Display16x2.setCursor(CursorStart0,FirstRow);
    Display16x2.print("INITIALIZING...");

    DispHeatingSymbolActive=0;
    Display16x2.createChar(0,RisingDoubleArrowInv);
    Display16x2.createChar(1,Battery1Char);
    Display16x2.createChar(2,Battery2Char);
    Display16x2.createChar(3,Battery3Char);
    Display16x2.createChar(4,Battery4Char);
    Display16x2.createChar(5,ComConnectionUnavailable);
    Display16x2.createChar(6,ComConnectionAvailable);
    Display16x2.createChar(7,ComConnectionActive);

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
    
    DisplayComStatusSymbol();
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

void DisplayComStatusSymbol()
{
    Display16x2.setCursor(DispComStatusSymbolCol,DispComStatusSymbolRow);
    if(ComStatus==__COM_STATUS_OK__)
        Display16x2.write(6);
    else
        Display16x2.write(5);
}