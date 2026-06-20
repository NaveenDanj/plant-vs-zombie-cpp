#include "Game.hpp"
#include "../Engine/Systems/RenderSystem.hpp"
#include <iostream>

void Game::Init(World &world)
{
    std::cout << "Game Initialized" << world.velocities.GetAll().size() << std::endl;
}

void Game::Update(World &world, Input &input, float deltaTime)
{
    for (const auto &[entity, velocity] : world.velocities.GetAll())
    {
        if (world.transforms.Has(entity))
        {
            Transform &transform = world.transforms.Get(entity);
            transform.x += velocity.vx * deltaTime;
            transform.y += velocity.vy * deltaTime;
        }
    }

    if (input.IsMouseButtonClicked(SDL_BUTTON_RIGHT))
    {
        int x, y;
        input.GetMousePosition(x, y);
        std::cout << "Right mouse button clicked at " << x << ", " << y << std::endl;
    }
}

void Game::Render(const World &world, Renderer &renderer)
{
    RenderSystem renderSystem;
    renderSystem.Render(world, renderer);
}