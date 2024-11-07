#include "napi/native_api.h"
#include "string.op.napi.h"
#include "integer.op.napi.h"
#include "rgb.base.napi.h"


EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        { "sub", nullptr, napi_ohos_int_sub, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "split_str", nullptr, napi_ohos_split_str, nullptr, nullptr, nullptr, napi_default, nullptr },
        { "get_rgb", nullptr, napi_get_rgb, nullptr, nullptr, nullptr, napi_default, nullptr }
    };
    
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    
    napi_init_rgb(env, exports);
    return exports;
    
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void*)0),
    .reserved = { 0 },
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
