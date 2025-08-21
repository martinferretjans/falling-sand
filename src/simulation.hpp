//
// Created by martin on 8/15/25.
//

#pragma once

#include "grid.hpp"

class Simulation {
public:
    Simulation(int width, int height, int cellSize) : grid(width, height, cellSize) {};
    void SetCellValue(int row, int column, int value);
    void Update();
private:
    Grid grid;
    void Draw();
    //Checks
};