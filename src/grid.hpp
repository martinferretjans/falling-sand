//
// Created by martin on 8/15/25.
//

#pragma once

#include <vector>
#include "materials.hpp"
#include "raylib.h"

//Thinking of making the grid a single contiguous array.

class Grid {
public:
    Grid(int width, int height, int cellSize) : rows(height/cellSize), columns(width/cellSize), cellSize(cellSize),
                                                cells(rows, std::vector<Cell>(columns, {MaterialType::Empty, MATERIALS[static_cast<int>(MaterialType::Empty)].color})) {};
    void Draw();
    void SetMaterial(int row, int column, MaterialType material);
    MaterialType GetMaterial(int row, int column) const;
    void Clean();
    void Swap(int row1, int column1, int row2, int column2);
    bool IsEmpty(int row, int column) const;
    bool IsWithinBounds(int row, int column) const;
    int GetRows() const {return rows;};
    int GetColumns() const {return columns;};

private:
    int rows;
    int columns;
    int cellSize;

    struct Cell {
        MaterialType material;
        Color color;
    };

    std::vector<std::vector<Cell>> cells;
};
