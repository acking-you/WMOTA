//
// Created by Alone on 2021-12-23.
//

#include "Scene.h"
#include "Hero.h"

int _flag;

extern TScene *cur_scene;

int isMonster(int code);

TScene *CreateScene(int map[][N]) {
    // 创建场景
    TScene *scene = (TScene *) malloc(sizeof(TScene));
    scene->kind = 0;
    scene->baseIndex = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            TBase *base = CreateBaseByType(map[i][j], i + 1, j + 1);
            if (base) {
                scene->bases[scene->baseIndex++] = base;
                if (isMonster(map[i][j]))
                    scene->kind |= map[i][j];//更新地图中有的怪物种类
            }
        }
    }
    return scene;
}

void PrintHelp() {
    printf("\033[2;90H===================");
    printf("\033[3;90H|  "_RED"游戏操作说明"_END"   |");
    printf("\033[4;90H|W A S D"_YELLOW"熊"_END"移动    |");
    printf("\033[5;90H|H 获取游戏帮助   |");
    printf("\033[6;90H|H2取消游戏帮助   |");
    printf("\033[7;90H|"_LIGHT_BLUE"矛:倚,屠,灭霸手套"_END"|");
    printf("\033[8;90H|"_PURPLE"盾:邓,回调,盆子"_END"  |");
    printf("\033[9;90H|M 怪物手册       |");
    printf("\033[10;90H|C 关卡穿越:%-2d个   |", GetHero()->nums);
    printf("\033[11;90H===================");
}

void PrintMonMap() {
    int row = 17;
    printf("\033[%d;40H|  怪物  |%s攻击%s|%s防御%s|%s生命%s|%s金币%s|", row++, _RED, _END, _GREEN, _END, _BLUE, _END, _YELLOW,
           _END);
    if (cur_scene->kind & E_REDSLIME)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "红史莱姆", 100, 70, 120, 10);
    if (cur_scene->kind & E_GREENSLIME)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "绿史莱姆", 80, 60, 100, 5);
    if (cur_scene->kind & E_MASTER)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "究极法师", 140, 40, 120, 10);
    if (cur_scene->kind & E_SKULL)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "邪恶骷髅", 120, 90, 150, 15);
    if (cur_scene->kind & E_BAT)
        printf("\033[%d;40H %8s %-3d  %-3d  %-3d  %-3d", row++, "进化蝙蝠", 200, 100, 120, 15);
}

void ClearMonMap() {
    int row = 17;
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
    printf("\033[%d;40H                                               ", row++);
}

void PrintScene(TScene *scene) {
    for (int i = 0; i < scene->baseIndex; ++i) {
        TBase *base = scene->bases[i];
        printf("\033[%d;%dH%s", base->x, base->y * 2, base->printName);
    }
    PrintHeroInfo(GetHero());
    PrintHelp();
    if (GetHero()->hasMap && _flag) {
        PrintMonMap();
    }
    if (GetHero()->hasMap && !_flag) {
        ClearMonMap();
    }
    printf(_RED"\033[15;50H打不赢了？买挂吧少年！按下g可进入买挂页面"_END);
}

// -1 0 1
void UpdateScene(TScene *scene, int dirX, int dirY) {
    scene->kind = 0;
    THero *pHero = GetHero();
    int x = pHero->base.x + dirX;
    int y = pHero->base.y + dirY;

    int bFlag = 1;
    for (int i = 0; i < scene->baseIndex; ++i) {
        TBase *base = scene->bases[i];
        if (isMonster(base->type))
            scene->kind |= base->type;//更新当前场景所拥有的怪物类型
        if (base->x == x && base->y == y && base->collionCB(pHero, base)) // 查询下一个位置是否存在物体
        {
            bFlag = 0;//不直接跳出，因为还需要更新当前地图拥有的类型
        }
    }
    // TODO  判断 是否允许移动
    if (bFlag) {
        printf("\033[%d;%dH  ", pHero->base.x, pHero->base.y * 2);
        pHero->base.x += dirX;
        pHero->base.y += dirY;

    }
}


TScene *GetScene() {
    return cur_scene;
}
