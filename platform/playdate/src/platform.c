#include "pd_api.h"

#include "platform.h"
#include "playdate.h"

int PL_get_screen_width() { return 400; }
int PL_get_screen_height() { return 400; }

void PL_begin_draw() {
    api->graphics->clear(kColorBlack);
}

void PL_end_draw() {}

void PL_set_font(const char* path, int font_size) {

}

void PL_draw_text(char* value, size_t len, int x, int y) {
    api->graphics->drawText(value, len, kASCIIEncoding, x, y);
}
