#include "platform.h"
#include "game.h"

void game_init() {}
void game_deinit() {}

void game_run(float dt) {
    int s_width = PL_get_screen_width();
    int s_height = PL_get_screen_height();

    PL_begin_draw();
    PL_draw_text("Hello, world!", 13, s_width / 2, s_height / 2);
    PL_end_draw();
}
