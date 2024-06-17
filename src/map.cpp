#include "map.hpp"
#include "raylib.h"
#include "state.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

void game::Map::init() {
    if (this->tiles.size() != 32) {
        TraceLog(LOG_FATAL, "Map initialized with wrong number of tiles (got: %li, want 32)\n", this->tiles.size());
        std::exit(1);
    }
}

void game::Map::run() {
    std::printf("map::run()\n");
}
    
std::vector<game::Player*> game::Map::getPlayersOnTile(int tileIndex) {
    std::vector<game::Player*> players;

    for (uint8_t i = 0; i < 4; i++) {
        Player player = state.players.at(i);
        if (player.currentTileIndex == tileIndex) players.push_back(&player);
    }

    return players;
}
