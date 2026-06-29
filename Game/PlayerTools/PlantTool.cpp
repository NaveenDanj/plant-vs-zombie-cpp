#include "Game/PlayerTools/PlantTool.hpp"
#include "Game/Grid.hpp"

void PlantPlacementTool::SelectPlant(PlantType plantType)
{
    PlantPlacementTool::selectedPlantType = plantType;
}

void PlantPlacementTool::OnCellClicked(World *world, int row, int col)
{

    if (PlantPlacementTool::IsCellOccupied(world, row, col))
    {
        std::cout << "Cell (" << row << ", " << col << ") is already occupied. Cannot place plant." << std::endl;
        return;
    }

    SDL_Point point = Grid::CellToScreen(row, col);
    auto plantEntity = world->CreateEntity();

    GridCell gridCell{row, col};
    Transform transform{static_cast<float>(point.x), static_cast<float>(point.y), 0.0f};
    Plant plant{PlantPlacementTool::selectedPlantType, 100, 5, "peashooter"};

    world->gridCells.Add(plantEntity, gridCell);
    world->transforms.Add(plantEntity, transform);
    world->plants.Add(plantEntity, plant);
}

void PlantPlacementTool::OnCellHovered(World *world, int row, int col)
{
    if (PlantPlacementTool::IsCellOccupied(world, row, col))
    {
        std::cout << "Hovering over occupied cell (" << row << ", " << col << ")" << std::endl;
    }
    else
    {
        std::cout << "Hovering over cell (" << row << ", " << col << ")" << std::endl;
    }
}

bool PlantPlacementTool::IsCellOccupied(World *world, int row, int col)
{
    for (const auto &[entity, gridCell] : world->gridCells.GetAll())
    {
        if (gridCell.row == row && gridCell.col == col)
        {
            std::cout << "Cell (" << row << ", " << col << ") is already occupied by a plant." << std::endl;
            return true;
        }
    }
    return false;
}
