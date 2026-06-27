#pragma once

#include <SDL2/SDL.h>

class Grid
{
public:
    static constexpr int ROWS = 5;
    static constexpr int COLS = 9;

    static constexpr int CELL_WIDTH = 100;
    static constexpr int CELL_HEIGHT = 100;

    static constexpr int START_X = 50;
    static constexpr int START_Y = 50;

    static SDL_FRect GetCellRect(int row, int col)
    {
        SDL_FRect rect;
        rect.x = START_X + col * CELL_WIDTH;
        rect.y = START_Y + row * CELL_HEIGHT;
        rect.w = CELL_WIDTH;
        rect.h = CELL_HEIGHT;
        return rect;
    }

    static SDL_Point CellToScreen(int row, int col)
    {
        return {
            START_X + col * CELL_WIDTH,
            START_Y + row * CELL_HEIGHT};
    }

    static SDL_Point ScreenToCell(int screen_x, int screen_y)
    {
        if (!ContainsScreenPoint(screen_x, screen_y))
        {
            return {-1, -1};
        }

        int row = (screen_y - START_Y) / CELL_HEIGHT;
        int col = (screen_x - START_X) / CELL_WIDTH;
        return {col, row};
    }

    static bool IsValidCell(int row, int col)
    {
        return row >= 0 && row < ROWS && col >= 0 && col < COLS;
    }

    static bool ContainsScreenPoint(int screen_x, int screen_y)
    {
        return screen_x >= START_X &&
               screen_x < START_X + COLS * CELL_WIDTH &&
               screen_y >= START_Y &&
               screen_y < START_Y + ROWS * CELL_HEIGHT;
    }
};
