//
// Created by Alone on 2021-12-28.
//

#include "Weapon.h"
#include "Hero.h"
#include "Scene.h"

static void Remove_t(TWeapon *dst) {
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

int YitianCollion(THero *hero, void *p) {
    hero->weaponlib |= E_YITIANSWORD;
    hero->att += 100;
    Remove_t(p);
    return 0;
}

TWeapon *CreatYitian(int x, int y) {
    TWeapon *obj = (TWeapon *) malloc(sizeof(TWeapon));
    InitBase(&obj->base, x, y, "ÒÐÌìÍÀÁú", _PURPLE"ÒÐ"_END, E_YITIANSWORD, YitianCollion);
}
