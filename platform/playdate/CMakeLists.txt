cmake_minimum_required(VERSION 3.14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)

if (NOT $ENV{PLAYDATE_SDK_PATH} STREQUAL "")
	# Convert path from Windows
	file(TO_CMAKE_PATH ${ENVSDK} SDK)
endif()

if (NOT EXISTS ${SDK})
	message(FATAL_ERROR "SDK Path not found; set ENV value PLAYDATE_SDK_PATH")
	return()
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

# Game Name Customization
set(PLAYDATE_GAME_NAME hello_world)
set(PLAYDATE_GAME_DEVICE hello_world_DEVICE)

project(${PLAYDATE_GAME_NAME} C ASM)

include_directories(${CMAKE_SOURCE_DIR}/../include)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)

if (TOOLCHAIN STREQUAL "armgcc")
	add_executable(${PLAYDATE_GAME_DEVICE} src/main.c)
else()
	add_library(${PLAYDATE_GAME_NAME} SHARED src/main.c )
endif()

include(${SDK}/C_API/buildsupport/playdate_game.cmake)
