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
};

constexpr MaterialStruct MATERIALS[static_cast<int>(MaterialType::Count)] = {
    [static_cast<int>(MaterialType::Empty)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = true
    },

    [static_cast<int>(MaterialType::Sand)] = {
        .color = {200, 200, 200, 255},
        .density = 2.0f,
        .isStatic = false
    },

    [static_cast<int>(MaterialType::Water)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = false
    },

    [static_cast<int>(MaterialType::Stone)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = true
    },

    [static_cast<int>(MaterialType::Fire)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = false
    },

    [static_cast<int>(MaterialType::Steam)] = {
        .color = {0, 0, 0, 255},
        .density = 0.0f,
        .isStatic = false
    }
};