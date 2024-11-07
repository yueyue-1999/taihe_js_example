//
// Created on 2024/11/6.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef MYAPPLICATION_RGB_BASE_NAPI_H
#define MYAPPLICATION_RGB_BASE_NAPI_H


#include "napi/native_api.h"

napi_value napi_get_rgb(napi_env env, napi_callback_info info);

napi_value napi_init_rgb(napi_env env, napi_value exports);

#endif //MYAPPLICATION_RGB_BASE_NAPI_H
