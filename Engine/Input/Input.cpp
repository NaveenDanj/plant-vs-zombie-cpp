#include "Input.hpp"
#include <SDL2/SDL.h>

void Input::Update()
{
    keyboardState = SDL_GetKeyboardState(&keyboardLength);
}

bool Input::IsKeyPressed(SDL_Scancode key)
{
    if (keyboardState == nullptr ||
        key == SDL_SCANCODE_UNKNOWN ||
        static_cast<int>(key) >= keyboardLength)
    {
        return false;
    }

    return keyboardState[key] != 0;
}

bool Input::IsKeyReleased(SDL_Scancode key)
{
    if (keyboardState == nullptr ||
        key == SDL_SCANCODE_UNKNOWN ||
        static_cast<int>(key) >= keyboardLength)
    {
        return false;
    }

    return keyboardState[key] == 0;
}

bool Input::IsMouseButtonPressed(uint8_t button)
{
    uint32_t mouseState = SDL_GetMouseState(nullptr, nullptr);
    return (mouseState & SDL_BUTTON(button)) != 0;
}

bool Input::IsMouseButtonClicked(uint8_t button)
{
    bool currentlyPressed = IsMouseButtonPressed(button);
    if (currentlyPressed && !mouseButtonClicked)
    {
        mouseButtonClicked = true;
        return true;
    }
    else if (!currentlyPressed)
    {
        mouseButtonClicked = false;
    }
    return false;
}

bool Input::IsMouseButtonReleased(uint8_t button)
{
    uint32_t mouseState = SDL_GetMouseState(nullptr, nullptr);
    return (mouseState & SDL_BUTTON(button)) == 0;
}