#ifndef MAP_HPP
#define MAP_HPP

#include "tile.hpp"
#include <vector>
namespace game {
#define MAP_SIZE 1078

struct Map {
    std::vector<Tile> tiles;

    void init();
    void run();
};


}

#endif
