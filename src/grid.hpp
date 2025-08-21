//
// Created by martin on 8/15/25.
//

#pragma once

#include <vector>
#include "raylib.h"

class Grid {
public:
    Grid(int width, int height, int cellSize) : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {};
    void Draw();
    void SetValue(int row, int column, int value);
    int GetValue(int row, int column) const;
    void Clean();
    //void Swap(int row, int column, int row2, int column2);
    bool IsEmpty(int row, int column) const;
    bool IsWithinBounds(int row, int column) const;
    int GetRows() const {return rows;};
    int GetColumns() const {return columns;};

private:
    int rows;       // Y
    int columns;    // X
    int cellSize;
    std::vector<std::vector<int>> cells; //In the future this will be a particle vector, planning on adding more materials.
};
