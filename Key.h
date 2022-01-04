//
// Created by Alone on 2021-12-27.
//

#ifndef WMOTA_KEY_H
#define WMOTA_KEY_H

#include "Base.h"

/*
E_REDKEY,		//红色钥匙
E_YELLOWKEY,	//黄色钥匙
E_BLUEKEY,		//蓝色钥匙
E_YELLOWDOOR,	//黄色门
E_REDDOOR,		//红色门
E_BLUEDOOR,		//蓝色门
*/
typedef struct Key {
    TBase base;
} Tkey;

Tkey *CreartRedKey(int x, int y);

Tkey *CreatYellowKey(int x, int y);

Tkey *CreatBlueKey(int x, int y);

#endif //WMOTA_KEY_H
