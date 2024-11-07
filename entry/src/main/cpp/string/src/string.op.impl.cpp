//
// Created on 2024/10/31.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "string.op.h"

std::tuple<std::string, std::string> ohos_split_str(std::string pstr, std::int32_t n) {
    int32_t l = pstr.size();
    if (n > l) {
        n = l;
    } else if (n + l < 0) {
        n = 0;
    } else if (n < 0) {
        n = n + l;
    }
    return {
        pstr.substr(0, n),
        pstr.substr(n, l - n),
    };
}