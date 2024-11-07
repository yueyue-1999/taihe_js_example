//
// Created on 2024/11/4.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef MYAPPLICATION_RGB_BASE_NAPI_H
#define MYAPPLICATION_RGB_BASE_NAPI_H

#include "napi/native_api.h"
#include "rgb.base.h"

struct NAPI_RGB : RGB {
    static void Destructor(napi_env env, void* nativeObject, void* finalize_hint);
    static napi_value Constructor(napi_env env, napi_callback_info info);
    static napi_value Init(napi_env env, napi_value exports);
    static napi_value GetR(napi_env env, napi_callback_info info);
    static napi_value SetR(napi_env env, napi_callback_info info);
    static napi_value GetG(napi_env env, napi_callback_info info);
    static napi_value SetG(napi_env env, napi_callback_info info);
    static napi_value GetB(napi_env env, napi_callback_info info);
    static napi_value SetB(napi_env env, napi_callback_info info);
};

napi_value napi_get_rgb(napi_env env, napi_callback_info info);
napi_value napi_init_color(napi_env env, napi_callback_info info);

#endif //MYAPPLICATION_RGB_BASE_NAPI_H
