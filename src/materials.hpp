//
// Created by martin on 12/25/25.
//

#pragma once
#include "raylib.h"

enum class Material_Type {
    Empty,
    Sand,
    Water,
    Stone,
    Fire,
    Steam,
    Count
};

struct Material_Struct {
    Color color;
    float density;
    bool isStatic;
};

constexpr Material_Struct MATERIALS[static_cast<int>(Material_Type::Count)] = {
    [static_cast<int>(Material_Type::Empty)] = {
        .color = {0, 0, 0, 0},
        .density = 0.0f,
        .isStatic = true
    },

    [static_cast<int>(Material_Type::Sand)] = {
        .color = {200, 200, 200, 200},
        .density = 0.0f,
        .isStatic = false
    },

    [static_cast<int>(Material_Type::Water)] = {
        .color = {0, 0, 0, 0},
        .density = 0.0f,
        .isStatic = false
    },

    [static_cast<int>(Material_Type::Stone)] = {
        .color = {0, 0, 0, 0},
        .density = 0.0f,
        .isStatic = true
    },

    [static_cast<int>(Material_Type::Fire)] = {
        .color = {0, 0, 0, 0},
        .density = 0.0f,
        .isStatic = false
    },

    [static_cast<int>(Material_Type::Steam)] = {
        .color = {0, 0, 0, 0},
        .density = 0.0f,
        .isStatic = false
    }
};