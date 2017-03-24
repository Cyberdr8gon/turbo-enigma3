#pragma once
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

class gameData;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



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


    bool handleMessages();
    void render(gameData& state);
    

    std::vector<SDL_Texture*> textures;
    SDL_Renderer* renderer = NULL;
    SDL_Window* window = NULL;

    std::vector<KeyPressSurfaces> recentEvents;
    

    bool error;
};
