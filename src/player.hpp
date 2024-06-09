#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include <cstdint>
#include <vector>
namespace game {
    struct Player {
        Texture texture;
        std::vector<uint8_t> properties; // the indices of the tiles they possess pretty much
        int32_t coins; // not a uint as one can go negative and sell stuff
        
        Vector2 pos;
        
        void init(uint8_t index);
        void run();
        void deinit();
    };
}

#endif
