#pragma once
#include <iostream>
#include "Game/PlayerTools/PlayerTool.hpp"

class PlayerPlacementController
{
public:
    void SetTool(PlayerTool *tool)
    {
        currentTool = tool;
    }

    void OnCellClicked(World *world, int row, int col)
    {
        if (currentTool)
        {
            currentTool->OnCellClicked(world, row, col);
        }
    }

    void OnCellHovered(World *world, int row, int col)
    {
        if (currentTool)
        {
            currentTool->OnCellHovered(world, row, col);
        }
    }

private:
    PlayerTool *currentTool = nullptr;
};
