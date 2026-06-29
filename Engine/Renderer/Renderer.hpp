#pragma once
#include <SDL2/SDL.h>
#include "Engine/AssetsManager/TextureManager.hpp"

class Renderer
{
public:
    bool Init(SDL_Window *window);
    void BeginFrame();
    void DrawFilledRectangle(const SDL_FRect &rectangle, const SDL_Color &color);
    void DrawLine(int x1, int y1, int x2, int y2, const SDL_Color &color);
    void DrawTexture(const std::string &textureId, const SDL_Rect &source, const SDL_FRect &destination);
    void EndFrame();
    void Shutdown();

private:
    SDL_Renderer *renderer = nullptr;
    TextureManager textureManager;
};
