#include "SDL2/SDL_image.h"

class Map
{
public:
  Map();
  ~Map();

  void loadMap(int arr[20][25]);
  void drawMap();
private:
  SDL_Rect srcRect, destRect;

  SDL_Texture* grass;
  SDL_Texture* hedge;

  int map[20][25];
};
