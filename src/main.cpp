#include "camerautils.hpp"
#include "raylib.h"
#include "tile.hpp"
#include "map.hpp"

#define NOMINAL_WIDTH  1920
#define NOMINAL_HEIGHT 1080
#define NOMINAL_SIZE   (Vector2) {NOMINAL_WIDTH, NOMINAL_HEIGHT}

const Color MONOPOLY_COLOR = GetColor(0xC2FFCCFF);

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1080, 720, "Smarciopoly");
    SetTargetFPS(60);

    Camera2D cam = {0};
    game::normalizeCamera(&cam, NOMINAL_SIZE);

    game::Map map;
    map.tiles = game::getTiles();
    map.init();
    for (game::Tile& tile : map.tiles) {
        tile.debugPrint();
    }

    while (!WindowShouldClose()){
        if (IsWindowResized()) game::normalizeCamera(&cam, NOMINAL_SIZE);

        BeginDrawing();
        BeginMode2D(cam);
        {
            ClearBackground(BLACK);
            DrawRectangle(0, 0, 1920, 1080, RAYWHITE);

            DrawRectangle(0, 0, 1080, 1080, MONOPOLY_COLOR);
            // DrawRectangle(882, 882, 196, 196, BLUE);
            for (game::Tile& tile : map.tiles) {
                tile.draw();
            }
        }
        EndMode2D();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
