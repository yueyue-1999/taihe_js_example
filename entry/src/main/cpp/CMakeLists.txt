# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(integer)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(DEFINED PACKAGE_FIND_FILE)
    include(${PACKAGE_FIND_FILE})
endif()

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/string/include
                    ${NATIVERENDER_ROOT_PATH}/integer/include
                    ${NATIVERENDER_ROOT_PATH}/small_rgb/include)

aux_source_directory(string/src STRING_SOURCE)
aux_source_directory(integer/src INTEGER_SOURCE)
aux_source_directory(small_rgb/src RGB_SOURCE)

add_library(entry SHARED napi_init.cpp ${STRING_SOURCE} ${INTEGER_SOURCE} ${RGB_SOURCE})
target_link_libraries(entry PUBLIC libace_napi.z.so libhilog_ndk.z.so)