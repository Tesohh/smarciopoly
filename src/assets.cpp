#include "assets.hpp"
#include "raylib.h"
#include <cstdio>

void game::_FontAssets::init() {
    TraceLog(LOG_INFO, "Loading fonts...");
    Font tubre = LoadFont("resources/fonts/karantina.ttf");
    TraceLog(LOG_INFO, "DIOTUBRESE.");
}
game::_FontAssets::~_FontAssets() {
    TraceLog(LOG_INFO, "Unloading fonts...");
    UnloadFont(this->uiFont);
}

game::_FontAssets game::fonts;
