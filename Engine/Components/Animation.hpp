#pragma once
#include <SDL2/SDL.h>
#include <vector>

struct Animation
{
    const AnimationClip *clip;
    int currentFrame = 0;
    float timer;
};

struct AnimationClip
{
    std::vector<SDL_Rect> frames;
    float frameDuration = 0.1f;
    bool looping = true;
};