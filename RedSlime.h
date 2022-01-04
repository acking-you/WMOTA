//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_REDSLIME_H
#define WMOTA_REDSLIME_H

#include "Base.h"

typedef struct RedSlime {
    TBase base;
    int att;
    int def;
    int hp;
    int gold;
} TRedSlime;

TRedSlime *CreatRedSlime(int x, int y);

#endif //WMOTA_REDSLIME_H
