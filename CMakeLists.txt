cmake_minimum_required(VERSION 3.8)
project(multi_type)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp multi_type.h)
add_executable(multi_type ${SOURCE_FILES})