#pragma once
#include "../ECS/World.hpp"

class MovementSystem
{
public:
    void Update(World &world, float deltaTime)
    {
        for (auto &[entity, transform] : world.transforms.GetAll())
        {
            if (!world.velocities.Has(entity))
            {
                continue;
            }

            auto &velocity = world.velocities.Get(entity);

            transform.x += velocity.vx * deltaTime;
            transform.y += velocity.vy * deltaTime;
        }
    }
};
