#ifndef STATE_HPP
#define STATE_HPP

#include "map.hpp"
#include "raylib.h"
#include "imaxcamera.hpp"

namespace game {
    struct _State {
        ImaxCamera camera;
        Map map;
        
        Tile* hoveredTile;
        bool isTileHoverLocked;
        
        _State();
        void deinit();
    };

    extern _State state;
}

#endif
