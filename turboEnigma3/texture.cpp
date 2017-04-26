#include <SDL.h>
#include "texture.h"


texture::texture(SDL_Texture* ptr, int height, int width) 
    : texturePtr(ptr), height(height), width(width)
{
    renderQuad = { 0, 0, width, height };
}

texture::~texture()
{
    SDL_DestroyTexture(texturePtr);

    texturePtr = NULL;
}

void texture::render(int x, int y, SDL_Renderer* gRenderer)
{
    renderQuad.x = x;
    renderQuad.y = y;
    SDL_RenderCopy(gRenderer, texturePtr, NULL, &renderQuad );
}
