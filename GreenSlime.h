//
// Created by Alone on 2021-12-24.
//

#ifndef WMOTA_GREENSLIME_H
#define WMOTA_GREENSLIME_H

#include "Base.h"

typedef struct GreenSlime {
    TBase base;
    int att;
    int def;
    int hp;
    int gold;
} TGreenSlime;

TGreenSlime *CreatGreenSlime(int x, int y);


#endif //WMOTA_GREENSLIME_H
