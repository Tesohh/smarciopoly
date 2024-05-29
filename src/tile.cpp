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
        Tile("resources/tiles/samplego.png", 882, 882, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 784, 882, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 686, 882, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 588, 882, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 490, 882, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 392, 882, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 294, 882, 0, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196, 882, 0, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/samplego.png", 0, 882, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 196, 882-96, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196, 784-96, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196, 686-96, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/campiconi.png", 196, 588-96, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196, 490-96, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196, 392-96, 90, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 196, 294-96, 90, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/samplego.png", 0, 0, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 196+96, 196, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 294+96, 196, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 392+96, 196, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 490+96, 196, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 588+96, 196, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 686+96, 196, 180, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 784+96, 196, 180, TileType::PROPERTY, 0, ""),

        Tile("resources/tiles/samplego.png", 882, 0, 0, TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", 882, 294, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882, 392, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882, 490, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882, 588, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882, 686, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", 882, 784, 270, TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/rikilento.png", 882, 882, 270, TileType::PROPERTY, 0, ""),
    };
    
    return tiles;
}
