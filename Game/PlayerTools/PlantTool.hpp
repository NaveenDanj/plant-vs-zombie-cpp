#pragma once
#include "Game/PlayerTools/PlayerTool.hpp"
#include <iostream>
#include "Engine/ECS/World.hpp"

class PlantPlacementTool : public PlayerTool
{
public:
    void OnCellClicked(World *world, int row, int col) override
    {
        std::cout << "Plant placed at cell (" << row << ", " << col << ")" << std::endl;
    }

    void OnCellHovered(World *world, int row, int col) override
    {
        std::cout << "Cell hovered at (" << row << ", " << col << ")" << std::endl;
    }
};