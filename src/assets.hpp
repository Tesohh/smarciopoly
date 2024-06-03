#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "raylib.h"
namespace game {
    struct _FontAssets {
        Font uiFont; 

        // not a constructor as init needs to be called after InitWindow
        void init();
        ~_FontAssets();
    };

    extern _FontAssets fonts;
}

#endif
