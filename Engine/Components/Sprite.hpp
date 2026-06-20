#pragma once
#include <SDL2/SDL_render.h>

struct Sprite
{
    SDL_Texture *texture = nullptr;
    int width = 0;
    int height = 0;
};