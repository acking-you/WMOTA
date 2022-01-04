//
// Created by Alone on 2021-12-23.
//

#include "Base.h"
#include "Hero.h"
#include "RedSlime.h"
#include "GreenSlime.h"
#include "BAT.h"
#include "Master.h"
#include "Skull.h"
#include "Key.h"
#include "Door.h"
#include "Medicine.h"
#include "Stone.h"
#include "Transform.h"
#include "Weapon.h"
#include "MonMap.h"

typedef struct tagWall {
    TBase base; // 所有结构体 必须 第一个字段为 tagBase
} TWall;

typedef TBase *(*CreateCB)(int x, int y);

static CreateCB createCB[1024] = {0};

void InitBase(TBase *base, int x, int y, const char *name,
              const char *printN, enum EBASE type, CollionCB *collionCB) {
    base->x = x;
    base->y = y;
    base->printName = printN;
    base->name = name;
    base->type = type;
    base->collionCB = collionCB;
}

int WallCollionCB(THero *hero, void *p) {
    return 1;
}

TBase *CreateWall(int x, int y) {
    TWall *wall = (TWall *) malloc(sizeof(TWall));
    wall->base.name = "墙";
    wall->base.printName = "■";
    wall->base.type = E_WALL;
    wall->base.x = x;
    wall->base.y = y;
    wall->base.collionCB = WallCollionCB;
    return &(wall->base);
}

TBase *CreateBaseByType(enum EBASE type, int x, int y) {
    // 根据枚举搜索 创建函数
    if (createCB[type])
        // 调用对应的创建函数
        return createCB[type](x, y);
    return 0;
}

void InitCreateMgr() {
    // 注册函数
    // 墙的创建函数
    createCB[E_WALL] = CreateWall;
    createCB[E_HERO] = CreateHero;
    createCB[E_REDSLIME] = CreatRedSlime;
    createCB[E_GREENSLIME] = CreatGreenSlime;
    createCB[E_BAT] = CreatBat;
    createCB[E_MASTER] = CreatMaster;
    createCB[E_SKULL] = CreatSkull;
    createCB[E_REDKEY] = CreartRedKey;
    createCB[E_YELLOWKEY] = CreatYellowKey;
    createCB[E_BLUEKEY] = CreatBlueKey;
    createCB[E_REDDOOR] = CreatRedDoor;
    createCB[E_YELLOWDOOR] = CreatYellowDoor;
    createCB[E_BLUEDOOR] = CreatBlueDoor;
    createCB[E_REDMED] = CreatRedMed;
    createCB[E_GREENMED] = CreatGreenMed;
    createCB[E_GREENSTONE] = CreatGreenStone;
    createCB[E_REDSTONE] = CreatRedStone;
    createCB[E_TRANSUP] = CreatTransUp;
    createCB[E_TRANSDOWN] = CreatTransDown;
    createCB[E_YITIANSWORD] = CreatYitian;
    createCB[E_MONMAP] = CreatMonMap;
}

