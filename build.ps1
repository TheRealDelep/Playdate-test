$program = "game"
$platform = "win32"
$run = $false

if (-not(Test-Path -Path "out/")) {
    mkdir out/
}

for ($i = 0; $i -lt $args.Count; $i++) {
    switch ($args[$i]) {
        "pd" { $platform = "playdate"; break }
        "editor" { $program = "editor"; break }
        "run" { $run = $true; break; }
    }
}

if ($program -eq "editor" -and $platform -eq "playdate") {
    echo "cannot build editor for playdate platform"
    return
}

$src = "platform/${platform}/main.c platform/${platform}/src/*.c game/src/*.c"
$include = "-Igame/include -Iplatform/include -Iplatform/win32/include -I${env:PLAYDATE_SDK_PATH}/C_API"
$libs = ""
$link_flags = ""
$flags = "-MJ compile_commands.json"

$out = ""
switch ($platform) {
    "win32" { 
        $out = "out/game.exe" 
        $include = "${include} -Iplatform/win32/libs/SDL/include -Iplatform/win32/libs/SDL_ttf/include"

        if (-not (Test-Path -Path "platform/win32/libs/SDL/build/SDL3.dll")) {
            cmake -S platform/win32/libs/SDL -B platform/win32/libs/SDL/build -G "Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMADS=ON
            cmake --build platform/win32/libs/SDL/build
        }

        if (-not(Test-Path -Path "out/SDL3.dll")) {
            cp "platform/win32/libs/SDL/build/SDL3.dll" "out/SDL3.dll"
        }

        if (-not (Test-Path -Path "platform/win32/libs/SDL/build/SDL3.dll")) {
            cmake -S platform/win32/libs/SDL -B platform/win32/libs/SDL/build -G "Unix Makefiles" -DCMAKE_EXPORT_COMPILE_COMMADS=ON
            cmake --build platform/win32/libs/SDL/build
        }

        if (-not(Test-Path -Path "out/SDL3.dll")) {
            cp "platform/win32/libs/SDL/build/SDL3.dll" "out/SDL3.dll"
        }

        $libs = "-L platform/win32/libs/SDL/build"
        $link_flags = "-lSDL3"
        break
    }
    "playdate" { 
        $out = "out/game.dll" 
        break
    }
}

$cc_command = "${env:cc} $src $include $libs -o $out $link_flags $flags"
echo $cc_command
$res = Invoke-Expression $cc_command
echo $res

#compile-commands generate by clang are wrongly formatted
$content = Get-Content -Raw -Path compile_commands.json
$content_fixed = $content.Substring(0, $content.Length -3)
$content = "[ $content_fixed ]"
Set-Content -Path .\compile_commands.json -Value $content

if (-not $?) { return }
& $out
