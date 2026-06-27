#include "Renderer.hpp"

bool Renderer::Init(SDL_Window *window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer != nullptr)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    }
    return renderer != nullptr;
}

void Renderer::BeginFrame()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Renderer::DrawFilledRectangle(const SDL_FRect &rectangle, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRectF(renderer, &rectangle);
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

void Renderer::DrawLine(int x1, int y1, int x2, int y2, const SDL_Color &color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
