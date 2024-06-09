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

void game::_SpriteAssets::init() {
    TraceLog(LOG_INFO, "Loading sprites...");

    this->figures.push_back(LoadImageSvg("resources/figures/figure.svg", 150, 315));
}
void game::_SpriteAssets::deinit() {
    TraceLog(LOG_INFO, "Unloading sprites...");
    UnloadImage(this->figures.at(0));
}

game::_SpriteAssets game::sprites;
