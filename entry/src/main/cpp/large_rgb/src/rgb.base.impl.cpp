//
// Created on 2024/10/31.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "rgb.base.h"

RGB get_rgb(Color color) {
    struct RGB result = {
        (uint8_t)(color >> 16 & 0xff),
        (uint8_t)(color >> 8 & 0xff),
        (uint8_t)(color >> 0 & 0xff),
    };
    return result;
}