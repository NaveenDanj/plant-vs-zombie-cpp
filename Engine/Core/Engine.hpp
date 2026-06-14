#pragma once
#include <SDL2/SDL.h>

class Engine
{
public:
    bool Init();
    void Run();
    void Shutdown();

private:
    SDL_Window *window = nullptr;
    bool running = false;
};