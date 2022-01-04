//
// Created by Alone on 2021-12-27.
//

#ifndef WMOTA_DOOR_H
#define WMOTA_DOOR_H

#include "Base.h"

typedef struct Door {
    TBase base;
} TDoor;

TDoor *CreatRedDoor(int x, int y);

TDoor *CreatBlueDoor(int x, int y);

TDoor *CreatYellowDoor(int x, int y);

#endif //WMOTA_DOOR_H
