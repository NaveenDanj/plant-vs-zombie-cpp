#pragma once
#include <SDL2/SDL_render.h>
#include <string>
#include <iostream>

struct Sprite
{
    std::string texture;
    SDL_Rect source;
    float width = 0;
    float height = 0;
};