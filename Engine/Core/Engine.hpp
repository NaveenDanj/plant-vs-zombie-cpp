#pragma once
#include <SDL2/SDL.h>
#include "../ECS/World.hpp"
#include "../Input/Input.hpp"
#include "../Renderer/Renderer.hpp"
#include "../Systems/MovementSystem.hpp"
#include "Time.hpp"
#include "../../Game/Game.hpp"

class Engine
{
public:
    bool Init();
    void Run();
    void Shutdown();

private:
    static constexpr uint16_t WINDOW_WIDTH = 1000;
    static constexpr uint16_t WINDOW_HEIGHT = 600;

    SDL_Window *window = nullptr;
    bool running = false;

    Renderer renderer;
    Time time;
    Input input;
    World world;

    MovementSystem movementSystem;
    Game game;
};
