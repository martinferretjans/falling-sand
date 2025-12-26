//
// Created by martin on 8/15/25.
//

#pragma once

#include "grid.hpp"
#include "materials.hpp"

class Simulation {
public:
    Simulation(int width, int height, int cellSize) : grid(width, height, cellSize) {};
    void SetCellValue(int row, int column, MaterialType value);
    void UpdateCell(int row, int column);
    void UpdateSand(int row, int column);
    void UpdateWater(int row, int column);
    void Update();
    bool CanMove(int row1, int column1, int row2, int column2) const;
private:
    Grid grid;
    void Draw();
    //Checks
};