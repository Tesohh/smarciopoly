#include "assets.hpp"
#include "raylib.h"

void game::_FontAssets::init() {
    TraceLog(LOG_INFO, "Loading fonts...");
    game::fonts.uiFont = LoadFontEx("resources/fonts/karantina.ttf", 128, 0, 250);
}
void game::_FontAssets::deinit() {
    TraceLog(LOG_INFO, "Unloading fonts...");
    UnloadFont(this->uiFont);
}

game::_FontAssets game::fonts;
