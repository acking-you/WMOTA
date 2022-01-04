//
// Created by Alone on 2021-12-27.
//

#ifndef WMOTA_STONE_H
#define WMOTA_STONE_H

#include "Base.h"

typedef struct Stone {
    TBase base;
} TStone;

TStone *CreatGreenStone(int x, int y);

TStone *CreatRedStone(int x, int y);

#endif //WMOTA_STONE_H
