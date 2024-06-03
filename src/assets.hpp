#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "raylib.h"
namespace game {
    struct _FontAssets {
        Font uiFont; 

        void init();
        ~_FontAssets();
    };

    extern _FontAssets fonts;
}

#endif
