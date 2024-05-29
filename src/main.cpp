#include "imaxcamera.hpp"
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

    game::ImaxCamera cam({0}, NOMINAL_SIZE);
    cam.setMode(game::ImaxCameraMode::DRAMATIC_FOLLOW);
    cam.followee = Vector2{588, 882};

    game::Map map;
    map.tiles = game::getTiles();
    map.init();
    for (game::Tile& tile : map.tiles) {
        tile.debugPrint();
    }

    while (!WindowShouldClose()){
        cam.update();
        if (IsWindowResized()) cam.normalize();

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
