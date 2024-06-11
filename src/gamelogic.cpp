#include "gamelogic.hpp"
#include "assets.hpp"
#include "raylib.h"
#include "state.hpp"
#include "uigame.hpp"
#include <cmath>
#include <cstdint>
#include <cstdio>

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

uint8_t playerTileBeforeMoving;
void game::moveFigure() {
    Player& player = state.players.at(state.currentPlayer);
    uint8_t diceValue = state.diceValue[0] + state.diceValue[1];

    if (state.secsSinceChange == 0) {
        playerTileBeforeMoving = player.currentTileIndex;

        // zom in the camera
        Tile tile = state.map.tiles.at(player.currentTileIndex);
        state.camera.followee = tile.getCenter();
        state.camera.targetZoom = 0.5f;
    }

    if (state.secsSinceChange < 1) return; // wait a second
    
    if (diceValue + playerTileBeforeMoving <= player.currentTileIndex) {
        state.nextState = game::TurnState::NOTHING; // TEMP
        return;
    }
    
    if (state.secsSinceChange - lastExecutionTime > .5) {
        player.currentTileIndex += 1;
        Tile tile = state.map.tiles.at(player.currentTileIndex);
        state.camera.followee = tile.getCenter();

        lastExecutionTime = state.secsSinceChange;
    }
}
