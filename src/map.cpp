#include "map.hpp"
#include "raylib.h"
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
