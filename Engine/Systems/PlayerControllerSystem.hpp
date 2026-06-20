#pragma once

#include "../ECS/World.hpp"
#include "../Input/Input.hpp"

class PlayerControllerSystem
{
public:
    void Update(World &world, Entity player, const Input &input) const
    {
        if (!world.velocities.Has(player))
        {
            return;
        }

        auto &velocity = world.velocities.Get(player);
        velocity.vx = GetHorizontalDirection(input) * PLAYER_SPEED;
        velocity.vy = GetVerticalDirection(input) * PLAYER_SPEED;
    }

private:
    static float GetHorizontalDirection(const Input &input)
    {
        float direction = 0.0f;

        if (input.IsKeyPressed(SDL_SCANCODE_A) || input.IsKeyPressed(SDL_SCANCODE_LEFT))
        {
            direction -= 1.0f;
        }

        if (input.IsKeyPressed(SDL_SCANCODE_D) || input.IsKeyPressed(SDL_SCANCODE_RIGHT))
        {
            direction += 1.0f;
        }

        return direction;
    }

    static float GetVerticalDirection(const Input &input)
    {
        float direction = 0.0f;

        if (input.IsKeyPressed(SDL_SCANCODE_W) || input.IsKeyPressed(SDL_SCANCODE_UP))
        {
            direction -= 1.0f;
        }

        if (input.IsKeyPressed(SDL_SCANCODE_S) || input.IsKeyPressed(SDL_SCANCODE_DOWN))
        {
            direction += 1.0f;
        }

        return direction;
    }

    static constexpr float PLAYER_SPEED = 250.0f;
};
