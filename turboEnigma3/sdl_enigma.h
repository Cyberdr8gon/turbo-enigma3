#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"
#include "gameState.h"



// api for sdlPlatform
class sdlPlatformData
{
    public:

    sdlPlatformData();
    ~sdlPlatformData();

    bool loadMedia();
    // load surface is not implemented
    SDL_Surface* loadSurface(std::string path);

    SDL_Texture* loadTexture(std::string path,int* width, int* height);
    bool textureLoadingHelper(std::string dir, std::string filename);


    bool handleMessages();

    void render(gameData& state);
    

    // rendering data
    std::vector<texture*> textures;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;

    // recent events, maybe optimize this away from vector later?
    // KeyPressSurfaces has a limited number of options, we should remove vector
    std::vector<KeyPressSurfaces> recentEvents;
    
    // write files to load here
    std::vector<std::string> filesToLoad = 
    {
        "test1.bmp"
    };

    bool error;
};
