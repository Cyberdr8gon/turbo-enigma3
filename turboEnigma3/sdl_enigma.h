#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "texture.h"
#include "gameState.h"
#include "camera.h"


// api for sdlPlatform
class sdlPlatformData
{
    public:

    sdlPlatformData(gameData& gameState);
    ~sdlPlatformData();

    bool loadMedia();
    // load surface is not implemented
    SDL_Surface* loadSurface(std::string path);

    SDL_Texture* loadTexture(std::string path,int* width, int* height);
    bool textureLoadingHelper(std::string dir, std::string filename);


    bool handleMessages();

    void render();

    camera sceneCamera;
    

    // rendering data
    std::vector<texture*> textures;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;

    // recent events, maybe optimize this away from vector later?
    // KeyPressSurfaces has a limited number of options, we should remove vector
    // to optimize of space
    std::vector<KeyPressSurfaces> recentEvents;
    
    // write files to load here
    std::vector<std::string> filesToLoad = 
    {
      // index 0
      "test1.bmp",
      //1
      "tiles/unused.bmp",
      //2
      "tiles/floor.bmp",
      //3
      "tiles/wall.bmp",
      //4
      "tiles/closedDoor.bmp",
      //5
      "tiles/openDoor.bmp",
      //6
      "tiles/upStairs.bmp",
      //7
      "tiles/downStairs.bmp"
    };

    bool error;
};
