#include "state.hpp"

// this is done just so the compiler doesnt yell at me for stupid oop reasons
game::_State::_State(): camera({0}, {0,0}) {}

void game::_State::deinit() {}

game::_State game::state;
