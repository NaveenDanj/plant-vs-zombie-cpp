#include "Engine.hpp"
#include "../../Game/Grid.hpp"
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

    game.Init(world);

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

        input.Update();
        time.Update();

        if (input.IsKeyPressed(SDL_SCANCODE_ESCAPE))
        {
            running = false;
        }

        game.Update(world, input, time.GetDeltaTime());
        movementSystem.Update(world, time.GetDeltaTime());

        renderer.BeginFrame();
        renderSystem.Render(world, renderer);
        SDL_Renderer *sdlRenderer = renderer.GetSDLRenderer();

        SDL_SetRenderDrawColor(
            sdlRenderer,
            100,
            100,
            100,
            255);

        for (int i = 0; i < Grid::COLS + 1; ++i)
        {
            int x = Grid::START_X + i * Grid::CELL_WIDTH;
            SDL_RenderDrawLine(sdlRenderer, x, Grid::START_Y, x, Grid::START_Y + Grid::ROWS * Grid::CELL_HEIGHT);
        }

        for (int j = 0; j < Grid::ROWS + 1; ++j)
        {
            int y = Grid::START_Y + j * Grid::CELL_HEIGHT;
            SDL_RenderDrawLine(sdlRenderer, Grid::START_X, y, Grid::START_X + Grid::COLS * Grid::CELL_WIDTH, y);
        }

        game.Render(world, renderer);
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
