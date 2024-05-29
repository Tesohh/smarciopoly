#include "imaxcamera.hpp"
#include "raylib.h"
#include "raymath.h"

game::ImaxCamera::ImaxCamera(Camera2D cam, Vector2 nominalSize) {
    this->target = cam.target;
    this->rotation = cam.rotation;
    this->zoom = cam.zoom;
    this->offset = cam.offset;

    this->nominalSize = nominalSize;
    this->targetZoom = cam.zoom;
}

float game::ImaxCamera::getNormalizedZoom() {
    Vector2 actualSize = { (float) GetScreenWidth(), (float) GetScreenHeight() };

    Vector2 scaleFactor;
    scaleFactor.x = actualSize.x / nominalSize.x;
    scaleFactor.y = actualSize.y / nominalSize.y;

    if (actualSize.x * scaleFactor.x < nominalSize.x) return scaleFactor.x;
    else if (actualSize.x * scaleFactor.x > nominalSize.x) return 1;
    else if (actualSize.y * scaleFactor.y < nominalSize.y) return scaleFactor.y;
    else if (actualSize.y * scaleFactor.y > nominalSize.y) return 1;
    else return 1;
}

void game::ImaxCamera::normalize() {
    this->targetZoom = this->getNormalizedZoom();
}

void game::ImaxCamera::setMode(game::ImaxCameraMode mode) {
    this->mode = mode;
    switch (this->mode) {
        case game::ImaxCameraMode::NORMAL:
            break;
        case FOLLOW:
            this->targetZoom = getNormalizedZoom();
        case DRAMATIC_FOLLOW:
            this->targetZoom = 2;
        }
}

void game::ImaxCamera::update() {
    switch (this->mode) {
        case game::ImaxCameraMode::NORMAL:
            break;
        case game::ImaxCameraMode::FOLLOW:
        case game::ImaxCameraMode::DRAMATIC_FOLLOW:
            Vector2 posDiff = Vector2Subtract(this->followee, this->target);
            float posDistance = Vector2Length(posDiff);

            float zoomDiff = this->targetZoom - this->zoom;

            if (posDistance > 10 && zoomDiff > 0) {
                float posSpeed = fmaxf(0.8*posDistance, 2) * 0.1;
                this->target = Vector2Add(this->target, Vector2Scale(posDiff, posSpeed/posDistance));

                float zoomSpeed = fmaxf(0.8*zoomDiff, 1) * 0.1;
                this->zoom += zoomDiff * zoomSpeed;
            }
            break;
    }
}
