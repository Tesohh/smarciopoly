#include "imaxcamera.hpp"
#include "raylib.h"
#include "raymath.h"
#include "tile.hpp"
#include "map.hpp"
#include <cstdio>
#include <iostream>

#define NOMINAL_WIDTH MAP_SIZE
#define NOMINAL_HEIGHT MAP_SIZE
#define NOMINAL_SIZE   (Vector2) {NOMINAL_WIDTH, NOMINAL_HEIGHT}

const Color MONOPOLY_COLOR = GetColor(0xC2FFCCFF);

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1080, 720, "Smarciopoly");
    SetTargetFPS(60);

    Texture2D bg = LoadTexture("resources/bg.png");

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
            // cam.followee = Vector2{588, 882};
            cam.targetZoom = 1.2f;
        }
        if (IsKeyDown(KEY_J)) cam.followee.x -= 100;
        if (IsKeyDown(KEY_K)) cam.followee.y += 100;
        if (IsKeyDown(KEY_I)) cam.followee.y -= 100;
        if (IsKeyDown(KEY_L)) cam.followee.x += 100;
        if (IsKeyDown(KEY_R)) cam.normalize();


        BeginDrawing();
        BeginMode2D(cam);
        {
            ClearBackground(BLACK);
            // PERF: smerdolox (unefficient background drawing)
            for (int y = -10800; y < 10800; y += bg.height) {
                for (int x = -10800; x < 10800; x += bg.width) {
                    DrawTexture(bg, x, y, WHITE);
                }
            }

            DrawRectangle(0, 0, MAP_SIZE, MAP_SIZE, MONOPOLY_COLOR);
            for (game::Tile& tile : map.tiles) {
                tile.draw();
            }

            DrawFPS(-500, -500);
        }
        EndMode2D();
        EndDrawing();

    }

    UnloadTexture(bg);
    CloseWindow();
    return 0;
}
