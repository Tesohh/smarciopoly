#include "raylib.h"
#include "map.hpp"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1080, 720, "Smarciopoly");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            DrawFPS(100, 100);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
