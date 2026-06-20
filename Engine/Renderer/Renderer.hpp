#pragma once
#include <SDL2/SDL.h>

class Renderer
{
public:
    bool Init(SDL_Window *window);
    void BeginFrame();
    void DrawFilledRectangle(const SDL_FRect &rectangle, const SDL_Color &color);
    void EndFrame();
    void Shutdown();
    SDL_Renderer *GetSDLRenderer() const { return renderer; }

private:
    SDL_Renderer *renderer = nullptr;
};
