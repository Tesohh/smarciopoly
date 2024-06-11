#include "gamelogic.hpp"
#include "player.hpp"
#include "ui.hpp"
#include "hover.hpp"
#include "imaxcamera.hpp"
#include "raylib.h"
#include "state.hpp"
#include "tile.hpp"
#include "map.hpp"
#include "assets.hpp"
#include "raymath.h"
#include <cstdio>

#define NOMINAL_WIDTH MAP_SIZE
#define NOMINAL_HEIGHT MAP_SIZE
#define NOMINAL_SIZE   (Vector2) {NOMINAL_WIDTH, NOMINAL_HEIGHT}

const Color MONOPOLY_COLOR = GetColor(0xC2FFCCFF);

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(1080, 720, "Smarciopoly");
    InitAudioDevice();
    SetTargetFPS(60);

    #ifdef DEVBUILD
        SetTraceLogLevel(LOG_DEBUG);
    #endif
    #ifndef DEVBUILD
        SetTraceLogLevel(LOG_WARNING);
    #endif


    game::fonts.init();
    game::sprites.init();
    game::sounds.init();

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

    for (int i = 0; i < 4; i++) {
        game::state.players.push_back(game::Player());
        game::state.players.at(i).init(i);
    }

    // TEMP:
    game::state.players.at(0).pos = {100, 100};
    game::state.players.at(1).pos = {200, 100};
    game::state.players.at(2).pos = {300, 100};
    game::state.players.at(3).pos = {400, 100};
    // :TEMP
    
    game::state.nextState = game::TurnState::DICE;

    while (!WindowShouldClose()){
        if (IsWindowResized()) game::state.camera.normalize();
        game::state.camera.update(GetFrameTime());

        // State management 
        game::state.secsSinceChange += GetFrameTime();
        if (game::state.nextState != game::TurnState::NOTHING) {
            game::state.currentState = game::state.nextState;
            game::state.nextState = game::TurnState::NOTHING;
            game::state.secsSinceChange = 0;
            game::state.isTileHoverLocked = false;
            game::state.debug();
        }


        // Input
        // TEMP:
        if (IsKeyPressed(KEY_G)) {
            game::state.camera.speed = 5;
            game::state.camera.followee = game::state.map.tiles.at(1).getCenter();
            game::state.camera.targetZoom = 1.2f;
        }
        if (IsKeyDown(KEY_J)) game::state.camera.followee.x -= 100;
        if (IsKeyDown(KEY_K)) game::state.camera.followee.y += 100;
        if (IsKeyDown(KEY_I)) game::state.camera.followee.y -= 100;
        if (IsKeyDown(KEY_L)) game::state.camera.followee.x += 100;
        // :TEMP

        if (IsKeyPressed(KEY_E)) game::state.camera.rotate(game::CLOCKWISE);
        if (IsKeyPressed(KEY_Q)) game::state.camera.rotate(game::ANTICLOCKWISE);

        if (IsKeyDown(KEY_R)) game::state.camera.normalize();

        // Rendering && game logic
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

            for (game::Player& player : game::state.players)
                player.run();

            if (game::state.hoveredTile != nullptr)
                ui::hoverTile(game::state.hoveredTile);

            switch (game::state.currentState) {
            case game::NOTHING: break;
            case game::DICE: game::rollDice(); break;
            case game::MOVING: game::moveFigure(); break;
            case game::DRAMATIC_ANIMATION: break;
            case game::BUYING_PROPERTY: break;
            case game::PAYING_ENEMY: break;
            case game::SELLING_PROPERTIES: break;
            }

            if (!game::state.isTileHoverLocked) // this is done to hide the hoverTile
                game::state.hoveredTile = nullptr;

            DrawFPS(-500, -500);
        }
        EndMode2D();
        EndDrawing();
    }

    UnloadTexture(bg);
    game::fonts.deinit();
    game::sprites.deinit();
    game::sounds.deinit();
    game::state.deinit();

    for (game::Player& player : game::state.players) {
        player.deinit();
    }

    CloseWindow();
    return 0;
}
