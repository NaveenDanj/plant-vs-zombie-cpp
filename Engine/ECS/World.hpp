#pragma once
#include "Entity.hpp"
#include "ComponentStorage.hpp"

#include "../Components/Rectangle.hpp"
#include "../Components/Transform.hpp"
#include "../Components/Velocity.hpp"
#include "../Components/GridCell.hpp"

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

private:
    Entity nextEntity = 1;
};
