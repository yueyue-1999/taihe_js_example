//
// Created on 2024/10/31.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef MYAPPLICATION_RGB_BASE_H
#define MYAPPLICATION_RGB_BASE_H

#include <cstdint>

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

enum Color {
    RED   = 0xff << 020,
    GREEN = 0xff << 010,
    BLUE  = 0xff << 000,
};

RGB get_rgb(Color color);

#endif //MYAPPLICATION_RGB_BASE_H
