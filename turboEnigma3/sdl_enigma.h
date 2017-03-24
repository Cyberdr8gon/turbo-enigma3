#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

class gameData;
const int TILE_SQUARE_SIDE_LENGTH = 16;
const int SCREEN_WIDTH = TILE_SQUARE_SIDE_LENGTH * 32;
const int SCREEN_HEIGHT = TILE_SQUARE_SIDE_LENGTH * 20;



enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};


// api for sdlPlatform
class sdlPlatformData
{
    public:

    sdlPlatformData();
    ~sdlPlatformData();

    bool loadMedia();
    bool closeMedia();
    SDL_Surface* loadSurface(std::string path);
    SDL_Texture* loadTexture(std::string path);
    bool textureLoadingHelper(std::string dir, std::string filename);


    bool handleMessages();
    void render(gameData& state);
    

    std::vector<SDL_Texture*> textures;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;

    std::vector<KeyPressSurfaces> recentEvents;
    
    // write files to load here
    std::vector<std::string> filesToLoad = 
    {
        "test1.bmp"
    };

    bool error;
};
