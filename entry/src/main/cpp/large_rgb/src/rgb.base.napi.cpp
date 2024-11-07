//
// Created on 2024/11/1.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".
#include "rgb.base.napi.h"
#include "hilog/log.h"

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x0000
#define LOG_TAG "testTag"

static thread_local napi_ref g_ref = nullptr;

void NAPI_RGB::Destructor(napi_env env,
                          void* nativeObject,
                          [[maybe_unused]] void* finalize_hint)
{
    OH_LOG_INFO(LOG_APP, "RGB::Destructor called");
    reinterpret_cast<NAPI_RGB*>(nativeObject)->~NAPI_RGB();
}

napi_value NAPI_RGB::Constructor(napi_env env, napi_callback_info info) {
    napi_value newTarget;
    napi_get_new_target(env, info, &newTarget);

    if (newTarget != nullptr) {
        OH_LOG_INFO(LOG_APP, "NAPI_RGB::Constructor called, new target");
        size_t argc = 3;
        napi_value argv[3];
        napi_value thisArg;

        napi_get_cb_info(env, info, &argc, argv, &thisArg, NULL);

        struct NAPI_RGB* rgb = new struct NAPI_RGB();

        uint32_t value;
        napi_get_value_uint32(env, argv[0], &value);
        rgb->r = static_cast<uint8_t>(value & 0xFF);
        napi_get_value_uint32(env, argv[1], &value);
        rgb->g = static_cast<uint8_t>(value & 0xFF);
        napi_get_value_uint32(env, argv[2], &value);
        rgb->b = static_cast<uint8_t>(value & 0xFF);

        napi_wrap(env, thisArg, reinterpret_cast<void*>(rgb), NAPI_RGB::Destructor, NULL, NULL);
        
        return thisArg;
    } else {
        OH_LOG_INFO(LOG_APP, "NAPI_RGB::Constructor called, not new target");
        size_t argc = 3;
        napi_value args[3];
        napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    
        napi_value cons;
        napi_get_reference_value(env, g_ref, &cons);
        napi_value instance;
        napi_new_instance(env, cons, argc, args, &instance);
    
        return instance;
    }
}

napi_value NAPI_RGB::GetR(napi_env env, napi_callback_info info) {
    OH_LOG_INFO(LOG_APP, "NAPI_RGB::GetR called");
    napi_value jsThis;
    napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);
    
    struct NAPI_RGB* rgb;
    napi_unwrap(env, jsThis, reinterpret_cast<void**>(&rgb));
    napi_value num;
    napi_create_uint32(env, rgb->r, &num);
        
    return num;
}

napi_value NAPI_RGB::SetR(napi_env env, napi_callback_info info) {
    OH_LOG_INFO(LOG_APP, "NAPI_RGB::SetR called");

    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_value jsThis;
    
    napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr);
    
    NAPI_RGB* rgb;
    napi_unwrap(env, jsThis, reinterpret_cast<void**>(&rgb));

    uint32_t value;
    napi_get_value_uint32(env, args[0], &value);
    rgb->r = static_cast<uint8_t>(value & 0xFF);

    return nullptr;
}

napi_value NAPI_RGB::GetG(napi_env env, napi_callback_info info) {
    napi_value jsThis;
    napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);
    
    NAPI_RGB* rgb;
    napi_unwrap(env, jsThis, reinterpret_cast<void**>(&rgb));
    napi_value num;
    napi_create_uint32(env, (uint32_t)rgb->g, &num);

    return num;
}


napi_value NAPI_RGB::SetG(napi_env env, napi_callback_info info) {
    OH_LOG_INFO(LOG_APP, "NAPI_RGB::SetG called");

    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_value jsThis;
    
    napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr);
    
    NAPI_RGB* rgb;
    napi_unwrap(env, jsThis, reinterpret_cast<void**>(&rgb));

    uint32_t value;
    napi_get_value_uint32(env, args[1], &value);
    rgb->r = static_cast<uint8_t>(value & 0xFF);

    return nullptr;
}


napi_value NAPI_RGB::GetB(napi_env env, napi_callback_info info) {
    napi_value jsThis;
    napi_get_cb_info(env, info, nullptr, nullptr, &jsThis, nullptr);
    
    NAPI_RGB* rgb;
    napi_unwrap(env, jsThis, reinterpret_cast<void**>(&rgb));
    napi_value num;
    napi_create_uint32(env, (uint32_t)rgb->b, &num);

    return num;
}


napi_value NAPI_RGB::SetB(napi_env env, napi_callback_info info) {
    OH_LOG_INFO(LOG_APP, "NAPI_RGB::SetB called");

    size_t argc = 3;
    napi_value args[3] = {nullptr};
    napi_value jsThis;
    
    napi_get_cb_info(env, info, &argc, args, &jsThis, nullptr);
    
    NAPI_RGB* rgb;
    napi_unwrap(env, jsThis, reinterpret_cast<void**>(&rgb));

    uint32_t value;
    napi_get_value_uint32(env, args[2], &value);
    rgb->r = static_cast<uint8_t>(value & 0xFF);

    return nullptr;
}

napi_value napi_get_rgb(napi_env env, napi_callback_info info)
{
    OH_LOG_INFO(LOG_APP, "get rgb color");
    size_t argc = 1;
    napi_value args[1] = {nullptr};

    napi_get_cb_info(env, info, &argc, args , nullptr, nullptr);
    
    // get number
    uint32_t color;
    napi_get_value_uint32(env, args[0], &color);
    
    // function call
    struct RGB rgb = get_rgb((Color)color);
    OH_LOG_INFO(LOG_APP, "cpp get rgb color, r: %{public}d, g: %{public}d, b: %{public}d", rgb.r, rgb.g, rgb.r);
    size_t newArgc = 3;
    napi_value newArgs[3] = {nullptr};
    napi_create_uint32(env, rgb.r, &newArgs[0]);
    napi_create_uint32(env, rgb.g, &newArgs[1]);
    napi_create_uint32(env, rgb.b, &newArgs[2]);

    napi_value cons;
    napi_get_reference_value(env, g_ref, &cons);
    napi_value instance;
    napi_new_instance(env, cons, newArgc, newArgs, &instance);

    
    return instance;

}

napi_value napi_init_color(napi_env env, napi_value exports) {
    napi_property_descriptor properties[] = {
      { "r", 0, 0, GetR, SetR, 0, napi_default, 0 },
      { "g", 0, 0, GetG, SetG, 0, napi_default, 0 },
      { "b", 0, 0, GetB, SetB, 0, napi_default, 0 },
    };

    napi_value cons;
    napi_define_class(env, "NAPI_RGB", NAPI_AUTO_LENGTH, Constructor, nullptr, 3,
                           properties, &cons);

    napi_create_reference(env, cons, 1, &g_ref);
    napi_set_named_property(env, exports, "NAPI_RGB", cons);
    return exports;
};