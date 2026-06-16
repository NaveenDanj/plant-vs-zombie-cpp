#pragma once
#include <SDL2/SDL.h>

class Input
{
public:
    void Update();
    bool IsKeyPressed(SDL_Keycode key);
    bool IsKeyReleased(SDL_Keycode key);

private:
    const uint8_t *keyboardState = nullptr;
    int keyboardLength = 0;
};