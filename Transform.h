//
// Created by Alone on 2021-12-27.
//

#ifndef WMOTA_TRANSFORM_H
#define WMOTA_TRANSFORM_H

#include "Base.h"

typedef struct TRANS {
    TBase base;
} TTrans;

TTrans *CreatTransUp(int x, int y);

TTrans *CreatTransDown(int x, int y);

#endif //WMOTA_TRANSFORM_H
