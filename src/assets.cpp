#include "assets.hpp"
#include "raylib.h"

void game::_FontAssets::init() {
    TraceLog(LOG_INFO, "Loading fonts...");
    game::fonts.uiFont = LoadFont("resources/fonts/karantina.ttf");
}
void game::_FontAssets::deinit() {
    TraceLog(LOG_INFO, "Unloading fonts...");
    UnloadFont(this->uiFont);
}

game::_FontAssets game::fonts;
