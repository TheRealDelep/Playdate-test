#include <pd_api.h>

#include "game.h"

int update(void* user_data);

PlaydateAPI* api;

int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg) {
    switch (event) {
        case kEventInit:
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
    return 0;
}
