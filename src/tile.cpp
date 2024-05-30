#include "tile.hpp"
#include "raylib.h"
#include <cstdio>
#include <string>
#include <vector>

game::Tile::Tile(std::string spritePath, int x, int y, int rotation, TileType tileType, uint32_t cost, std::string zone) {
    this->spritePath = spritePath;
    this->sprite = LoadImage(this->spritePath.c_str());
    this->pos.x = x;
    this->pos.y = y;
    this->rotation = rotation;
    this->tileType = tileType;
    this->cost = cost;
    this->zone = zone;

    updateTexture();
}

void game::Tile::debugPrint() {
    std::printf("TYPE: %d, ROT: %d, X: %f, Y: %f\n", this->tileType, this->rotation, this->pos.x, this->pos.y);
}

void game::Tile::updateTexture() { 
    // PERF: image and texture should be unlaoded
    this->editedImage = ImageCopy(this->sprite);

    if (this->tileType == TileType::PROPERTY) {
        std::string str = "$" + std::to_string(this->cost);
        int textWidth = MeasureText(str.c_str(), 110);
        int textX = this->editedImage.width / 2 - textWidth / 2;

        ImageDrawText(&this->editedImage, str.c_str(), textX, 655, 110, BLACK);
        // ImageDrawTextEx(&this->editedImage,
        //                 LoadFont("resources/fonts/karantina.ttf"),
        //                 std::to_string(this->cost).c_str(),
        //                 Vector2{0,0},
        //                 128,
        //                 0,
        //                 BLACK);
    }

    this->texture = LoadTextureFromImage(this->editedImage);
}

void game::Tile::draw() {
    DrawTextureEx(this->texture, this->pos, this->rotation, 1.0f, WHITE);
};

std::vector<game::Tile> game::getTiles() {
    std::vector<game::Tile> tiles = {
        Tile("resources/tiles/start.png", 882*4, 882*4, 0, TileType::START, 0, ""),
        Tile("resources/tiles/baraccopoli.png", 784*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/ecomostro.png", 686*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/viadeimulini.png", 588*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/casanova.png", 490*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/k21.png", 392*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/chickenhut.png", 294*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/kebz.png", 196*4, 882*4, 0, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/prison.png", 0, 882*4, 0, TileType::PRISON, 0, ""),
        Tile("resources/tiles/probability.png", 196*4, (882-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/acquarena.png", 196*4, (784-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/acquarena.png", 196*4, (686-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/bolzanosud.png", 196*4, (588-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/max.png", 196*4, (490-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/life.png", 196*4, (392-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/baila.png", 196*4, (294-96)*4, 90, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/awards.png", 0, 0, 0, TileType::AWARDS, 0, ""),
        Tile("resources/tiles/talvera.png", (196+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/yogurteria.png", (294+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/stationpark.png", (392+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/brixtown.png", (490+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/chance.png", (588+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/twenty.png", (686+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/noi.png", (784+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/police.png", 882*4, 0, 0, TileType::POLICE, 0, ""),
        Tile("resources/tiles/baita.png", 882*4, 294*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/bronzolo.png", 882*4, 392*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/probability.png", 882*4, 490*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/fortezza.png", 882*4, 588*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/mino.png", 882*4, 686*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/chance.png", 882*4, 784*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/rikilento.png", 882*4, 882*4, 270, TileType::PROPERTY, 100, ""),
    };
    
    return tiles;
}
