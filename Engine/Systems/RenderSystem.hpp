#pragma once

#include "Engine/ECS/World.hpp"
#include "Engine/Renderer/Renderer.hpp"
#include "Game/Grid.hpp"

class RenderSystem
{
public:
    void Render(const World &world, Renderer &renderer) const
    {
        for (const auto &[entity, transform] : world.transforms.GetAll())
        {
            // if (world.rectangles.Has(entity))
            // {
            //     const auto &rectangle = world.rectangles.Get(entity);
            //     const SDL_FRect destination{
            //         transform.x,
            //         transform.y,
            //         rectangle.width,
            //         rectangle.height};
            //     const SDL_Color color{
            //         rectangle.red,
            //         rectangle.green,
            //         rectangle.blue,
            //         rectangle.alpha};

            //     renderer.DrawFilledRectangle(destination, color);
            // }

            if (world.plants.Has(entity))
            {
                const SDL_FRect destination{
                    transform.x + (Grid::CELL_WIDTH - 50.0f) / 2,
                    transform.y + (Grid::CELL_HEIGHT - 50.0f) / 2,
                    50.0f,
                    50.0f};

                renderer.DrawTexture("peashooter", destination);
            }
        }
    }
};
