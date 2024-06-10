#ifndef STATE_HPP
#define STATE_HPP

#include "map.hpp"
#include "player.hpp"
#include "imaxcamera.hpp"
#include <cstdint>

namespace game {
enum TurnState : uint8_t {
    NOTHING, // currentState can never be NOTHING except for at the start of the game 
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
    float secsSinceChange; // PROTIP: if it's at 0 you know it's the first cycle inside that state

    uint8_t diceValue[2];
    
    Tile* hoveredTile;
    bool isTileHoverLocked;
    
    _State();
    void deinit();
    void debug();
};

extern _State state;
}

#endif
