#ifndef ASSETS_HPP
#define ASSETS_HPP

#include "raylib.h"
#include <vector>
namespace game {
    struct _FontAssets {
        Font uiFont; 

        // not a constructor as init needs to be called after InitWindow
        void init();
        void deinit();
    };

    struct _SpriteAssets {
        std::vector<Image> figures; 
        Texture dice[6]; 

        void init();
        void deinit();
    };

    struct _SoundAssets {
        Sound bell;

        void init();
        void deinit();
    };

    extern _FontAssets fonts;
    extern _SpriteAssets sprites;
    extern _SoundAssets sounds;
}

#endif
