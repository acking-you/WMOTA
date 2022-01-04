#ifndef SCENE_H_
#define SCENE_H_

#include "Base.h"

#define  N 13

typedef struct tagScene {
    // ¶¯Ì¬Êý×é
    TBase *bases[N * N];
    int baseIndex;
    unsigned int kind;
    struct tagScene *next;
    struct tagScene *pre;
} TScene;

TScene *GetScene();

#ifdef MAIN

TScene* CreateScene(int map[][N]);

void PrintScene(TScene* scene);

void UpdateScene(TScene* scene, int dirX, int dirY);

void PrintHelp();

#endif

#endif // !SCENE_H_
