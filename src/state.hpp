#ifndef STATE_HPP
#define STATE_HPP

#include "map.hpp"
#include "raylib.h"
#include "imaxcamera.hpp"

namespace game {
    struct _State {
        ImaxCamera camera;
        Map map;
        
        _State();
        ~_State();
    };

    extern _State state;
}

#endif
