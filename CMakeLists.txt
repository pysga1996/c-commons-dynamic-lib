cmake_minimum_required(VERSION 3.16)
project(common-functions C)

set(CMAKE_C_STANDARD 11)

file(GLOB COMMON_SRC *.c *.h */*.c */*.h)
include_directories(common-array common-matrix common-string common-number common-utility)
add_library(common-functions SHARED ${COMMON_SRC})