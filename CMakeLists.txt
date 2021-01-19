cmake_minimum_required(VERSION 3.16)
project(common-functions C)

set(CMAKE_C_STANDARD 11)

add_library(common-functions SHARED common-functions.h scan-util.c array-util.c
        string-util.c number-util.c constants.c file-util.c)