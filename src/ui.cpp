#include "ui.hpp"
#include "raylib.h"

void ui::drawBorderRect(Rectangle rect, Color color, int borderWidth) {
    Rectangle inner = {
        .x = rect.x + borderWidth,
        .y = rect.y + borderWidth,
        .width = rect.width - borderWidth * 2,
        .height = rect.height - borderWidth * 2
    };

    DrawRectangleRec(rect, BLACK);
    DrawRectangleRec(inner, color);
}
