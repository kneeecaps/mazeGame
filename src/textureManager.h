#include "SDL2/SDL_image.h"

class textureManager
{
public:
  static SDL_Texture* loadTexture(const char* texture);

  static void draw(SDL_Texture* tex, SDL_Rect srcRect, SDL_Rect destRect);
};
