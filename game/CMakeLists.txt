cmake_minimum_required(VERSION 3.14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(game_lib)

set(CMAKE_C_STANDARD 17)

include_directories("include")
include_directories("${CMAKE_SOURCE_DIR}/../platform/include")

file(GLOB_RECURSE SOURCES src/*.c)
add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCES})
