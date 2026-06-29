#pragma once
#include <SDL2/SDL.h>
#include <vector>

struct AnimationClip
{
    std::vector<SDL_Rect> frames;
    float frameDuration = 0.1f;
    bool looping = true;
};

struct Animation
{
    AnimationClip clip;
    int currentFrame = 0;
    float timer = 0.0f;
};
