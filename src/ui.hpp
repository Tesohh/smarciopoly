#ifndef UI_HPP
#define UI_HPP

#include "raylib.h"

#define RECTANGLE_DEFAULT_BORDER 16

namespace ui {
    void drawBorderRect(Rectangle rect, Color color, int borderWidth = RECTANGLE_DEFAULT_BORDER);
}

#endif
