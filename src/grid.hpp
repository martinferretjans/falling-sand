//
// Created by martin on 8/15/25.
//

#pragma once

#include <vector>
#include "materials.hpp"
#include "raylib.h"

class Grid {
public:
    Grid(int width, int height, int cellSize) : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), cells(rows, std::vector<Material_Type>(columns, Material_Type::Empty)) {};
    void Draw();
    void SetMaterial(int row, int column, Material_Type material);
    Material_Type GetMaterial(int row, int column) const;
    void Clean();
    void Swap(int row1, int column1, int row2, int column2);
    bool IsEmpty(int row, int column) const;
    bool IsWithinBounds(int row, int column) const;
    int GetRows() const {return rows;};
    int GetColumns() const {return columns;};

private:
    int rows;       // Y
    int columns;    // X
    int cellSize;
    std::vector<std::vector<Material_Type>> cells;
};
