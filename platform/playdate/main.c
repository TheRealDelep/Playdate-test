#include <stdio.h>
#include <pd_api.h>

#include "game.h"

int update(void* user_data);
PlaydateAPI* api;

#ifdef _WINDLL
__declspec(dllexport)
#endif
int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg) {
    switch (event) {
        case kEventInit:
            printf("Hello, from playdate");
            api = pd;
            api->system->setUpdateCallback(update, pd);
            game_init();
            break;
        case kEventTerminate:
            break;
        default:
            break;
    } 

    return 0;
}

static int update(void* user_data) {
    float dt = api->system->getElapsedTime();
    api->system->resetElapsedTime();
    game_run(dt);
    return 0;
}
