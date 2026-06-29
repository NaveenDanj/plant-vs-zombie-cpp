#include "TextureManager.hpp"
#include <SDL2/SDL_image.h>

#ifndef GAME_ASSET_DIR
#define GAME_ASSET_DIR "assets/"
#endif

void TextureManager::LoadTexture(SDL_Renderer *renderer, const std::string &id, const std::string &path)
{

    const std::string assetPath = std::string(GAME_ASSET_DIR);

    if (textures.find(id) != textures.end())
    {
        std::cerr << "Texture with ID " << id << " already exists. Skipping load." << std::endl;
        return;
    }

    SDL_Surface *surface = IMG_Load((assetPath + path).c_str());
    if (!surface)
    {
        std::cerr << "Failed to load surface from " << path << ": " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
        return;
    }

    textures[id] = texture;
}

SDL_Texture *TextureManager::GetTexture(const std::string &id) const
{
    auto it = textures.find(id);
    if (it != textures.end())
    {
        return it->second;
    }
    else
    {
        std::cerr << "Texture with ID " << id << " not found." << std::endl;
        return nullptr;
    }
}
