#ifndef UTIL_H
#define UTIL_H

struct ftos{
    short intPart;
    unsigned short fractPart;
};

ftos UtilFtoS(float inArg);
float UtilStoF(ftos inArg);

#endif