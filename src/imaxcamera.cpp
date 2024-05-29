#include "imaxcamera.hpp"
#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include <iostream>

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

    scaleFactor.x = actualSize.x / (nominalSize.x);
    scaleFactor.y = actualSize.y / (nominalSize.y);

    if(actualSize.x > actualSize.y) return scaleFactor.y;
    else return scaleFactor.x;

}

void game::ImaxCamera::normalize() {
    this->speed = 20;
    this->followee = Vector2 {(float)-((GetScreenWidth()-(MAP_SIZE * getNormalizedZoom()))/(getNormalizedZoom())/2),    // freaky formula
                              (float)-((GetScreenHeight()-(MAP_SIZE * getNormalizedZoom()))/(getNormalizedZoom())/2)};  // DO NOT TOUCH
    this->targetZoom = this->getNormalizedZoom();
    this->rotation = 0;
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
