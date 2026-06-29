#pragma once
#include "Game/PlayerTools/PlayerTool.hpp"
#include <iostream>
#include "Engine/ECS/World.hpp"
#include "Engine/Components/Plant.hpp"

class PlantPlacementTool : public PlayerTool
{
public:
    void SelectPlant(PlantType plantType);
    void OnCellClicked(World *world, int row, int col) override;
    void OnCellHovered(World *world, int row, int col) override;

private:
    PlantType selectedPlantType = PlantType::NONE;
    bool IsCellOccupied(World *world, int row, int col);
};