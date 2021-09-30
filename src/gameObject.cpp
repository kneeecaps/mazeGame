#include "gameObject.h"
#include "game.h"
#include "textureManager.h"

gameObject::gameObject(const char* textureSheet, int x, int y)
{
  objTexture = textureManager::loadTexture(textureSheet);

  xPos = x;
  yPos = y;
}

void gameObject::update()
{
  srcRect.h = 32;
  srcRect.w = 32;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xPos;
  destRect.y = yPos;
  destRect.h = srcRect.h;
  destRect.w = srcRect.w;
}
void gameObject::render()
{
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
