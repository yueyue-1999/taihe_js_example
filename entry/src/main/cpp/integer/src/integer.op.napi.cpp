//
// Created on 2024/11/4.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "integer.op.napi.h"
#include "integer.op.h"

napi_value napi_ohos_int_sub(napi_env env, napi_callback_info info)
{
    size_t argc = 2;
    napi_value args[2] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    
    int32_t value0;
    napi_get_value_int32(env, args[0], &value0);

    int32_t value1;
    napi_get_value_int32(env, args[1], &value1);
    
    int32_t value = ohos_int_sub(value0, value1);

    napi_value result;
    napi_create_int32(env, value, &result);
    return result;

}