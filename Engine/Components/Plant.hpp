#pragma once
#include <iostream>
enum class PlantType
{
    NONE,
    PEASHOOTER,
    SUNFLOWER,
    WALLNUT,
    CHERRYBOMB,
};

struct Plant
{
    PlantType type;
    int cost;
    int cooldown;
    std::string textureName;
};