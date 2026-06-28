#pragma once
#include "Engine/Components/GridCell.hpp"
#include <optional>
#include "Engine/ECS/Entity.hpp"

struct CursorState
{
    std::optional<GridCell> hoveredCell;
    Entity hoveredPlant;
    Entity hoveredZombie;

    void Reset()
    {
        hoveredCell = std::nullopt;
        hoveredPlant = 0;
        hoveredZombie = 0;
    }
};