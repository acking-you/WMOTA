//
// Created by Alone on 2021-12-27.
//

#include "Medicine.h"
#include "Hero.h"
#include "Scene.h"

static void Remove_t(TMed *dst) {
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

int RedMedCollion(THero *hero, void *p) {
    if (hero->hp + 200 < hero->maxHp){
        Remove_t(p);
        hero->hp += 200;
    }
    else
        hero->hp = hero->maxHp;
    return 0;
}

int GreenMedCollion(THero *hero, void *p) {
    if (hero->hp + 100 < hero->maxHp){
        Remove_t(p);
        hero->hp += 100;
    }
    else
        hero->hp = hero->maxHp;
    return 0;
}

TMed *CreatGreenMed(int x, int y) {
    TMed *obj = (TMed *) malloc(sizeof(TMed));
    InitBase(&obj->base, x, y, "ÂÌÒ©Ë®", _GREEN"Ò©"_END, E_GREENMED, GreenMedCollion);
    return obj;
}

TMed *CreatRedMed(int x, int y) {
    TMed *obj = (TMed *) malloc(sizeof(TMed));
    InitBase(&obj->base, x, y, "ºìÒ©Ë®", _RED"Ò©"_END, E_REDMED, RedMedCollion);
    return obj;
}
