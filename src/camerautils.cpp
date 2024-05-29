#include "camerautils.hpp"
#include "raylib.h"

void game::normalizeCamera(Camera2D *cam, Vector2 nominalSize) {
    Vector2 actualSize = { (float) GetScreenWidth(), (float) GetScreenHeight() };

    Vector2 scaleFactor;
    scaleFactor.x = actualSize.x / nominalSize.x;
    scaleFactor.y = actualSize.y / nominalSize.y;

    // WORKING
    // if (actualSize.x > actualSize.y) cam->zoom = scaleFactor.y;
    // if (actualSize.y > actualSize.x) cam->zoom = scaleFactor.x;
    
    // EXPERIMENTAL
    // if (actualSize.x < nominalSize.x) cam->zoom = scaleFactor.x;
    // else if (actualSize.x > nominalSize.x) cam->zoom = scaleFactor.y;
    // else if (actualSize.y < nominalSize.y) cam->zoom = scaleFactor.y;
    // else if (actualSize.y > nominalSize.y) cam->zoom = scaleFactor.x;

    // DANGEROUS
    if (actualSize.x * scaleFactor.x < nominalSize.x) cam->zoom = scaleFactor.x;
    else if (actualSize.x * scaleFactor.x > nominalSize.x) cam->zoom = 1;
    else if (actualSize.y * scaleFactor.y < nominalSize.y) cam->zoom = scaleFactor.y;
    else if (actualSize.y * scaleFactor.y > nominalSize.y) cam->zoom = 1;

    // CRAZY WINS
    // if (scaleFactor.x < 1) cam->zoom = scaleFactor.x;
    // else if (scaleFactor.x > 1) cam->zoom = 1;
    // else if (scaleFactor.y < 1) cam->zoom = scaleFactor.y;
    // else if (scaleFactor.y > 1) cam->zoom = 1;
}
