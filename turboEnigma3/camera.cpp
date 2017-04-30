
#include "camera.h"
#include <functional>
#include "collision.h"


camera::camera(gameData& state, std::vector<texture*>& textureArray) : _gameState(state), _textureArrayRef(textureArray)
{
  
}

// there is CAMERA_RENDER_TILE_WIDTH / 2 - 1 to the left of hero
// CAMERA_RENDER_TILE_WIDTH / 2 to the right of hero
// CAMERA_RENDER_TILE_HEIGHT / 2 - 1 on top
// CAMERA_RENDER_TILE_HEIGHT / 2 on bottom
void camera::renderScene(SDL_Renderer* renderer)
{
  int xHeroCord = _gameState.heroEntity->xCord();
  int yHeroCord = _gameState.heroEntity->yCord();

  xRenderOrigin = xHeroCord - (CAMERA_RENDER_TILE_WIDTH / 2 - 1);
  yRenderOrigin = yHeroCord - (CAMERA_RENDER_TILE_HEIGHT / 2 - 1);

  envRenderPass(renderer);

  heroRenderPass(renderer);

  entityRenderPass(renderer);

  armorRenderPass(renderer);

  itemRenderPass(renderer);


}


void camera::envRenderPass(SDL_Renderer* renderer)
{

  int x_offset = 0;
  int y_offset = CAMERA_RENDER_TILE_HEIGHT * TILE_SQUARE_SIDE_LENGTH - TILE_SQUARE_SIDE_LENGTH;

  for(int x = xRenderOrigin; x < xRenderOrigin + CAMERA_RENDER_TILE_WIDTH; x++)
  {
    y_offset = CAMERA_RENDER_TILE_HEIGHT * TILE_SQUARE_SIDE_LENGTH - TILE_SQUARE_SIDE_LENGTH;
    for(int y = yRenderOrigin + CAMERA_RENDER_TILE_HEIGHT; y >= yRenderOrigin; y--)
    {
      switch(_gameState.map_system->loadedLevels[2]->getTile(x -1 ,y - 2))
      {
      case Floor:
      case Corridor:
        _textureArrayRef[2]->render(x_offset, y_offset, renderer);
        break;
      case Wall:
        Tile up, down, left, right;
        up    = _gameState.map_system->loadedLevels[2]->getTile(x - 1, y - 2 - 1);
        down  = _gameState.map_system->loadedLevels[2]->getTile(x - 1, y - 2 + 1);
        left  = _gameState.map_system->loadedLevels[2]->getTile(x - 1 + 1, y - 2);
        right = _gameState.map_system->loadedLevels[2]->getTile(x - 1 - 1, y - 2);
        _textureArrayRef[selectWallTile(up,down,left,right)]->render(x_offset, y_offset, renderer);
        break;
      case ClosedDoor:
        _textureArrayRef[4]->render(x_offset, y_offset, renderer);
        break;
      case OpenDoor:
        _textureArrayRef[5]->render(x_offset, y_offset, renderer);
        break;
      case UpStairs:
        _textureArrayRef[2]->render(x_offset, y_offset, renderer);
        _textureArrayRef[6]->render(x_offset, y_offset, renderer);
        break;
      case DownStairs:
        _textureArrayRef[7]->render(x_offset, y_offset, renderer);
        break;
      case Unused:
      default:
        _textureArrayRef[1]->render(x_offset, y_offset, renderer);
        break;
      }
      y_offset -= TILE_SQUARE_SIDE_LENGTH;
    }
    x_offset += TILE_SQUARE_SIDE_LENGTH;
  }
}

// TODO finish the rendering methods
void camera::heroRenderPass(SDL_Renderer* renderer)
{
  //TODO
  _textureArrayRef[23]->render(CAMERA_RENDER_TILE_WIDTH * TILE_SQUARE_SIDE_LENGTH / 2, CAMERA_RENDER_TILE_HEIGHT * TILE_SQUARE_SIDE_LENGTH / 2, renderer);

}

void camera::entityRenderPass(SDL_Renderer* renderer)
{
  
  //TODO
}

void camera::armorRenderPass(SDL_Renderer* renderer)
{
  
  //TODO
}

void camera::itemRenderPass(SDL_Renderer* renderer)
{
  
  //TODO
}

