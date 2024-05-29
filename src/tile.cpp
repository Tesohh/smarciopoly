#include "tile.hpp"
#include "raylib.h"
#include <vector>

game::Tile::Tile(std::string spritePath, TileType tileType, uint32_t cost, std::string zone) {
    this->sprite = LoadImage(spritePath.c_str());
    this->texture = LoadTextureFromImage(this->sprite);
    this->tileType = tileType;
    this->cost = cost;
    this->zone = zone;
}

void game::Tile::draw() {
    DrawTexture(this->texture, this->pos.x, this->pos.y, WHITE);
};

std::vector<game::Tile> game::getTiles() {
    std::vector<game::Tile> tiles = {
        Tile("resources/tiles/gosample.png", TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/gosample.png", TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/gosample.png", TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/gosample.png", TileType::GO, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
        Tile("resources/tiles/sample.png", TileType::PROPERTY, 0, ""),
    };
    
    return tiles;
}
