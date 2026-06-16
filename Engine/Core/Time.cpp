#include "Time.hpp"
#include <SDL2/SDL.h>

void Time::Update()
{
    uint64_t currentCounter = SDL_GetPerformanceCounter();
    if (lastCounter != 0)
    {
        deltaTime = static_cast<float>(currentCounter - lastCounter) / SDL_GetPerformanceFrequency();
    }
    lastCounter = currentCounter;
}

float Time::GetDeltaTime() const
{
    return deltaTime;
}