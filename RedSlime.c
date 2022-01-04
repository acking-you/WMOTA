//
// Created by Alone on 2021-12-23.
//

#include "RedSlime.h"
#include "Hero.h"
#include "Scene.h"
#include "Fight.h"
#include <conio.h>
////TODO 将史莱姆从表中删除

PrintFight(TRedSlime, "红史莱姆", _RED)

TRedSlime *CreatRedSlime(int x, int y) {
    TRedSlime *_pRedSlime = malloc(sizeof(TRedSlime));
    InitBase(&_pRedSlime->base, x, y, "红史莱姆", _RED"史"_END, E_REDSLIME, Collion_t);
    _pRedSlime->hp = 120;
    _pRedSlime->att = 100;
    _pRedSlime->def = 70;
    _pRedSlime->gold = 10;
    return _pRedSlime;
}
