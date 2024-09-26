#include "..\include\util\util.h"


ftos UtilFtoS(float inArg)
{
    ftos result;
    if(inArg>32767 || inArg<-32768)
        inArg=32767;
    result.intPart=(short)inArg;
    result.fractPart=short(inArg*10)-result.intPart*10;
    return result;
}

float UtilStoF(ftos inArg)
{
    float result;
    if(inArg.intPart>32767 || inArg.intPart<-32768)
        inArg.intPart=32767;
    result=float(inArg.intPart*10 + inArg.fractPart)/10;
    return result;
}