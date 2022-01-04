//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_HERO_H
#define WMOTA_HERO_H

#include "Base.h"

typedef struct tagHero {
    TBase base;
    int hp;
    int att;
    int def;
    int gold;
    int yellow_key;
    int blue_key;
    int red_key;
    int nums;
    int maxHp;
    int hasMap;
    int weaponlib;
    int armornlib;
} THero;

TBase *CreateHero(int x, int y);

void PrintHeroInfo(THero *);

THero *GetHero();

#endif //WMOTA_HERO_H
