//
// Created by Alone on 2021-12-27.
//

#include "Transform.h"
#include "Hero.h"
#include "Scene.h"

extern TScene *cur_scene;

int TransUpCollion(THero *hero, void *p) {
    if (cur_scene->next) {
        hero->nums += 1;
        cur_scene = cur_scene->next;
        system("cls");
    }
    return 1;
}

int TransDownCollion(THero *hero, void *p) {
    if (cur_scene->pre) {
        hero->nums -= 1;
        cur_scene = cur_scene->pre;
        system("cls");
    }
    return 1;
}

TTrans *CreatTransUp(int x, int y) {
    TTrans *obj = (TTrans *) malloc(sizeof(TTrans));
    InitBase(&obj->base, x, y, "传送门UP", _PURPLE"※"_END, E_TRANSUP, TransUpCollion);
    return obj;
}

TTrans *CreatTransDown(int x, int y) {
    TTrans *obj = (TTrans *) malloc(sizeof(TTrans));
    InitBase(&obj->base, x, y, "传送门DOWN", _LIGHT_BLUE"※"_END, E_TRANSUP, TransDownCollion);
    return obj;
}