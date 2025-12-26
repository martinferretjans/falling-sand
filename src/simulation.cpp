//
// Created by martin on 8/15/25.
//

#include "simulation.hpp"

void Simulation::UpdateCell(int row, int column) {
    switch(grid.GetMaterial(row, column)) {
        case MaterialType::Sand: UpdateSand(row, column); break;
        default: break;
    }
}

void Simulation::UpdateSand(int row, int column) {
    //Downwards
    if(CanMove(row, column, row+1, column)) {
        grid.Swap(row, column, row+1, column);
    } else {
        //down left, down right
        int column1, column2;
        if(GetRandomValue(0,1)) { //Will maybe replace with c++ random value
            column1 = column+1; //Right first
            column2 = column-1;
        } else {
            column1 = column-1; //Left first
            column2 = column+1;
        }
        if(CanMove(row, column, row+1, column1)) {
            grid.Swap(row, column, row+1, column1);
        } else if(CanMove(row, column, row+1, column2)) {
            grid.Swap(row, column, row+1, column2);
        }
    }
}

bool Simulation::CanMove(int row1, int column1, int row2, int column2) const {
    MaterialType a = grid.GetMaterial(row1, column1);
    MaterialType b = grid.GetMaterial(row2, column2);
    return MATERIALS[static_cast<int>(a)].density > MATERIALS[static_cast<int>(b)].density;
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
