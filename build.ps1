$program = "game"
$platform = "win"
$run = $false

for ($i = 0; $i -lt $args.Count; i++)  {
    $arg = $args[$i]
    switch ($arg) {
        "run" { $run = $true; break }
        "pd" { $platform = "pd"; break }
        "editor" { $program = "editor"; break }
    }
}

if ($program -eq "editor" -and $platform -eq "pd") {
    echo Cannot build editor for platform playdate
    return
}

switch ($platform) {
    "win" { ./platform/win32/build.ps1; break }
    "pd"  { ./platform/playdate/build.ps1; break }
}

switch ($program) {
    "game" { 
        echo "Building sdl"
        cmake -S "platform/win32/libs/SDL" -B "platform/win32/libs/SDL/build" -G "Unix Makefiles"
        if (!$?) { return }
        
        cmake --build "platform/win32/libs/SDL/build"
        if (!$?) { return }

        echo "Building platform layer for win32"
        cmake -S $PSScriptRoot -B "platform/win32/build" -G "Unix Makefiles"
        if (!$?) { return }
        
        cmake --build "platform/win32/build"
        break 
    }
    "editor" { ./editor/build.ps1; break }
}

if (!$run) {
    return
}

if ($program -eq "editor") {
    ./editor/build/editor.exe
} else {
    switch ($platform) {
        "win" { ./platform/win32/build/game.exe; break }
        "pd" { PlaydateSimulator.exe ./platform/playdate/build/game.dll; break }
    }
}
