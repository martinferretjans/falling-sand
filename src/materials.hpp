//
// Created by martin on 12/25/25.
//

#pragma once
#include "raylib.h"

enum class MaterialType {
    Empty,
    Sand,
    Water,
    Stone,
    Fire,
    Steam,
    Count
};

struct MaterialStruct {
    Color color;
    float density;
    bool isStatic;
    int dispersionRate;
};

constexpr MaterialStruct MATERIALS[static_cast<int>(MaterialType::Count)] = {
    [static_cast<int>(MaterialType::Empty)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = false,
        .dispersionRate = 1
    },

    [static_cast<int>(MaterialType::Sand)] = {
        .color = {255, 225, 130, 255}, //HSL = 60,100,75.5
        .density = 2.0f,
        .isStatic = false,
        .dispersionRate = 1
    },

    [static_cast<int>(MaterialType::Water)] = {
        .color = {50, 100, 255, 255},
        .density = 1.0f,
        .isStatic = false,
        .dispersionRate = 5
    },

    [static_cast<int>(MaterialType::Stone)] = {
        .color = {150, 150, 150, 255},
        .density = 10.0f,
        .isStatic = true,
        .dispersionRate = 1
    },

    [static_cast<int>(MaterialType::Fire)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = false,
        .dispersionRate = 1
    },

    [static_cast<int>(MaterialType::Steam)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = false,
        .dispersionRate = 1
    }
};