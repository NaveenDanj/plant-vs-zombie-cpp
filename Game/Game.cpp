#include "Game.hpp"
#include "Grid.hpp"
#include "../Engine/Systems/RenderSystem.hpp"
#include <iostream>

void Game::Init(World &world)
{
    std::cout << "Game Initialized" << world.velocities.GetAll().size() << std::endl;
}

void Game::Update(World &world, Input &input, float deltaTime)
{
    // update the positions of the entities based on their velocities
    for (const auto &[entity, velocity] : world.velocities.GetAll())
    {
        if (world.transforms.Has(entity))
        {
            Transform &transform = world.transforms.Get(entity);
            transform.x += velocity.vx * deltaTime;
            transform.y += velocity.vy * deltaTime;
        }
    }

    int x, y;
    input.GetMousePosition(x, y);
    const SDL_Point cellPosition = Grid::ScreenToCell(x, y);
    const int row = cellPosition.y;
    const int col = cellPosition.x;

    hoveredCell = std::nullopt;
    if (Grid::IsValidCell(row, col))
    {
        hoveredCell = GridCell{row, col};
    }

    if (input.IsMouseButtonClicked(SDL_BUTTON_LEFT) && hoveredCell.has_value())
    {
        std::cout << "Clicked on cell: (" << hoveredCell->row << ", " << hoveredCell->col << ")" << std::endl;
    }
}

void Game::Render(const World &world, Renderer &renderer)
{
    DrawGrid(renderer);

    RenderSystem renderSystem;
    renderSystem.Render(world, renderer);
}

void Game::DrawGrid(Renderer &renderer) const
{
    const SDL_Color hoverColor{255, 0, 0, 96};
    const SDL_Color lineColor{0, 0, 0, 255};

    if (hoveredCell.has_value())
    {
        renderer.DrawFilledRectangle(Grid::GetCellRect(hoveredCell->row, hoveredCell->col), hoverColor);
    }

    for (int col = 0; col <= Grid::COLS; ++col)
    {
        SDL_Point startPoint = Grid::CellToScreen(0, col);
        SDL_Point endPoint = Grid::CellToScreen(Grid::ROWS, col);
        renderer.DrawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y, lineColor);
    }

    for (int row = 0; row <= Grid::ROWS; ++row)
    {
        SDL_Point startPoint = Grid::CellToScreen(row, 0);
        SDL_Point endPoint = Grid::CellToScreen(row, Grid::COLS);
        renderer.DrawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y, lineColor);
    }
}
