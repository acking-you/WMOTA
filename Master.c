//
// Created by Alone on 2021-12-24.
//

#include "Master.h"
#include "Hero.h"
#include "Scene.h"
#include "Fight.h"
#include <conio.h>

GET_COLOR_NUMS("法")

PrintFight(TMaster, "究极法师", _BLUE)

TMaster *CreatMaster(int x, int y) {
    TMaster *_pBat = malloc(sizeof(TMaster));
    const char *_color = COLOR_NUMS[rand() % _COLOR_LEN];
    InitBase(&_pBat->base, x, y, "究极法师", _color, E_BAT, Collion_t);
    _pBat->hp = 120;
    _pBat->att = 140;
    _pBat->def = 40;
    _pBat->gold = 10;
    return _pBat;
}
