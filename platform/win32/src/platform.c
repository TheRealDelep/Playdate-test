#include <stdio.h>
 
#include <SDL3/SDL.h>

#include "win32.h"
#include "platform.h"

int PL_get_screen_width() {
    int width;
    SDL_GetWindowSize(window, &width, NULL);
    return width;
}

int PL_get_screen_height() {
    int height;
    SDL_GetWindowSize(window, NULL, &height);
    return height;
}

void PL_draw_text(char* value, int x, int y) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDebugText(renderer, 0, 0, "Hello, world!");
}

void PL_begin_draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void PL_end_draw() {
    SDL_RenderPresent(renderer);
}