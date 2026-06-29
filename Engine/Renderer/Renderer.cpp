#include "Renderer.hpp"
#include <string>

#ifndef GAME_ASSET_DIR
#define GAME_ASSET_DIR "assets/"
#endif

bool Renderer::Init(SDL_Window *window)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer != nullptr)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    }

    textureManager = TextureManager();
    const std::string assetPath = std::string(GAME_ASSET_DIR);
    textureManager.LoadTexture(renderer, "peashooter", assetPath + "test.png");

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

void Renderer::DrawTexture(const std::string &textureId, const SDL_FRect &destination)
{
    SDL_Texture *texture = textureManager.GetTexture(textureId);
    if (texture != nullptr)
    {
        SDL_RenderCopyF(renderer, texture, nullptr, &destination);
    }
    else
    {
        std::cerr << "Failed to draw texture with ID " << textureId << ": Texture not found." << std::endl;
    }
}
