#include "stdio.h"
#include "game.h"
#include "SDL3/SDL.h"

int main() {
    printf("Hello from win32! main.c\n");
    game_hello();

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("failed to initialize sdl");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("sdl-template", 800, 600, 0);
    
    if (window == NULL) {
        printf("failed to create window");
        return 1;
    }

    bool should_quit = false;
    SDL_Event e;

    while(!should_quit) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT || (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
                should_quit = true;
            }
        }
    }

    return 0;
}
