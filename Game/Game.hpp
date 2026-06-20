#pragma once
#include "../Engine/ECS/World.hpp"
#include "../Engine/Input/Input.hpp"
#include "../Engine/Renderer/Renderer.hpp"

class Game
{
public:
    void Init(World &world);
    void Update(World &world, Input &input, float deltaTime);
    void Render(const World &world, Renderer &renderer);
};