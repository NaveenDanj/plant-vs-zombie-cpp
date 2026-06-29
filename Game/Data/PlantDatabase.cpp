#include "PlantDefinition.hpp"
#include "PlantDatabase.hpp"

void PlantDatabase::Init()
{

    plantDefinitions[PlantType::PEASHOOTER] = PlantDefinition{
        PlantType::PEASHOOTER,
        100,
        5,
        1.0f,
        "peashooter-idle",
        32.0f,
        32.0f,
        AnimationClip{
            {
                {0, 0, 32, 32},
                {31, 0, 32, 32},
                {63, 0, 32, 32},
                {95, 0, 32, 32},
                {128, 0, 32, 32},
                {157, 0, 32, 32},
                {187, 0, 32, 32},
                {217, 0, 32, 32},
            },
            0.1f,
            true}};

    plantDefinitions[PlantType::SUNFLOWER] = PlantDefinition{
        PlantType::SUNFLOWER,
        100,
        5,
        1.0f,
        "sunflower-idle",
        34.0f,
        34.0f,
        AnimationClip{
            {
                {2, 0, 34, 34},
                {34, 0, 34, 34},
                {68, 0, 34, 34},
                {102, 0, 34, 34},
                {136, 0, 34, 34},
                {170, 0, 34, 34},
                {204, 0, 34, 34},
                {238, 0, 34, 34},
            },
            0.1f,
            true}};
}

const PlantDefinition &PlantDatabase::GetDefinition(PlantType plantType)
{
    if (PlantDatabase::plantDefinitions.empty())
    {
        PlantDatabase::Init();
    }

    auto it = PlantDatabase::plantDefinitions.find(plantType);

    if (it != PlantDatabase::plantDefinitions.end())
    {
        return it->second;
    }

    std::cout << "Plant definition not found" << std::endl;
    static PlantDefinition defaultDefinition;
    return defaultDefinition;
}