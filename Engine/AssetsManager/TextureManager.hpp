#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <unordered_map>

class TextureManager
{

public:
    void LoadTexture(SDL_Renderer *renderer, const std::string &id, const std::string &filePath);
    SDL_Texture *GetTexture(const std::string &id) const;

private:
    std::unordered_map<std::string, SDL_Texture *> textures;
};
