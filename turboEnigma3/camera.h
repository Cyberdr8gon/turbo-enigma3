#pragma once
#include <SDL.h>
#include "gameState.h"
#include "enigma_constants.h"
#include "texture.h"

class camera
{
public:

  camera(gameData& state, std::vector<texture*>& textureArray);
  
  void renderScene(SDL_Renderer* renderer);

  void envRenderPass(SDL_Renderer* renderer);
  void heroRenderPass(SDL_Renderer* renderer);
  void entityRenderPass(SDL_Renderer* renderer);
  void armorRenderPass(SDL_Renderer* renderer);
  void itemRenderPass(SDL_Renderer* renderer);

  gameData& _gameState;
  std::vector<texture*>& _textureArrayRef;

  int xRenderOrigin;
  int yRenderOrigin;
};
