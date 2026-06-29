#include "Game/PlayerTools/PlantTool.hpp"
#include "Game/Grid.hpp"
#include "Engine/Components/Sprite.hpp"
#include "Game/Data/PlantDatabase.hpp"

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

    auto plantDef = PlantDatabase::GetDefinition(PlantPlacementTool::selectedPlantType);
    Plant plant{PlantPlacementTool::selectedPlantType, plantDef.cost, static_cast<int>(plantDef.cooldown), plantDef.textureName};
    Sprite sprite{plantDef.textureName, {0, 0, static_cast<int>(plantDef.frameWidth), static_cast<int>(plantDef.frameHeight)}, static_cast<float>(plantDef.frameWidth), static_cast<float>(plantDef.frameHeight)};
    Animation animation{plantDef.animationClip, 0, 0.0f};

    world->gridCells.Add(plantEntity, gridCell);
    world->transforms.Add(plantEntity, transform);
    world->plants.Add(plantEntity, plant);
    world->sprites.Add(plantEntity, sprite);
    world->animations.Add(plantEntity, animation);
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
