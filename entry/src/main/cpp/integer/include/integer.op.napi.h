//
// Created on 2024/11/4.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef MYAPPLICATION_INTEGER_OP_NAPI_H
#define MYAPPLICATION_INTEGER_OP_NAPI_H

#include "napi/native_api.h"

napi_value napi_ohos_int_sub(napi_env env, napi_callback_info info);

#endif //MYAPPLICATION_INTEGER_OP_NAPI_H
