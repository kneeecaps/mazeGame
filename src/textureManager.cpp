#include "textureManager.h"
#include "game.h"

SDL_Texture* textureManager::loadTexture(const char* texture)
{
  SDL_Surface* tmpSurface = IMG_Load(texture);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);

  return tex;
}

void textureManager::draw(SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect destRect)
{
  SDL_RenderCopy(Game::renderer, tex, &srcRect, &destRect);
}
