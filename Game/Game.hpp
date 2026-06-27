#pragma once
#include "../Engine/Components/GridCell.hpp"
#include "../Engine/ECS/World.hpp"
#include "../Engine/Input/Input.hpp"
#include "../Engine/Renderer/Renderer.hpp"
#include <optional>

class Game
{
public:
    void Init(World &world);
    void Update(World &world, Input &input, float deltaTime);
    void Render(const World &world, Renderer &renderer);

private:
    void DrawGrid(Renderer &renderer) const;

    std::optional<GridCell> hoveredCell;
};
