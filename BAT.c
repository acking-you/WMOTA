//
// Created by Alone on 2021-12-23.
//

#include "BAT.h"
#include "Hero.h"
#include "Scene.h"
#include "Fight.h"
#include <conio.h>

PrintFight(TBat, "究极蝙蝠", _BLUE)

GET_COLOR_NUMS("蝠")

TBat *CreatBat(int x, int y) {
    TBat *_pBat = malloc(sizeof(TBat));
    const char *name = COLOR_NUMS[rand() % _COLOR_LEN];
    InitBase(&_pBat->base, x, y, "究极蝙蝠：颜色随机", name, E_BAT, Collion_t);
    _pBat->hp = 120;
    _pBat->att = 200;
    _pBat->def = 100;
    _pBat->gold = 10;
    return _pBat;
}
