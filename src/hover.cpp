#include "hover.hpp"
#include "raylib.h"
#include "state.hpp"
#include "ui.hpp"


bool IsHovered(Rectangle rect) {
    if (!IsCursorOnScreen()) return false;

    Vector2 screenMousePosition = GetMousePosition();
    Vector2 mousePosition = GetScreenToWorld2D(screenMousePosition, game::state.camera);

    bool xMatch = mousePosition.x >= rect.x && mousePosition.x <= rect.x + rect.width;
    bool yMatch = mousePosition.y >= rect.y && mousePosition.y <= rect.y + rect.height;
    
    return xMatch && yMatch;
}

Rectangle hoverCardRect = {
    .x = 2550,
    .y = 2250,
    .width = 785,
    .height = 1176,
};

void game::hoverTile(Tile *tile) {
    DrawRectangleRec(tile->rect, GetColor(0xffffff44));

    switch (tile->tileType) {
    case START: case PRISON: case AWARDS: case POLICE:
        break;
    case PROPERTY:
        ui::drawBorderRect(hoverCardRect, WHITE);
    }
}
