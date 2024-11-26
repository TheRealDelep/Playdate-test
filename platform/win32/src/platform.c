#include <SDL3/SDL.h>

#include "platform.h"
#include "win32.h"

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

}