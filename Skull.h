//
// Created by Alone on 2021-12-24.
//

#ifndef WMOTA_SKULL_H
#define WMOTA_SKULL_H
#define _NUMS

#include "Base.h"

typedef struct SKULL {
    TBase base;
    int att;
    int def;
    int hp;
    int gold;
} TSkull;

TSkull *CreatSkull(int x, int y);


#endif //WMOTA_SKULL_H
