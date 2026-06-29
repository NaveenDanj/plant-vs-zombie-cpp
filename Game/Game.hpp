#pragma once
#include "Engine/Components/GridCell.hpp"
#include "Engine/ECS/World.hpp"
#include "Engine/Input/Input.hpp"
#include "Engine/Renderer/Renderer.hpp"
#include <optional>
#include "Game/Systems/PlacementController.hpp"
#include "Game/Systems/CursorState.hpp"

class Game
{
public:
    void Init(World &world);
    void Update(World &world, Input &input, float deltaTime);
    void Render(const World &world, Renderer &renderer);

private:
    void DrawGrid(Renderer &renderer) const;
    PlayerPlacementController playerPlacementController;
    CursorState cursorState;
    std::optional<GridCell> hoveredCell;
    PlayerTool *currentTool = nullptr;
};
