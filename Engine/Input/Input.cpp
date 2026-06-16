#include "Input.hpp"
#include <SDL2/SDL.h>

void Input::Update()
{
    keyboardState = SDL_GetKeyboardState(&keyboardLength);
}

bool Input::IsKeyPressed(SDL_Keycode key)
{
    if (keyboardState == nullptr || key < 0 || static_cast<int>(key) >= keyboardLength)
    {
        return false;
    }
    return keyboardState[key] != 0;
}

bool Input::IsKeyReleased(SDL_Keycode key)
{
    if (keyboardState == nullptr || key < 0 || static_cast<int>(key) >= keyboardLength)
    {
        return false;
    }
    return keyboardState[key] == 0;
}