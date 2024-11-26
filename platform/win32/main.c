#include "stdio.h"

#include <SDL3/SDL.h>

#include "win32.h"
#include "game.h"

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("failed to initialize sdl");
        return 1;
    }

    window = SDL_CreateWindow("sdl-template", 800, 600, 0);
    
    if (window == NULL) {
        printf("failed to create window");
        return 1;
    }

    game_init(); 

    SDL_Event e;
    float dt = 0;

    while(true) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT || (
                e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {           
                goto exit;
            }

            dt = ((float)SDL_GetTicks() / 1000.0f) - dt;
            game_run(dt);
        }
    }

exit:
    game_deinit();
    return 0;
}
