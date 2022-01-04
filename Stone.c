//
// Created by Alone on 2021-12-27.
//

#include "Stone.h"
#include "Scene.h"
#include "Hero.h"

static void Remove_t(TStone *dst) {
    int find_index = 0;
    TScene *src = GetScene();
    int len = src->baseIndex;
    for (int i = 0; i < len; i++) {
        if (src->bases[i] == dst) {
            find_index = i;
            break;
        }
    }
    src->bases[find_index] = src->bases[len - 1];
    src->baseIndex--;
    free(dst);
}

int RedStoneCollion(THero *hero, void *p) {
    hero->gold += 2000;
    Remove_t(p);
    return 0;
}

int GreenStoneCollion(THero *hero, void *p) {
    hero->gold += 1000;
    Remove_t(p);
    return 0;
}

TStone *CreatGreenStone(int x, int y) {
    TStone *obj = (TStone *) malloc(sizeof(TStone));
    InitBase(&obj->base, x, y, "ÂÌ±¦Ê¯", _GREEN"±¦"_END, E_GREENSTONE, GreenStoneCollion);
    return obj;
}

TStone *CreatRedStone(int x, int y) {
    TStone *obj = (TStone *) malloc(sizeof(TStone));
    InitBase(&obj->base, x, y, "ºì±¦Ê¯", _RED"±¦"_END, E_REDSTONE, RedStoneCollion);
    return obj;
}
