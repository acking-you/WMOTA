//
// Created by Alone on 2021-12-24.
//

#ifndef WMOTA_MASTER_H
#define WMOTA_MASTER_H
#define _NUMS

#include "Base.h"

typedef struct MASTER {
    TBase base;
    int att;
    int def;
    int hp;
    int gold;
} TMaster;

TMaster *CreatMaster(int x, int y);


#endif //WMOTA_MASTER_H
