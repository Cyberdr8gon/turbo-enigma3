#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "sdl_enigma.h"




sdlPlatformData::sdlPlatformData() 
{
  error = false;

  // init SDL

  if(SDL_Init(SDL_INIT_VIDEO) < 0 ) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    error = true;
  } else {
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf("Warning: Linear texture filtering not enabled!");
    }
    
    window = SDL_CreateWindow( "Turbo Enigma 3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      error = true;
    }
    else {
      renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
      if(renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        error = true;
      }
      else {
        int imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags) & imgFlags)) {
          printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
          error = true;
        }
      }
    }

  }

  if(error)
  {
    error = true;
    printf("SDL could not initialize post Window Creation SDL_Error: %s\n", SDL_GetError());
  } else {
    if(!loadMedia()) {
      error = true;
      printf("Failed to load media SDL_Error: %s\n", SDL_GetError());
    }
  }
}

sdlPlatformData::~sdlPlatformData()
{
  // SDL_DestroyTexture every allocated texture
  // also set pointer to null
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  
  SDL_DestroyWindow(window);
  window = NULL;

  IMG_Quit();
  SDL_Quit();
}



// handles OS messages and input
bool sdlPlatformData::handleMessages()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            return false;
        } else if (e.type == SDL_KEYDOWN)
        {
            // handle key inputs
        }
    }

    return true;
}


bool sdlPlatformData::loadMedia()
{
    // TODO
    return true;
}


void sdlPlatformData::render(gameData& state)
{

}

SDL_Surface* sdlPlatformData::loadSurface(std::string path)
{
    /*
    TODO Check if we need to load surfaces
    if we do, then add surface array


    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
    */
    return NULL;
}

SDL_Texture* sdlPlatformData::loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
