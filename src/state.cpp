#include "state.hpp"

// this is done just so the compiler doesnt yell at me for stupid oop reasons
game::_State::_State(): camera({0}, {0,0}) {}

game::_State::~_State() {}

game::_State game::state;
