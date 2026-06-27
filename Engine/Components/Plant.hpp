#pragma once

enum class PlantType
{
    PEASHOOTER,
    SUNFLOWER,
    WALLNUT,
    CHERRYBOMB,
};

struct Plant
{
    PlantType type;
};