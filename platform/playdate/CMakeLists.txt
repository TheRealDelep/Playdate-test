cmake_minimum_required(VERSION 3.14)
set(CMAKE_C_STANDARD 11)

set(ENVSDK $ENV{PLAYDATE_SDK_PATH})

if (NOT ${ENVSDK} STREQUAL "")
	file(TO_CMAKE_PATH ${ENVSDK} SDK)
else()
	execute_process(
			COMMAND bash -c "egrep '^\\s*SDKRoot' $HOME/.Playdate/config"
			COMMAND head -n 1
			COMMAND cut -c9-
			OUTPUT_VARIABLE SDK
			OUTPUT_STRIP_TRAILING_WHITESPACE
	)
endif()

if (NOT EXISTS ${SDK})
	message(FATAL_ERROR "SDK Path not found; set ENV value PLAYDATE_SDK_PATH")
	return()
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_XCODE_GENERATE_SCHEME TRUE)

# Game Name Customization
set(PLAYDATE_GAME_NAME game)
set(PLAYDATE_GAME_DEVICE game_DEVICE)

project(${PLAYDATE_GAME_NAME} C ASM)

include_directories(
    "${CMAKE_SOURCE_DIR}/include" 
    "${CMAKE_SOURCE_DIR}/../include" 
    "${CMAKE_SOURCE_DIR}/../../game/include" 
)

file(
    GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.c"
    GLOB SOURCES "${CMAKE_SOURCE_DIR}/../../game/src/*.c"
    "${CMAKE_SOURCE_DIR}/main.c"
)

if (TOOLCHAIN STREQUAL "armgcc")
    add_executable(${PLAYDATE_GAME_DEVICE} ${SOURCES})
else()
    add_library(${PLAYDATE_GAME_NAME} SHARED ${SOURCES})
endif()

include(${SDK}/C_API/buildsupport/playdate_game.cmake)
