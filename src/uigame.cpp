#include "uigame.hpp"
#include "assets.hpp"
#include "raylib.h"
#include <cstdint>

void ui::drawDice(Vector2 pos, uint8_t value) {
    if (value < 1) value = 1;
    if (value > 6) value = 6;
    DrawTexture(game::sprites.dice[value-1], pos.x, pos.y, WHITE); 
}
