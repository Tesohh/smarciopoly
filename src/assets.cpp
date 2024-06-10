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

    this->figures.push_back(LoadImage("resources/figures/figure.png"));

    this->dice[0] = LoadTexture("resources/figures/dice1.png");
    this->dice[1] = LoadTexture("resources/figures/dice2.png");
    this->dice[2] = LoadTexture("resources/figures/dice3.png");
    this->dice[3] = LoadTexture("resources/figures/dice4.png");
    this->dice[4] = LoadTexture("resources/figures/dice5.png");
    this->dice[5] = LoadTexture("resources/figures/dice6.png");
}
void game::_SpriteAssets::deinit() {
    TraceLog(LOG_INFO, "Unloading sprites...");
    UnloadImage(this->figures.at(0));
    UnloadTexture(this->dice[0]);
    UnloadTexture(this->dice[1]);
    UnloadTexture(this->dice[2]);
    UnloadTexture(this->dice[3]);
    UnloadTexture(this->dice[4]);
    UnloadTexture(this->dice[5]);
}

game::_SpriteAssets game::sprites;
