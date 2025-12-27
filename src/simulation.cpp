//
// Created by martin on 8/15/25.
//

#include "simulation.hpp"

void Simulation::UpdateCell(int row, int column) {
    switch(grid.GetMaterial(row, column)) {
        case MaterialType::Sand: UpdateSand(row, column); break;
        case MaterialType::Water: UpdateWater(row, column); break;
        default: break;
    }
}

void Simulation::UpdateSand(int row, int column) {
    //Downwards
    int side = GetRandomValue(0, 1) ? 1 : -1;       //Left or Right

    if(CanMove(row, column, row+1, column)) {
        grid.Swap(row, column, row+1, column);
        return;
    }

    if(CanMove(row, column, row+1, column+side)) {
        grid.Swap(row, column, row+1, column+side);
        return;
    }

    if(CanMove(row, column, row+1, column-side)) {
        grid.Swap(row, column, row+1, column-side);
        return;
    }
}

void Simulation::UpdateWater(int row, int column) {
    if(CanMove(row, column, row+1, column)) {
        grid.Swap(row, column, row+1, column);
        return;
    }

    int side = GetRandomValue(0, 1) ? 1 : -1;

    if(CanMove(row, column, row+1, column+side)) {
        grid.Swap(row, column, row+1, column+side);
    } else if (CanMove(row, column, row+1, column-side)) {
        grid.Swap(row,column,row+1, column-side);
        return;
    }

    int dispersionRate = MATERIALS[static_cast<int>(MaterialType::Water)].dispersionRate;
    for (int i = 1; i <= dispersionRate; i++) {
        if (CanMove(row, column, row, column + (side * i))) {
            grid.Swap(row, column, row, column + (side * i));
            return;
        } else if (CanMove(row, column, row, column - (side * i))) {
            grid.Swap(row, column, row, column - (side * i));
            return;
        }
    }
}

bool Simulation::CanMove(int row1, int column1, int row2, int column2) const {
    if (!grid.IsWithinBounds(row2, column2)) {
        return false;
    }

    MaterialType a = grid.GetMaterial(row1, column1);
    MaterialType b = grid.GetMaterial(row2, column2);

    float aDensity = MATERIALS[static_cast<int>(a)].density;
    float bDensity = MATERIALS[static_cast<int>(b)].density;

    return b == MaterialType::Empty || (aDensity > bDensity && (!MATERIALS[static_cast<int>(b)].isStatic));
}

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::Update() {
    for(int row = grid.GetRows()-2; row >= 0 ; --row) {
        for(int column = grid.GetColumns()-1 ; column >= 0 ; --column) {
            UpdateCell(row, column);
        }
    }
    Draw();
}

void Simulation::SetCellValue(int row, int column, MaterialType value) {
    grid.SetMaterial(row,column,value);
}
