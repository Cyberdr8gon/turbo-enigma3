#pragma once
#include <vector>
#include <SDL.h>


class texture
{
    public:
        texture(SDL_Texture* ptr, int height, int width);

        ~texture();

        void render(int x, int y, SDL_Renderer* gRenderer);

        SDL_Texture* texturePtr;
        int height;
        int width;
        SDL_Rect renderQuad;
};
