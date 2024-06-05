#ifndef TILE_HPP
#define TILE_HPP
#include "raylib.h"
#include <cstdint>
#include <string>
#include <vector>

namespace game {
#define BORDER_OVERHANG 8   // extra border in each direction

#define TILE_WIDTH 392      // without 2 * BORDER_OVERHANG
#define TILE_HEIGHT 784     // without 2 * BORDER_OVERHANG

enum TileType {
    START,
    PRISON,
    AWARDS,
    POLICE,
    PROPERTY,
};

struct Tile {
    Vector2 pos = {0, 0};
    uint32_t rotation = 0;
    Image sprite;
    std::string spritePath;

    TileType tileType = TileType::PROPERTY;
    uint32_t cost = 0;
    std::string zone = "";
    uint8_t slotMachines = 0; // 1 slot = house, 4 slot -> shisha bar = hotel
    

    void draw();
    void updateTexture();
    void debugPrint();

    Tile(std::string spritePath, int x, int y, int rotation, TileType tileType, uint32_t cost, std::string zone);
    
    Texture2D texture;
    private: 
        Rectangle rect;
        Image editedImage;
};

// returns the 32 tiles
std::vector<Tile> getTiles();

}
#endif

