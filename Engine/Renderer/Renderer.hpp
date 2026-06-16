#pragma once
#include <SDL2/SDL.h>

class Renderer
{
public:
    bool Init(SDL_Window *window);
    void BeginFrame();
    void EndFrame();
    void Shutdown();

private:
    SDL_Renderer *renderer = nullptr;
};