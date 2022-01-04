//
// Created by Alone on 2021-12-24.
//

#ifndef WMOTA_BAT_H
#define WMOTA_BAT_H
#define _NUMS

#include "Base.h"

typedef struct BAT {
    TBase base;
    int att;
    int def;
    int hp;
    int gold;
} TBat;

TBat *CreatBat(int x, int y);

#endif //WMOTA_BAT_H
