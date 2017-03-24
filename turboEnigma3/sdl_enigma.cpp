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

  for (SDL_Texture* el: textures)
  {
    SDL_DestroyTexture(el);
    el = NULL;
  }


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


bool sdlPlatformData::textureLoadingHelper(std::string dir, std::string filename)
{
    SDL_Texture* texturePointer = NULL;
    texturePointer = loadTexture(dir + filename);
    
    if(!texturePointer)
    {
        printf("Could not load: %s%s", dir.c_str(), filename.c_str());
        return false;
    } else
    {
        textures.push_back(texturePointer);
        return true;
    }
    
}

bool sdlPlatformData::loadMedia()
{
    std::string imageDir = "images/";
    bool succeeded = true;
    
    // load all textures in array
    for (std::string s: filesToLoad)
    {
        succeeded = textureLoadingHelper(imageDir, s) && succeeded;
    }

    if(succeeded)
    {
        printf("All assets loaded successfully!");
    }
    return succeeded;
}


void sdlPlatformData::render(gameData& state)
{
    // this is just test code!
    SDL_RenderClear( renderer );
    SDL_RenderCopy(renderer, textures[0], NULL, NULL);
    SDL_RenderPresent(renderer);
    
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
