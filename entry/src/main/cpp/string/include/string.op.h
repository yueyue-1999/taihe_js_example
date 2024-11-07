//
// Created on 2024/10/31.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef MYAPPLICATION_STRING_OP_IMPL_H
#define MYAPPLICATION_STRING_OP_IMPL_H

#include <string>
#include <tuple>

std::tuple<std::string, std::string> ohos_split_str(std::string pstr, std::int32_t n);

#endif //MYAPPLICATION_STRING_OP_IMPL_H
