#include "hover.hpp"
#include "imaxcamera.hpp"
#include "raylib.h"
#include "state.hpp"
#include "tile.hpp"
#include "map.hpp"
#include "assets.hpp"
#include "raymath.h"

#define NOMINAL_WIDTH MAP_SIZE
#define NOMINAL_HEIGHT MAP_SIZE
#define NOMINAL_SIZE   (Vector2) {NOMINAL_WIDTH, NOMINAL_HEIGHT}

const Color MONOPOLY_COLOR = GetColor(0xC2FFCCFF);

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(1080, 720, "Smarciopoly");
    SetTargetFPS(60);

    game::fonts.init();

    Texture2D bg = LoadTexture("resources/bg.png");

    game::state.camera = game::ImaxCamera({0}, NOMINAL_SIZE);
    game::state.camera.mode = game::ImaxCameraMode::DRAMATIC_FOLLOW;
    game::state.camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
    game::state.camera.target = Vector2 {0, 0};
    game::state.camera.zoom = game::state.camera.getNormalizedZoom();
    game::state.camera.normalize();

    game::state.map = game::Map();
    game::state.map.tiles = game::getTiles();
    game::state.map.init();

    while (!WindowShouldClose()){
        if (IsWindowResized()) game::state.camera.normalize();
        game::state.camera.update(GetFrameTime());
        if (IsKeyPressed(KEY_G)) {
            game::state.camera.speed = 5;
            game::state.camera.followee = Vector2Add(game::state.map.tiles.at(8).pos, Vector2 {TILE_WIDTH, TILE_HEIGHT/2});
            game::state.camera.targetZoom = 1.2f;
        }
        if (IsKeyDown(KEY_J)) game::state.camera.followee.x -= 100;
        if (IsKeyDown(KEY_K)) game::state.camera.followee.y += 100;
        if (IsKeyDown(KEY_I)) game::state.camera.followee.y -= 100;
        if (IsKeyDown(KEY_L)) game::state.camera.followee.x += 100;

        if (IsKeyPressed(KEY_E)) game::state.camera.rotate(game::CLOCKWISE);
        if (IsKeyPressed(KEY_Q)) game::state.camera.rotate(game::ANTICLOCKWISE);

        if (IsKeyDown(KEY_R)) game::state.camera.normalize();
        BeginDrawing();
        BeginMode2D(game::state.camera);
        {
            ClearBackground(BLACK);
            // PERF: smerdolox (unefficient background drawing)
            for (int y = -10800; y < 10800; y += bg.height) {
                for (int x = -10800; x < 10800; x += bg.width) {
                    DrawTexture(bg, x, y, WHITE);
                }
            }

            DrawRectangle(0, 0, MAP_SIZE, MAP_SIZE, MONOPOLY_COLOR);
            for (game::Tile& tile : game::state.map.tiles) {
                tile.draw();
            }

            DrawFPS(-500, -500);
        }
        EndMode2D();
        EndDrawing();

    }

    UnloadTexture(bg);
    game::fonts.deinit();
    game::state.deinit();

    CloseWindow();
    return 0;
}
