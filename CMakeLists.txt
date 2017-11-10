cmake_minimum_required(VERSION 3.8)
project(keyvalue)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c parser.c node.c node.h parser.h)
add_library(keyvalue ${SOURCE_FILES})
add_executable(run ${SOURCE_FILES})