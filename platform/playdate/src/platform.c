#include "string.h"
#include "pd_api.h"

#include "platform.h"
#include "playdate.h"
#include <stdio.h>

const char* default_font_path = "/System/Fonts/Asheville-Sans-14-Bold.pft";
LCDFont* default_font = NULL;

int PL_get_screen_width() { return 400; }
int PL_get_screen_height() { return 240; }

void PL_begin_draw() {
    api->graphics->clear(kColorWhite);
}

void PL_end_draw() {}
void PL_set_font(const char* path, int font_size) { }

void PL_use_default_font() {
    if (default_font == NULL) {
        const char* err;
        default_font = api->graphics->loadFont(default_font_path, &err);

        if (default_font == NULL) {
            api->system->error(
                "%s:%i Couldn't load font %s: %s",
                __FILE__, __LINE__, 
                default_font_path, 
                err
            );
        }

        api->graphics->setFont(default_font);
    }
}

void PL_draw_text(char* value, size_t len, int x, int y) {
    api->graphics->drawText(value, len, kASCIIEncoding, x, y);
}

void PL_log(const char* message, ...) {
    char* buffer = malloc(sizeof(char) * 255);
    
    va_list args;
    va_start(args, message);

    vsprintf(buffer, message, args);
    api->system->logToConsole(buffer);
    va_end(args);
}
