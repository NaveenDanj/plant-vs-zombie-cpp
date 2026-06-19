#pragma once
#include "Entity.hpp"
#include "ComponentStorage.hpp"

#include "Components/Transform.hpp"
#include "Components/Velocity.hpp"

class World
{

public:
    Entity CreateEntity()
    {
        return nextEntity++;
    }

    ComponentStorage<Transform> transforms;
    ComponentStorage<Velocity> velocities;

private:
    Entity nextEntity = 1;
};