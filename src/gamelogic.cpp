#include "gamelogic.hpp"
#include "raylib.h"
#include "state.hpp"
#include "uigame.hpp"
#include <cmath>
#include <cstdio>

Vector2 dice1pos = { 845, 2985 };
Vector2 dice2pos = { 1405, 2985 };

float lastExecutionTime = 0.0f;

void game::rollDice() {
    if (game::state.secsSinceChange < 4) {
        if (game::state.secsSinceChange - lastExecutionTime > .1) {
            game::state.diceValue[0] = GetRandomValue(1, 6);
            game::state.diceValue[1] = GetRandomValue(1, 6);

            lastExecutionTime = game::state.secsSinceChange;
        }
    } else {
        lastExecutionTime = 0;
    }

    ui::drawDice(dice1pos, game::state.diceValue[0]);
    ui::drawDice(dice2pos, game::state.diceValue[1]);
}
