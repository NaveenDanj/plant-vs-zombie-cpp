#pragma once
#include <SDL2/SDL.h>
#include "../Renderer/Renderer.hpp"

class Engine
{
public:
    bool Init();
    void Run();
    void Shutdown();
    const uint16_t WINDOW_WIDTH = 800;
    const uint16_t WINDOW_HEIGHT = 600;

private:
    SDL_Window *window = nullptr;
    Renderer renderer;
    bool running = false;
};