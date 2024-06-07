#ifndef UI_HPP
#define UI_HPP

#include "raylib.h"
#include <string>

#define RECTANGLE_DEFAULT_BORDER 16
#define TEXT_DEFAULT_SPACING 4

namespace ui {
void drawBorderRect(Rectangle rect, Color color, int borderWidth = RECTANGLE_DEFAULT_BORDER);
void drawCenteredText(Rectangle rect, std::string str, Font font, float fontSize, Color tint);
void drawVerticallyCenteredText(Rectangle rect, float x, std::string str, Font font, float fontSize, Color tint);
void drawHorizontallyCenteredText(Rectangle rect, float y, std::string str, Font font, float fontSize, Color tint);
}

#endif
