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
            if (world.sprites.Has(entity))
            {
                const auto &sprite = world.sprites.Get(entity);
                const SDL_FRect destination{
                    transform.x + (Grid::CELL_WIDTH - sprite.width) / 2,
                    transform.y + (Grid::CELL_HEIGHT - sprite.height) / 2,
                    sprite.width,
                    sprite.height};

                renderer.DrawTexture(sprite.texture, sprite.source, destination);
            }
        }
    }
};
