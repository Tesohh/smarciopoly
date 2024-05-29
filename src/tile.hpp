#ifndef TILE_HPP
#define TILE_HPP
#include "raylib.h"
#include <cstdint>
#include <string>
#include <vector>

namespace game {

enum TileType {
    GO,
    PROPERTY,
};

struct Tile {
    Vector2 pos = {0, 0};
    uint32_t rotation = 0;
    Image sprite;

    TileType tileType = TileType::PROPERTY;
    uint32_t cost = 0;
    std::string zone = "";
    uint8_t slotMachines = 0; // 1 slot = house, 4 slot -> shisha bar = hotel
    

    void draw();
    void debugPrint();

    Tile(std::string spritePath, int x, int y, int rotation, TileType tileType, uint32_t cost, std::string zone);

    private: Texture2D texture;
};

// returns the 32 tiles
std::vector<Tile> getTiles();

}
#endif

