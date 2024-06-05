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
//    this->targetRotation = cam.rotation;
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

    Vector2 mapCenter = (Vector2){MAP_SIZE/2.0f,MAP_SIZE/2.0f};
    Vector2 screenCenter = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};

    this->offset = screenCenter;
    this->followee = mapCenter;

    this->targetZoom = this->getNormalizedZoom();
}

void game::ImaxCamera::rotate(int direction) {
    switch (direction) {
        case CLOCKWISE:
            this->targetRotation += 90;
            break;
        case ANTICLOCKWISE:
            this->targetRotation -= 90;
            break;
        default:
            break;
    }
}

void game::ImaxCamera::update(float delta) {
    switch (this->mode) {
        case game::ImaxCameraMode::NORMAL:
            break;
        case game::ImaxCameraMode::DRAMATIC_FOLLOW:
            Vector2 posDiff = Vector2Subtract(this->followee, this->target);
            float posDistance = Vector2Length(posDiff);

            float zoomDiff = this->targetZoom - this->zoom;
            float rotDiff = this->targetRotation - this->rotation;

            if (posDistance > 0) {
                float posSpeed = fmaxf(CAMERA_MOVE_ACCELERATION*posDistance, CAMERA_MOVE_MIN) * delta * speed;
                this->target = Vector2Add(this->target, Vector2Scale(posDiff, posSpeed/posDistance));
                if (posDistance < 1) this->target = this->followee;
            }

            if (zoomDiff != 0) {
                float zoomSpeed = fmaxf(CAMERA_ZOOM_ACCELERATION*zoomDiff, CAMERA_ZOOM_MIN) * delta * speed;
                this->zoom += zoomDiff * zoomSpeed;
            }

            // TODO: Figure out why rotating CLOCKWISE makes the camera kind of turn twice
            // my guess is it has something to do with the fact that rotDiff is negative or positive
            // after the animation the camera is in the right rotation but it still looks weird you know
            if(rotDiff != 0) {
                float rotSpeed = fmaxf(CAMERA_ROTATION_ACCELERATION*rotDiff, CAMERA_ROTATION_MIN) * delta * speed;
                this->rotation += rotDiff * rotSpeed;
            }
            break;
    }
}
