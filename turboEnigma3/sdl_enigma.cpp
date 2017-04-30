#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "sdl_enigma.h"




sdlPlatformData::sdlPlatformData(gameData& gameState) : sceneCamera(gameState, textures)
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
    for (texture* el: textures)
    {
        delete el;
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
          switch (e.key.keysym.sym)
          {
          case SDLK_UP:
            recentEvents.push_back(KEY_PRESS_SURFACE_UP);
            break;
          case SDLK_DOWN:
            recentEvents.push_back(KEY_PRESS_SURFACE_DOWN);
            break;
          case SDLK_RIGHT:
            recentEvents.push_back(KEY_PRESS_SURFACE_RIGHT);
            break;
          case SDLK_LEFT:
            recentEvents.push_back(KEY_PRESS_SURFACE_LEFT);
            break;
          default:
            break;
          }
        }
    }

    return true;
}


bool sdlPlatformData::textureLoadingHelper(std::string dir, std::string filename)
{
    SDL_Texture* texturePointer = NULL;
    int width = 0;
    int height= 0;

    texturePointer = loadTexture(dir + filename, &width, &height);

    if(!texturePointer)
    {
        printf("Could not load: %s%s", dir.c_str(), filename.c_str());
        return false;
    } else
    {
        textures.push_back(new texture(texturePointer,width,height));
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
        printf("All assets loaded successfully!\n");
    }
    return succeeded;
}




void sdlPlatformData::render()
{
    // this is just test code!
    // clean off screen
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	  SDL_RenderClear( renderer );



    //printf("SDL Render Error: %s\n", SDL_GetError());
    // each texture render copy looks like this
    // 3rd arg is important, it is the rect for the location of the sprite

    // parse game state and render stuff here

    sceneCamera.renderScene(renderer);

    // TODO remove this test XD
    // textures[0]->render(50, 50, renderer);

    // everything to render is above this line
    // actually renderering the scene is here
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

SDL_Texture* sdlPlatformData::loadTexture(std::string path, int* width, int* height)
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
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0, 0xFF ) );
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            return NULL;
        }
        else 
        {
            *width = loadedSurface->w;
            *height = loadedSurface->h;
        }


        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
