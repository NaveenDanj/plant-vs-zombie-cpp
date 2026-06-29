#pragma once
#include "Engine/ECS/World.hpp"
#include "Engine/Components/Animation.hpp"

class AnimationSystem
{
public:
    void Update(World &world, float deltaTime)
    {
        for (auto &[entity, animation] : world.animations.GetAll())
        {
            if (!world.sprites.Has(entity))
            {
                continue;
            }

            auto &sprite = world.sprites.Get(entity);
            auto &clip = animation.clip;

            if (clip.frames.empty())
            {
                continue;
            }

            animation.timer += deltaTime;

            if (animation.timer >= clip.frameDuration)
            {
                animation.timer -= clip.frameDuration;
                animation.currentFrame++;

                if (animation.currentFrame >= static_cast<int>(clip.frames.size()))
                {
                    if (clip.looping)
                    {
                        animation.currentFrame = 0;
                    }
                    else
                    {
                        animation.currentFrame = static_cast<int>(clip.frames.size()) - 1;
                    }
                }

                sprite.source = clip.frames[animation.currentFrame];
            }
        }
    }
};
