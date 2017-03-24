
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
