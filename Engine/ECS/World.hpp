#pragma once
#include "Entity.hpp"
#include "ComponentStorage.hpp"

#include "Engine/Components/Rectangle.hpp"
#include "Engine/Components/Velocity.hpp"
#include "Engine/Components/GridCell.hpp"
#include "Engine/Components/Transform.hpp"
#include "Engine/Components/Plant.hpp"
#include "Engine/Components/Sprite.hpp"

class World
{

public:
    Entity CreateEntity()
    {
        return nextEntity++;
    }

    ComponentStorage<Transform> transforms;
    ComponentStorage<Velocity> velocities;
    ComponentStorage<Rectangle> rectangles;
    ComponentStorage<GridCell> gridCells;
    ComponentStorage<Plant> plants;
    ComponentStorage<Sprite> sprites;

private:
    Entity nextEntity = 1;
};
