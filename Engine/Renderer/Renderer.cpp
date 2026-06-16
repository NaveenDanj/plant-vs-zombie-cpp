#include "Renderer.hpp"

bool Renderer::Init(SDL_Window *window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return renderer != nullptr;
}

void Renderer::BeginFrame()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
}

void Renderer::EndFrame()
{
    SDL_RenderPresent(renderer);
}

void Renderer::Shutdown()
{
    if (renderer != nullptr)
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}