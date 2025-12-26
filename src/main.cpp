#include <iostream>

#include "raylib.h"
#include "simulation.hpp"

const int CELL_SIZE = 10;
const int WINDOW_WIDTH = 750;
const int WINDOW_HEIGHT = 750;

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Falling Sand");
    SetTargetFPS(60);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    //Simulation loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            simulation.SetCellValue(GetMouseY() / CELL_SIZE, GetMouseX() / CELL_SIZE, MaterialType::Sand);
        }
        simulation.Update();
        DrawRectangle(GetMouseX(), GetMouseY(),CELL_SIZE,CELL_SIZE,MATERIALS[static_cast<int>(MaterialType::Sand)].color);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
