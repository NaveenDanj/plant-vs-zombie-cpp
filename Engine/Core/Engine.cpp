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

    return true;
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

        time.Update();
        float dt = time.GetDeltaTime();
        std::cout << "Delta Time: " << dt << " seconds" << std::endl;

        SDL_Delay(16);
        renderer.BeginFrame();
        // Game update and rendering logic would go here
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    renderer.Shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();
}