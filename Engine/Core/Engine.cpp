#include "Engine.hpp"
#include <iostream>

bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Plant vs Zombies", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    running = window != nullptr;

    if (!running)
    {
        return false;
    }

    if (!renderer.Init(window))
    {
        return false;
    }

    CreatePlayer();
    return true;
}

void Engine::CreatePlayer()
{
    constexpr float playerWidth = 50.0f;
    constexpr float playerHeight = 50.0f;

    player = world.CreateEntity();
    world.transforms.Add(
        player,
        Transform{
            (WINDOW_WIDTH - playerWidth) / 2.0f,
            (WINDOW_HEIGHT - playerHeight) / 2.0f});
    world.velocities.Add(player, Velocity{});
    world.rectangles.Add(
        player,
        Rectangle{
            playerWidth,
            playerHeight,
            46,
            160,
            67,
            255});
}

void Engine::Run()
{
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        input.Update();
        time.Update();

        if (input.IsKeyPressed(SDL_SCANCODE_ESCAPE))
        {
            running = false;
        }

        playerControllerSystem.Update(world, player, input);
        movementSystem.Update(world, time.GetDeltaTime());

        renderer.BeginFrame();
        renderSystem.Render(world, renderer);
        renderer.EndFrame();

        SDL_Delay(16);
    }
}

void Engine::Shutdown()
{
    renderer.Shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();
}
