//
// Created on 2024/11/4.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "integer.op.h"

int32_t ohos_int_sub(int32_t a, int32_t b) {
    return a - b;
}