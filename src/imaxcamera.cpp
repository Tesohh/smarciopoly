#include "imaxcamera.hpp"
#include "raylib.h"
#include "raymath.h"
#include <cstdio>

game::ImaxCamera::ImaxCamera(Camera2D cam, Vector2 nominalSize) {
    this->target = cam.target;
    this->rotation = cam.rotation;
    this->zoom = cam.zoom;
    this->offset = cam.offset;

    this->nominalSize = nominalSize;
    this->targetZoom = cam.zoom;
    this->speed = CAMERA_DEFAULT_SPEED;
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
    this->speed = 20;
    this->followee = Vector2 {0,0};
    this->targetZoom = this->getNormalizedZoom();
}

void game::ImaxCamera::update(float delta) {
    switch (this->mode) {
        case game::ImaxCameraMode::NORMAL:
            break;
        case game::ImaxCameraMode::DRAMATIC_FOLLOW:
            Vector2 posDiff = Vector2Subtract(this->followee, this->target);
            float posDistance = Vector2Length(posDiff);

            float zoomDiff = this->targetZoom - this->zoom;

            if (posDistance > 0) {
                float posSpeed = fmaxf(CAMERA_MOVE_ACCELERATION*posDistance, CAMERA_MOVE_MIN) * delta * speed;
                this->target = Vector2Add(this->target, Vector2Scale(posDiff, posSpeed/posDistance));
                if (posDistance < 1) this->target = this->followee;
            }

            if (zoomDiff != 0) {
                float zoomSpeed = fmaxf(CAMERA_ZOOM_ACCELERATION*zoomDiff, CAMERA_ZOOM_MIN) * delta * speed;
                this->zoom += zoomDiff * zoomSpeed;
            }
            break;
    }
}
