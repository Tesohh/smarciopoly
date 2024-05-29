#include "map.hpp"
#include "raylib.h"
#include <cstdio>
#include <cstdlib>

void game::Map::init() {
    if (this->tiles.size() != 32) {
        TraceLog(LOG_FATAL, "Map initialized with wrong number of tiles (got: %li, want 32)\n", this->tiles.size());
        std::exit(1);
    }

    /*
    Vector2 cursor = { 882, 882 };
    int i = 0;

    for (; i<8; i++) {
        tiles[i].pos.x = cursor.x;
        tiles[i].pos.y = cursor.y;
        switch (tiles[i].tileType) {
            case game::TileType::GO: 
                tiles[i].rotation = 0;
                cursor.x -= 98;
                break;
            case game::TileType::PROPERTY: 
                tiles[i].rotation = 0;
                cursor.x -= 98;
                break;
        }
    }

    cursor.x += 98;
    for (; i<16; i++) {
        tiles[i].pos.x = cursor.x;
        tiles[i].pos.y = cursor.y;
        switch (tiles[i].tileType) {
            case game::TileType::GO: 
                tiles[i].rotation = 90;
                cursor.y -= 98;
                break;
            case game::TileType::PROPERTY: 
                tiles[i].rotation = 90;
                cursor.y -= 98;
                break;
        }
    }

    cursor.y += 98;
    for (; i<24; i++) {
        tiles[i].pos.x = cursor.x;
        tiles[i].pos.y = cursor.y;
        switch (tiles[i].tileType) {
            case game::TileType::GO: 
                tiles[i].rotation = 180;
                cursor.x += 98;
                break;
            case game::TileType::PROPERTY: 
                tiles[i].rotation = 180;
                cursor.x += 98;
                break;
        }
    }

    cursor.x -= 98;
    for (; i<32; i++) {
        tiles[i].pos.x = cursor.x;
        tiles[i].pos.y = cursor.y;
        switch (tiles[i].tileType) {
            case game::TileType::GO: 
                tiles[i].rotation = 270;
                cursor.y += 98;
                break;
            case game::TileType::PROPERTY: 
                tiles[i].rotation = 270;
                cursor.y += 98;
                break;
        }
    }
    */
}

void game::Map::run() {
    std::printf("map::run()\n");
}
