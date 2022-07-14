cmake_minimum_required(VERSION 3.16)
project(c-commons)
#project(c-commons C)
#set(CMAKE_C_STANDARD 11)

#Add the google test subdirectory
add_subdirectory(lib/googletest)

#include googletest/include dir
include_directories(lib/googletest/googletest/include)

#include the googlemock/include dir
include_directories(lib/googletest/googlemock/include)

file(GLOB_RECURSE COMMON_SRC src/*.c src/*.h)
message(STATUS "Files are ${COMMON_SRC}")
include_directories(src src/common_array src/common_matrix src/common_string src/common_number src/common_utility)
add_library(c-commons SHARED ${COMMON_SRC})

file(GLOB_RECURSE COMMON_TEST test/*.cpp test/*/*.cpp)
add_executable(c-commons-test ${COMMON_SRC} ${COMMON_TEST})

#Link with GoogleTest
target_link_libraries(c-commons-test gtest gtest_main)

#Link with GoogleMock
target_link_libraries(c-commons-test gmock gmock_main)

file(GLOB ARRAY_TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/common-array/*.txt)
file(GLOB MATRIX_TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/common-matrix/*.txt)
file(COPY ${ARRAY_TEST_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/common-array)
file(COPY ${MATRIX_TEST_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/common-matrix)