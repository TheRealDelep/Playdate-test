echo "Building sdl"
cmake -S "${PSScriptRoot}/libs/SDL" -B "${PSScriptRoot}/libs/SDL/build" -G "Unix Makefiles"
if (!$?) { return }

cmake --build "${PSScriptRoot}/libs/SDL/build"
if (!$?) { return }

echo "Building platform layer for win32"
cmake -S $PSScriptRoot -B "${PSScriptRoot}/build" -G "Unix Makefiles"
if (!$?) { return }

cmake --build "${PSScriptRoot/build}"
