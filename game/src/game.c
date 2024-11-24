#include "stdio.h"
#include "game.h"
#include "platform.h"

void game_hello() {
    platform_hello();
    printf("Hello from game!");
}
