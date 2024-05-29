#ifndef IMAXCAMERA_HPP
#define IMAXCAMERA_HPP
#include "raylib.h"
namespace game {

    enum ImaxCameraMode {
        NORMAL,
        FOLLOW,
        DRAMATIC_FOLLOW,
    };

    struct ImaxCamera : Camera2D {
        ImaxCamera(Camera2D cam, Vector2 nominalSize);

        Vector2 followee;
        ImaxCameraMode mode;
        Vector2 nominalSize;
        float targetZoom;

        float getNormalizedZoom();
        void normalize();
        void setMode(ImaxCameraMode mode);
        void update();
    };
}

#endif
