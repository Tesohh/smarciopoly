#include "tile.hpp"
#include "raylib.h"
#include <cstdio>
#include <vector>

game::Tile::Tile(std::string spritePath, int x, int y, int rotation, TileType tileType, uint32_t cost, std::string zone) {
    this->sprite = LoadImage(spritePath.c_str());
    this->pos.x = x;
    this->pos.y = y;
    this->rotation = rotation;
    this->texture = LoadTextureFromImage(this->sprite);
    this->tileType = tileType;
    this->cost = cost;
    this->zone = zone;
}

void game::Tile::debugPrint() {
    std::printf("TYPE: %d, ROT: %d, X: %f, Y: %f\n", this->tileType, this->rotation, this->pos.x, this->pos.y);
}

void game::Tile::draw() {
    DrawTextureEx(this->texture, this->pos, this->rotation, 1.0f, WHITE);
};

std::vector<game::Tile> game::getTiles() {
    std::vector<game::Tile> tiles = {
        Tile("resources/tiles/samplego.png", 882*4, 882*4, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 784*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 686*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 588*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 490*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 392*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 294*4, 882*4, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, 882*4, 0, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/samplego.png", 0, 882*4, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (882-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (784-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (686-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (588-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (490-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (392-96)*4, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196*4, (294-96)*4, 90, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/samplego.png", 0, 0, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", (196+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", (294+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", (392+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", (490+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", (588+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", (686+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", (784+96)*4, 196*4, 180, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/samplego.png", 882*4, 0, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 294*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 392*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 490*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 588*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 686*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 784*4, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882*4, 882*4, 270, TileType::PROPERTY, 0, ""),
    };
    
    return tiles;
}
