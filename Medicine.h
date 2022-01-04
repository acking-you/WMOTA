//
// Created by Alone on 2021-12-27.
//

#ifndef WMOTA_MEDICINE_H
#define WMOTA_MEDICINE_H

#include "Base.h"

typedef struct Med {
    TBase base;
} TMed;

TMed *CreatGreenMed(int x, int y);

TMed *CreatRedMed(int x, int y);

#endif //WMOTA_MEDICINE_H
