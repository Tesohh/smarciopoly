#include "gamelogic.hpp"
#include "assets.hpp"
#include "imaxcamera.hpp"
#include "raylib.h"
#include "raymath.h"
#include "state.hpp"
#include "uigame.hpp"
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

// none of these functions run at the same time so
// in theory you can use lastExecutionTime for any function???
// no responsibility for what happens though
float lastExecutionTime = 0.0f;

Vector2 dice1pos = { 845, 2985 };
Vector2 dice2pos = { 1405, 2985 };
void game::rollDice() {
    if (game::state.secsSinceChange == 0) PlaySound(game::sounds.bell);

    if (game::state.secsSinceChange < 4) {
        if (game::state.secsSinceChange - lastExecutionTime > .1) {
            game::state.diceValue[0] = GetRandomValue(1, 6);
            game::state.diceValue[1] = GetRandomValue(1, 6);

            lastExecutionTime = game::state.secsSinceChange;
        }
    } else if (game::state.secsSinceChange < 6) {
    } else {
        lastExecutionTime = 0;
        game::state.nextState = game::TurnState::MOVING;
    }

    ui::drawDice(dice1pos, game::state.diceValue[0]);
    ui::drawDice(dice2pos, game::state.diceValue[1]);
}

int8_t playerTileBeforeMoving;
void game::moveFigure() {
    Player& player = state.players.at(state.currentPlayer);
    uint8_t diceValue = state.diceValue[0] + state.diceValue[1];

    if (state.secsSinceChange == 0) {
        playerTileBeforeMoving = player.currentTileIndex;

        // zom in the camera
        Tile tile = state.map.tiles.at(player.currentTileIndex);
        state.camera.speed = 25;
        state.camera.followee = tile.getCenter();
        state.camera.targetRotation = tile.rotation % 180 == 0 ? tile.rotation : tile.rotation + 180;
        state.camera.targetZoom = 0.5f;
    }

    if (diceValue + playerTileBeforeMoving <= player.currentTileIndex) {
        lastExecutionTime = 0;

        Tile tile = state.map.tiles.at(player.currentTileIndex);
        player.pos = tile.getCenter();
        player.pos.x -= player.texture.width/2.0;
        player.pos.y -= player.texture.height/2.0;

        // if multiple players are on the same tile, move me a bit down
        auto players = state.map.getPlayersOnTile(player.currentTileIndex);
        if (tile.rotation % 180 == 0) player.pos.y += (players.size()-1) * 100;
        else player.pos.x += (players.size()-1) * 100;

        state.camera.normalize();
        state.camera.speed = 25;
        state.camera.targetRotation = 0;
        state.nextState = game::TurnState::DICE; // TEMP
        return;
    }
    
    float moveFactor = (state.secsSinceChange - lastExecutionTime) * 2;
    moveFactor = Clamp(moveFactor, 0, 1);
    Tile tile = state.map.tiles.at(player.currentTileIndex);
    Vector2 tileCenter = tile.getCenter();
    Tile next = state.map.tiles.at(player.currentTileIndex+1);
    Vector2 nextCenter = next.getCenter();

    if (tile.rotation % 180 == 0) {
        player.pos.x = Lerp(tileCenter.x - (FIGURE_WIDTH / 2), nextCenter.x - (FIGURE_WIDTH / 2), moveFactor);
        float y = tileCenter.y - (FIGURE_HEIGHT / 2);
        player.pos.y = y - (300 * std::abs(std::cosf(Lerp(90, 180, moveFactor))));
    } else {
        player.pos.y = Lerp(tileCenter.y - (FIGURE_HEIGHT / 2), nextCenter.y - (FIGURE_HEIGHT / 2), moveFactor);
        float x = tileCenter.x - (FIGURE_WIDTH / 2);
        player.pos.x = x - (300 * std::abs(std::cosf(Lerp(90, 180, moveFactor))));
    }
    
    if (state.secsSinceChange - lastExecutionTime > .5) {
        player.currentTileIndex += 1;
        if (player.currentTileIndex > 30) { // overflow protection
            player.currentTileIndex = 0;
            playerTileBeforeMoving -= 31;
            TraceLog(LOG_DEBUG, "diceValue:%d, playerTileBefore:%d, player.tile:%d", diceValue, playerTileBeforeMoving, player.currentTileIndex);
        }

        Tile tile = state.map.tiles.at(player.currentTileIndex);
        state.camera.speed = 25;
        state.camera.targetRotation = tile.rotation % 180 == 0 ? tile.rotation : tile.rotation + 180;
        state.camera.followee = tile.getCenter();

        lastExecutionTime = state.secsSinceChange;
    }
}
