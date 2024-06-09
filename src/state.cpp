#include "state.hpp"
#include "raylib.h"

// this is done just so the compiler doesnt yell at me for stupid oop reasons
game::_State::_State(): camera({0}, {0,0}) {}

void game::_State::deinit() {}

void game::_State::debug() {
    TraceLog(LOG_DEBUG,
             "[TurnState] currentPlayer:%d, currentState:%d, nextState:%d, timeSinceChange:%f",
             this->currentPlayer, this->currentState, this->nextState, this->secsSinceChange);
}

game::_State game::state;
