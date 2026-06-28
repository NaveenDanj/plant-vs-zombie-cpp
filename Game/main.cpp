#include <iostream>
#include "Engine/Core/Engine.hpp"

int main()
{
    std::cout << "Game Started" << std::endl;

    Engine engine;
    if (!engine.Init())
    {
        return 1;
    }

    engine.Run();
    engine.Shutdown();
    return 0;
}