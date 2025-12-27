//
// Created by martin on 8/15/25.
//

#include "grid.hpp"
#include "raylib.h"
#include "materials.hpp"

void Grid::Draw() const{
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            Color color =  cells[row][column].color;
            DrawRectangle(column * cellSize,row * cellSize,cellSize,cellSize, color);
        }
    }
}

void Grid::Swap(int row1, int column1, int row2, int column2) {
    if(IsWithinBounds(row1, column1) && IsWithinBounds(row2, column2)) {
        std::swap(cells[row1][column1], cells[row2][column2]);
    }
};

void Grid::SetMaterial(int row, int column, MaterialType material) {
    if(IsWithinBounds(row, column)) {
        cells[row][column].material = material;
        cells[row][column].color = RandomizeColor(material);
    }
}

bool Grid::IsEmpty(int row, int column) const {
    return IsWithinBounds(row, column) && cells[row][column].material == MaterialType::Empty;
}


MaterialType Grid::GetMaterial(int row, int column) const {
    if(IsWithinBounds(row, column)) {
        return cells[row][column].material;
    }
    return MaterialType::Empty;
}

Color Grid::RandomizeColor(MaterialType material) const{
    Color baseColor = MATERIALS[static_cast<int>(material)].color;

    if(material == MaterialType::Empty) {
        return baseColor;
    }

    Vector3 hsv = ColorToHSV(baseColor);

    float variation = GetRandomValue(-10, 10) / 50.0f;
    hsv.z += variation;

    if(hsv.z > 1.0f) {hsv.z = 1.0f;}
    if(hsv.z < 0.0f) {hsv.z = 0.0f;}

    return ColorFromHSV(hsv.x, hsv.y, hsv.z);
}

bool Grid::IsWithinBounds(int row, int column) const {
    if(row >= 0 && row < rows && column >= 0 && column < columns) {
        return true;
    }
    return false;
}

void Grid::Clean() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            SetMaterial(row, column, MaterialType::Empty);
        }
    }
}

