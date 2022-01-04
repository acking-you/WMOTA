//
// Created by Alone on 2021-12-27.
//

#include "Door.h"
#include "Hero.h"
#include "Scene.h"

static void Remove_t(TDoor *dst) {
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

int RedDoorCollion(THero *hero, void *p) {
    int f = 1;
    if (hero->red_key > 0) {
        hero->red_key--;
        Remove_t(p);
        f = 0;
    }
    return f;
}

int YellowDoorCollion(THero *hero, void *p) {
    int f = 1;
    if (hero->yellow_key > 0) {
        hero->yellow_key--;
        Remove_t(p);
        f = 0;
    }
    return f;
}

int BlueDoorCollion(THero *hero, void *p) {
    int f = 1;
    if (hero->blue_key > 0) {
        hero->blue_key--;
        Remove_t(p);
        f = 0;
    }
    return f;
}

TDoor *CreatRedDoor(int x, int y) {
    TDoor *obj = (TDoor *) malloc(sizeof(TDoor));
    InitBase(&obj->base, x, y, "红色的门", _RED"门"_END, E_REDDOOR, RedDoorCollion);
    return obj;
}

TDoor *CreatYellowDoor(int x, int y) {
    TDoor *obj = (TDoor *) malloc(sizeof(TDoor));
    InitBase(&obj->base, x, y, "黄色的门", _YELLOW"门"_END, E_YELLOWDOOR, YellowDoorCollion);
    return obj;
}

TDoor *CreatBlueDoor(int x, int y) {
    TDoor *obj = (TDoor *) malloc(sizeof(TDoor));
    InitBase(&obj->base, x, y, "蓝色的门", _BLUE"门"_END, E_BLUEDOOR, BlueDoorCollion);
    return obj;
}
