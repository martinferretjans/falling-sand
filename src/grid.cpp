//
// Created by martin on 8/15/25.
//

#include "grid.hpp"
#include "raylib.h"

void Grid::Draw() {
    for(int row = 0; row < rows; row++) {
        for(int column = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{225,220,145,255} : Color{55,55,55,255};
            DrawRectangle(column * cellSize,row * cellSize,cellSize,cellSize,color);
        }
    }
}

void Grid::SetValue(int row, int column, int value) {
    if(IsWithinBounds(row, column)) {
        cells[row][column] = value;
    }
}

bool Grid::IsEmpty(int row, int column) const {
    if(IsWithinBounds(row, column) && cells[row][column] == 0) {
        return true;
    }
    return false;
}


int Grid::GetValue(int row, int column) const {
    if(IsWithinBounds(row, column)) {
        return cells[row][column];
    } else {
        return -1;
    }
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
            Color color = Color{55,55,55,255};
            DrawRectangle(column * cellSize,row * cellSize,cellSize,cellSize,color);
        }
    }
}

