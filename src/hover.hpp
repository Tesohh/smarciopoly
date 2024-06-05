#ifndef HOVER_HPP
#define HOVER_HPP

#include "raylib.h"

// Credits to ChatGPT
Rectangle RotateRectangle(Rectangle rectangle, float rotation);

// Returns true if the cursor is in the bounds of the rectangle. Relies on the game::state.camera
bool IsHovered(Rectangle rect);

#endif
