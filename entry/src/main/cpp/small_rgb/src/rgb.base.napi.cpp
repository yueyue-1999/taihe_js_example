//
// Created on 2024/11/6.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "rgb.base.napi.h"
#include "rgb.base.h"
#include "hilog/log.h"

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x0000
#define LOG_TAG "testTag"


napi_value Constructor(napi_env env, napi_callback_info info) {
    napi_value obj, r, g, b;
    napi_create_object(env, &obj);

    napi_create_uint32(env, 0, &r);
    napi_create_uint32(env, 0, &g);
    napi_create_uint32(env, 0, &b);

    napi_set_named_property(env, obj, "r", r);
    napi_set_named_property(env, obj, "g", g);
    napi_set_named_property(env, obj, "b", b);

    return obj;
}

napi_value napi_init_rgb(napi_env env, napi_value exports) {
    napi_property_descriptor properties[] = {
      { "r", 0, 0, 0, 0, 0, napi_default, 0 },
      { "g", 0, 0, 0, 0, 0, napi_default, 0 },
      { "b", 0, 0, 0, 0, 0, napi_default, 0 },
    };

    napi_value cons;
    napi_define_class(env, "RGB", NAPI_AUTO_LENGTH, Constructor, nullptr, 3,
                           properties, &cons);
    
    napi_set_named_property(env, exports, "RGB", cons);
    return exports;
};


napi_value napi_get_rgb(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "get rgb color");
    size_t argc = 2;
    napi_value args[2] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    
    // get number
    uint32_t color;
    napi_get_value_uint32(env, args[0], &color);

    // function call
    struct RGB rgb = get_rgb((Color)color);
    
    napi_value obj, r, g, b;
    napi_create_object(env, &obj);

    napi_create_uint32(env, (uint32_t)rgb.r, &r);
    napi_create_uint32(env, (uint32_t)rgb.g, &g);
    napi_create_uint32(env, (uint32_t)rgb.b, &b);

    napi_set_named_property(env, obj, "r", r);
    napi_set_named_property(env, obj, "g", g);
    napi_set_named_property(env, obj, "b", b);

    return obj;
}