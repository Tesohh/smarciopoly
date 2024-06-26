#ifndef IMAXCAMERA_HPP
#define IMAXCAMERA_HPP
#include "raylib.h"
#include "map.hpp"
namespace game {
    #define CAMERA_MOVE_ACCELERATION 0.8f
    #define CAMERA_ZOOM_ACCELERATION 0.8f
    #define CAMERA_ROTATION_ACCELERATION 1
    #define CAMERA_MOVE_MIN 2
    #define CAMERA_ZOOM_MIN 0.5f
    #define CAMERA_ROTATION_MIN 0.5f
    #define CAMERA_ROTATION_MAX 1.5f
    #define CAMERA_DEFAULT_SPEED 10

    enum ImaxCameraMode {
        NORMAL,
        DRAMATIC_FOLLOW,
    };

    enum ImaxCameraRotation {
        CLOCKWISE = 1,
        ANTICLOCKWISE,
    };

    struct ImaxCamera : Camera2D {
        ImaxCamera(Camera2D cam, Vector2 nominalSize);

        Vector2 followee;
        ImaxCameraMode mode;
        Vector2 nominalSize;
        Vector2 scaleFactor;
        float targetZoom;
        float targetRotation;
        float speed;
        int currentRotationDirection;

        float getNormalizedZoom();
        void normalize();
        void rotate(int direction);
        void update(float delta);
    };
}

#endif
