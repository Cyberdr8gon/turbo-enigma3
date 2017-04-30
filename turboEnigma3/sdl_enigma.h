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
      "tiles/unused.png",
      //2
      "tiles/floor.png",
      //3
      "tiles/wall.bmp",
      //4
      "tiles/closedDoor.bmp",
      //5
      "tiles/openDoor.bmp",
      //6
      "tiles/upStairs.png",
      //7
      "tiles/downStairs.png",
      //8 - wall1
      "tiles/walls/11.png",
      //9 - wall2
      "tiles/walls/12.png",
      //10 - wall3
      "tiles/walls/13.png",
      //11 - wall4
      "tiles/walls/14.png",
      //12 - wall5
      "tiles/walls/15.png",
      //13 - wall6
      "tiles/walls/16.png",
      //14 - wall7
      "tiles/walls/17 copy.png",
      //15 - wall8
      "tiles/walls/20.png",
      //16 - wall9
      "tiles/walls/21.png",
      //17 - wall10
      "tiles/walls/22.png",
      //18 - wall11
      "tiles/walls/23.png",
      //19 - wall12
      "tiles/walls/24.png",
      //20 - wall13
      "tiles/walls/25.png",
      //21 - wall14
      "tiles/walls/26.png",
      //22 - wall15
      "tiles/walls/27.png",
      //23 - wall15
      "entities/caveman.png",


    };

    bool error;
};
