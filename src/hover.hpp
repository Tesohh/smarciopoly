#ifndef HOVER_HPP
#define HOVER_HPP

#include "raylib.h"
#include "tile.hpp"

// Returns true if the cursor is in the bounds of the rectangle. Relies on the game::state.camera
bool IsHovered(Rectangle rect);

namespace game {
    void hoverTile(Tile *tile);
}

#endif
