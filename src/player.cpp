#include "player.hpp"
#include "assets.hpp"
#include "raylib.h"

Color colors[] = {RED, BLUE, GREEN, YELLOW};

void game::Player::init(uint8_t index) {
    Image figure = ImageCopy(game::sprites.figures[0]);
    ImageColorTint(&figure, colors[index]);
    this->texture = LoadTextureFromImage(figure);
    UnloadImage(figure);
}

void game::Player::run() {
    DrawTexture(this->texture, this->pos.x, this->pos.y, WHITE);
}

void game::Player::deinit() {
    UnloadTexture(this->texture);
}