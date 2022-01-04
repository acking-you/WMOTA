//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_BASE_H
#define WMOTA_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "color.h"

enum EBASE {
    E_EMPTY,        //空位置
    E_WALL,            //墙
    E_REDSLIME = 0x00000002,     //红色史莱姆
    E_GREENSLIME = 0x00000004,   //绿色史莱姆
    E_BAT = 0x00000008,            //蝙蝠
    E_MASTER = 0x00000010,        //法师
    E_SKULL = 0x00000020,        //骷髅人
    E_BUSINESSMAN,    //商人
    E_CLEVER,        //智者
    E_REDKEY,        //红色钥匙
    E_YELLOWKEY,    //黄色钥匙
    E_BLUEKEY,        //蓝色钥匙
    E_YELLOWDOOR,    //黄色门
    E_REDDOOR,        //红色门
    E_BLUEDOOR,        //蓝色门
    E_GREENMED,    //绿色血瓶
    E_REDMED,        //红色血瓶
    E_THIEF,        //小偷
    E_STORE,        //商店
    E_REDSTONE,        //红色宝石
    E_GREENSTONE,    //绿色宝石
    E_HERO,            //英雄
    E_TRANSUP,      //上楼
    E_TRANSDOWN,    //下楼
    E_MONMAP,        //怪物手册
    E_IRONDOOR,        //铁牢门
    E_IRONWALL,     //铁墙壁
    E_PASS,
    E_YITIANSWORD = 0x00000003,  //倚天剑
    E_TULONGSWORD = 0x00000006,    //屠龙刀
    E_BOSSSWORD = 0x0000000c,    //灭霸手套
    E_LONGSHIELD = 0x00000003,   //邓宝盾牌
    E_BACKSHIELD = 0x00000006,    //回调盾
    E_PENGSHIELD = 0x0000000c,    //脸盆子
};

//TODO 碰撞回调函数 return 1发生碰撞不允许移动  0没有发生碰撞允许移动
typedef int (*CollionCB)(struct tagHero *, void *);//碰撞检测的基本函数指针类型


typedef struct tagBase  //基类
{
    int x;
    int y;
    const char *name;
    const char *printName;
    enum EBASE type;
    CollionCB collionCB;
} TBase;


void InitBase(TBase *base, int x, int y, const char *name,
              const char *printN, enum EBASE type, CollionCB *collionCB);

#ifdef SCENE_H_

// 根据枚举创建 基础类型
TBase* CreateBaseByType(enum EBASE type, int x, int y);

#endif

// 初始化创建管理器
void InitCreateMgr();

#endif //WMOTA_BASE_H
