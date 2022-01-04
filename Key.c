//
// Created by Alone on 2021-12-27.
//

#include "Key.h"
#include "Hero.h"
#include "Scene.h"

static void Remove_t(Tkey *dst) {
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


int RedKeyCollion(THero *hero, void *p) {
    hero->red_key += 1;
    Remove_t(p);
    return 0;
}

int YellowKeyCollion(THero *hero, void *p) {
    hero->yellow_key += 1;
    Remove_t(p);
    return 0;
}

int BlueKeyCollion(THero *hero, void *p) {
    hero->blue_key += 1;
    Remove_t(p);
    return 0;
}

Tkey *CreartRedKey(int x, int y) {
    Tkey *obj = (Tkey *) malloc(sizeof(Tkey));
    InitBase(&obj->base, x, y, "ºìÉ«Ô¿³×", _RED"Ô¿"_END, E_REDKEY, RedKeyCollion);
    return obj;
}

Tkey *CreatYellowKey(int x, int y) {
    Tkey *obj = (Tkey *) malloc(sizeof(Tkey));
    InitBase(&obj->base, x, y, "»ÆÉ«Ô¿³×", _YELLOW"Ô¿"_END, E_YELLOWKEY, YellowKeyCollion);
    return obj;
}


Tkey *CreatBlueKey(int x, int y) {
    Tkey *obj = (Tkey *) malloc(sizeof(Tkey));
    InitBase(&obj->base, x, y, "À¶É«Ô¿³×", _BLUE"Ô¿"_END, E_BLUEKEY, BlueKeyCollion);
    return obj;
}