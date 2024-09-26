#include"..\include\glob.h"

short ComInit(){

    short result;

    result&=iComRfInit();

    //DisplayMessage( strcat("INITIALIZING...", VAL_TO_STR(__COM_STATUS_OK__) + result));

    return result;
}