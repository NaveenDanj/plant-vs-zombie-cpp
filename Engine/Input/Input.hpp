#pragma once
#include <SDL2/SDL.h>

class Input
{
public:
    void Update();
    bool IsKeyPressed(SDL_Scancode key);
    bool IsKeyReleased(SDL_Scancode key);
    bool IsMouseButtonPressed(uint8_t button);
    bool IsMouseButtonClicked(uint8_t button); // Optional: Implement if you want to detect clicks (press + release)
    bool IsMouseButtonReleased(uint8_t button);

private:
    const uint8_t *keyboardState = nullptr;
    int keyboardLength = 0;
    // add state to track the mouse button click event
    bool mouseButtonClicked = false;
};