#include "map.hpp"

void game::Map::init() {
    std::printf("map::init()\n");
}

void game::Map::run() {
    std::printf("map::run()\n");
}

void game::Tile::draw() {
    std::printf("tile drawing...\n");
};

game::Tile newTile(std::string imagePath) {

}

game::Tile* game::getTiles() {
    return {
        
    };
}
