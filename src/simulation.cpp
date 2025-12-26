//
// Created by martin on 8/15/25.
//

#include "simulation.hpp"

void Simulation::Update() {
    //Should randomize between left and right
    for(int row = grid.GetRows()-2; row >= 0 ; --row) {
        for(int column = grid.GetColumns()-1 ; column >= 0 ; --column) {
            if(!grid.IsEmpty(row,column)) {
                std::vector<std::pair<int, int>> positions = {{row+1, column},  //Down
                                                              {row+1, column+1},   //Down Right
                                                              {row+1, column-1}};  //Down Left
                for(auto [newRow, newColumn] : positions) {
                    if(grid.IsEmpty(newRow,newColumn)) {
                        grid.Swap(row, column, newRow, newColumn);
                        break;
                    }
                }
            }
        }
    }
    Draw();
}

void Simulation::Draw() {
    grid.Draw();
}


void Simulation::SetCellValue(int row, int column, MaterialType value) {
    grid.SetMaterial(row,column,value);
}
