//
// Created by martin on 8/16/25.
//

#pragma once
#import "raylib.h"

class Particle{
public:
    Particle() : color(RandomColor()) {};
private:
    Color color;
    Color RandomColor();
};