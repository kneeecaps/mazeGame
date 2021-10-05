#include "SDL2/SDL_image.h"

class ViewMap
{
public:
  ViewMap();
  ~ViewMap();

  void loadMap(int arr[20][25]);
  void drawMap();

  int getMap() {return map[20][25];}
private:
  SDL_Rect srcRect, destRect;

  SDL_Texture* grass;
  SDL_Texture* hedge;

  int map[20][25];
};
