#pragma once
#include <cstdint>

class Time
{
public:
    void Update();
    float GetDeltaTime() const;

private:
    uint64_t lastCounter = 0;
    float deltaTime = 0.0f;
};