//
// Created by Alone on 2021-12-23.
//

#ifndef WMOTA_COLOR_H
#define WMOTA_COLOR_H

#define _END          "\033[m"
#define _RED          "\033[0;32;31m"
#define _GREEN        "\033[0;32;32m"
#define _BLUE         "\033[0;32;34m"
#define _PURPLE       "\033[0;35m"
#define _YELLOW       "\033[1;33m"
#define _WHITE        "\033[1;37m"
#define _LIGHT_BLUE   "\033[1;34m"
#ifdef _NUMS
#define _COLOR_LEN   5
#define GET_COLOR_NUMS(name) static const char* COLOR_NUMS[_COLOR_LEN] = {_RED name _END,_GREEN name _END,_BLUE name _END,_PURPLE name _END,_LIGHT_BLUE name _END};

#endif
#endif //WMOTA_COLOR_H
