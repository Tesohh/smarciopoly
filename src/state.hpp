#ifndef STATE_HPP
#define STATE_HPP

#include "map.hpp"
#include "player.hpp"
#include "imaxcamera.hpp"
#include <cstdint>

namespace game {
enum TurnState {
    NOTHING, // currentState can never be NOTHING except for at the start of the game 
    NAME_BANNER,
    DICE,
    DRAMATIC_ANIMATION,
    BUYING_PROPERTY,
    PAYING_ENEMY,
    SELLING_PROPERTIES,
};

struct _State {
    ImaxCamera camera;
    Map map;
    std::vector<Player> players;

    uint8_t currentPlayer;
    TurnState currentState;
    TurnState nextState;
    float timeSinceChange;
    
    Tile* hoveredTile;
    bool isTileHoverLocked;
    
    _State();
    void deinit();
    void debug();
};

extern _State state;
}

#endif
