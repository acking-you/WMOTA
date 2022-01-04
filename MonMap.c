//
// Created by Alone on 2021-12-29.
//

#include "MonMap.h"
#include "Hero.h"
#include "Scene.h"

static void Remove_t(TMonMap *dst) {
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

int MonMapCollion(THero *hero, void *p) {
    if (!(hero->hasMap))
        hero->hasMap = 1;
    Remove_t(p);
    printf("\033[17;40H你捡到了怪物手册！可以按m显示怪物信息了！");
    Sleep(1000);
    system("cls");
    return 0;
}

TMonMap *CreatMonMap(int x, int y) {
    TMonMap *obj = (TMonMap *) malloc(sizeof(TMonMap));
    InitBase(&obj->base, x, y, "册子", _LIGHT_BLUE"册"_END, E_MONMAP, MonMapCollion);
}
