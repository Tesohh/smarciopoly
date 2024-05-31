#ifndef MAP_HPP
#define MAP_HPP

#include "tile.hpp"
#include <vector>
namespace game {
#define MAP_SIZE 4312

struct Map {
    std::vector<Tile> tiles;

    void init();
    void run();
};


}

#endif
