//
// Created by martin on 8/15/25.
//

#include "simulation.hpp"

void Simulation::Update() {
    //Really barebones, will do a std::pair vector and the function will receive a pair.
    //Will check positions on a loop
    for(int row = grid.GetRows()-2; row >= 0 ; --row) {
        for(int column = grid.GetColumns()-1 ; column >= 0 ; --column) {
            if(!grid.IsEmpty(row,column)) {
                if(grid.IsEmpty(row+1, column)) {
                    grid.SetValue(row+1,column, 1);
                    grid.SetValue(row,column,0);
                } else if(grid.IsWithinBounds(row+1, column+1) && grid.IsEmpty(row+1, column+1)) {
                    grid.SetValue(row+1,column+1, 1);
                    grid.SetValue(row,column,0);
                } else if(grid.IsWithinBounds(row+1, column-1) && grid.IsEmpty(row+1, column-1)) {
                    grid.SetValue(row+1,column-1, 1);
                    grid.SetValue(row,column,0);
                }
            }
        }
    }
    Draw();
}

/*if(!grid.IsEmpty(row,column)) {
                std::vector<std::pair<int, int>> positions = {{row+1, column},  //Down
                                                              {row+1, column+1},   //Down Right
                                                              {row+1, column-1}};  //Down Left
                for(auto [newRow, newColumn] : positions) {
                    if(grid.IsEmpty(newRow,newColumn)) {
                        grid.SetValue(newRow, newColumn, 1);
                        grid.SetValue(row,column,0);
                    }
                }
            }*/

void Simulation::Draw() {
    grid.Draw();
}


void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row,column,value);
}
