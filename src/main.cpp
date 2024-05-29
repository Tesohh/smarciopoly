#include "imaxcamera.hpp"
#include "raylib.h"
#include "raymath.h"
#include "tile.hpp"
#include "map.hpp"
#include <cstdio>

#define NOMINAL_WIDTH  1920
#define NOMINAL_HEIGHT 1080
#define NOMINAL_SIZE   (Vector2) {NOMINAL_WIDTH, NOMINAL_HEIGHT}

const Color MONOPOLY_COLOR = GetColor(0xC2FFCCFF);

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1080, 720, "Smarciopoly");
    SetTargetFPS(60);

    game::ImaxCamera cam({0}, NOMINAL_SIZE);
    cam.mode = game::ImaxCameraMode::DRAMATIC_FOLLOW;
    cam.target = Vector2 {0, 0};
    cam.zoom = cam.getNormalizedZoom();
    cam.normalize();

    game::Map map;
    map.tiles = game::getTiles();
    map.init();

    while (!WindowShouldClose()){
        if (IsWindowResized()) cam.normalize();
        cam.update(GetFrameTime());
        if (IsKeyPressed(KEY_G)) {
            cam.speed = 5;
            cam.followee = Vector2{588, 882};
            cam.targetZoom = 2;
        }
        if (IsKeyDown(KEY_H)) cam.followee.x -= 100;
        if (IsKeyDown(KEY_J)) cam.followee.y += 100;
        if (IsKeyDown(KEY_K)) cam.followee.y -= 100;
        if (IsKeyDown(KEY_L)) cam.followee.x += 100;
        if (IsKeyDown(KEY_R)) cam.normalize();

        BeginDrawing();
        BeginMode2D(cam);
        {
            ClearBackground(BLACK);
            DrawRectangle(0, 0, 1920, 1080, RAYWHITE);

            DrawRectangle(0, 0, 1078, 1078, MONOPOLY_COLOR);
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
