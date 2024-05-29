#include "camerautils.hpp"
#include "raylib.h"
#include "tile.hpp"
#include "map.hpp"
#include <iostream>

#define NOMINAL_WIDTH  1920
#define NOMINAL_HEIGHT 1080
#define NOMINAL_SIZE   (Vector2) {NOMINAL_WIDTH, NOMINAL_HEIGHT}

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1080, 720, "Smarciopoly");
    SetTargetFPS(60);

    Camera2D cam = {0};
    game::normalizeCamera(&cam, NOMINAL_SIZE);

    game::Tile tile("resources/tiles/sample.png", game::TileType::PROPERTY, 0, "zesty");

    while (!WindowShouldClose()){
        if (IsWindowResized()) game::normalizeCamera(&cam, NOMINAL_SIZE);

        BeginDrawing();
        BeginMode2D(cam);
        {
            ClearBackground(BLACK);
            DrawRectangle(0, 0, 1920, 1080, RAYWHITE);
            DrawFPS(100, 100);
            tile.draw();
            DrawRectangle(0, 0, 1080, 1080, RED);
            DrawRectangle(882, 882, 196, 196, BLUE);
        }
        EndMode2D();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
