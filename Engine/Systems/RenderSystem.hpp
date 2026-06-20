#pragma once

#include "../ECS/World.hpp"
#include "../Renderer/Renderer.hpp"

class RenderSystem
{
public:
    void Render(const World &world, Renderer &renderer) const
    {
        for (const auto &[entity, transform] : world.transforms.GetAll())
        {
            if (!world.rectangles.Has(entity))
            {
                continue;
            }

            const auto &rectangle = world.rectangles.Get(entity);
            const SDL_FRect destination{
                transform.x,
                transform.y,
                rectangle.width,
                rectangle.height};
            const SDL_Color color{
                rectangle.red,
                rectangle.green,
                rectangle.blue,
                rectangle.alpha};

            renderer.DrawFilledRectangle(destination, color);
        }
    }
};
