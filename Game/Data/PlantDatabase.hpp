#pragma once
#include "PlantDefinition.hpp"
#include <unordered_map>

class PlantDatabase
{
public:
    static const PlantDefinition &GetDefinition(PlantType plantType);

private:
    static void Init();
    static inline std::unordered_map<PlantType, PlantDefinition> plantDefinitions;
};