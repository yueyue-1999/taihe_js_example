//
// Created on 2024/11/4.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".


#include "string.op.napi.h"
#include "string.op.h"

napi_value napi_ohos_split_str(napi_env env, napi_callback_info info)
{

    size_t argc = 2;
    napi_value args[2] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    
    // get string
    size_t length;
    napi_get_value_string_utf8(env, args[0], nullptr, 0, &length);
    char* buffer = new char[length + 1]; // +1 for null terminator
    std::memset(buffer, 0, length + 1);
    napi_get_value_string_utf8(env, args[0], buffer, length + 1, &length);
    
    // get number
    uint32_t n;
    napi_get_value_uint32(env, args[1], &n);
    
    // function call
    std::tuple<std::string, std::string> ts = ohos_split_str(std::string(buffer), n);
    
    // create result
    napi_value jsArray = nullptr;
    napi_create_array(env, &jsArray);
    std::string s0 = std::get<0>(ts);
    std::string s1 = std::get<1>(ts);
    
    napi_value element = nullptr;
    napi_create_string_utf8(env, s0.c_str(), s0.size(), &element);
    napi_set_element(env, jsArray, 0, element);
    napi_create_string_utf8(env, s1.c_str(), s1.size(), &element);
    napi_set_element(env, jsArray, 1, element);
    
    return jsArray;

}