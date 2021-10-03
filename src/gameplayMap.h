#include "SDL2/SDL_image.h"

class gameplayMap
{
public:
  gameplayMap();
  ~gameplayMap();

  void loadMap(int arr[20][25]);
  void drawMap();

  void checkEnemy(int& money);
  void removeEnemy();

  int move(int direction, int& money);
  int checkMove(int direction);
private:
  int gameplayMap1[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,3},
    {1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,0,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,0,4,1,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,1,1,4,1,0,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,4,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,6,1,1,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1},
    {1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,4,1,0,1},
    {1,0,1,0,1,1,0,1,0,1,1,1,1,1,1,0,4,0,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,1,1,0,1,0,0,0,4,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

  int playerY = 19;
  int playerX = 1;

  SDL_Rect srcRect, destRect;

  SDL_Texture* player;
  SDL_Texture* enemy;
  SDL_Texture* startFlag;
  SDL_Texture* endFlag;
  SDL_Texture* coin;

  int map[20][25];
};
