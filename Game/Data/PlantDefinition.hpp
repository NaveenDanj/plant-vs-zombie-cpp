#pragma once
#include <string>
#include "Engine/Components/Animation.hpp"
#include "Engine/Components/Plant.hpp"

struct PlantDefinition
{
    PlantType type;
    int health;
    int cost;
    float cooldown;

    std::string textureName;
    float frameWidth;
    float frameHeight;

    AnimationClip animationClip;
};