#include "hover.hpp"
#include "assets.hpp"
#include "raylib.h"
#include "smarciomath.hpp"
#include "state.hpp"
#include "tile.hpp"
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
    .width = 786,
    .height = 1176,
};

Rectangle nameTagRect = {
    .x = 2609,
    .y = 2309,
    .width = 668,
    .height = 164,
};

Rectangle infoBoxRect = {
    .x = 2609,
    .y = 2490,
    .width = 668,
    .height = 570,
};

Rectangle button1Rect = {
    .x = 2609,
    .y = 3080,
    .width = 668,
    .height = 124,
};

Rectangle button2Rect = {
    .x = 2609,
    .y = 3230,
    .width = 668,
    .height = 124,
};

void noop_button_callback() {}

void ui::hoverTile(game::Tile *tile) {
    DrawRectangleRec(tile->rect, GetColor(0xffffff44));

    switch (tile->tileType) {
    case game::START: case game::PRISON: case game::AWARDS: case game::POLICE:
    case game::PROBABILITY: case game::CHANCE:
        // return and don't do anything else
        return;
        break;
    case game::PROPERTY:
        break;
    }

    ui::drawBorderRect(hoverCardRect, RAYWHITE);

    ui::drawBorderRect(nameTagRect, game::getColorFromZone(tile->zone));
    ui::drawHorizontallyCenteredText(nameTagRect, 2326, tile->name, game::fonts.uiFont, 128, WHITE);

    ui::drawBorderRect(infoBoxRect, RAYWHITE);

    ui::drawButton(button1Rect, "Bottone 1", game::fonts.uiFont, 96, GetColor(0xEA2424FF), BLACK, &noop_button_callback);
    ui::drawButton(button2Rect, "Bottone 2", game::fonts.uiFont, 96, GetColor(0x27AE60FF), BLACK, &noop_button_callback);
}
