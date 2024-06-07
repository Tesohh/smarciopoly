#include "ui.hpp"
#include "hover.hpp"
#include "raylib.h"
#include <string>

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

void ui::drawCenteredText(Rectangle rect, std::string str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str.c_str(), fontSize, TEXT_DEFAULT_SPACING);
    float x =  rect.width/2 - size.x/2 + rect.x;
    float y = rect.height/2 - size.y/2 + rect.y;

    DrawTextEx(font, str.c_str(), {x, y}, fontSize, TEXT_DEFAULT_SPACING, tint);
}

void ui::drawVerticallyCenteredText(Rectangle rect, float x, std::string str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str.c_str(), fontSize, TEXT_DEFAULT_SPACING);
    float y = rect.height/2 - size.y/2 + rect.y;

    DrawTextEx(font, str.c_str(), {x, y}, fontSize, TEXT_DEFAULT_SPACING, tint);
}

void ui::drawHorizontallyCenteredText(Rectangle rect, float y, std::string str, Font font, float fontSize, Color tint) {
    Vector2 size = MeasureTextEx(font, str.c_str(), fontSize, TEXT_DEFAULT_SPACING);
    float x = (rect.width/2 - size.x/2) + rect.x;

    DrawTextEx(font, str.c_str(), {x, y}, fontSize, TEXT_DEFAULT_SPACING, tint);
}

void ui::drawButton(Rectangle rect, std::string str, Font font, float fontSize, Color buttonTint, Color textTint, std::function<void()> callback) {
    drawBorderRect(rect, buttonTint);
    drawCenteredText(rect, str, font, fontSize, textTint);

    bool isHovered = IsHovered(rect);

     if (isHovered && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawRectangleRec(rect, GetColor(0x00000055));
    } else if (isHovered && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        callback();
    } else if (isHovered) {
        DrawRectangleRec(rect, GetColor(0xFFFFFF55));
    }
}

