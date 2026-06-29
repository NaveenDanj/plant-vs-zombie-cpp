#pragma once
#include "Engine/ECS/World.hpp"

class PlayerTool
{
public:
    virtual ~PlayerTool() = default;
    virtual void OnCellClicked(World *world, int row, int col) = 0;
    virtual void OnCellHovered(World *world, int row, int col) = 0;
};