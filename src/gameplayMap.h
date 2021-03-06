#include "SDL2/SDL_image.h"

class GamePlayMap
{
public:
  GamePlayMap();
  ~GamePlayMap();

  void loadMap(int arr[20][25]);
  void drawMap();

  void checkEnemy(int& money);
  void removeEnemy();

  int move(int direction, int& money);
  int checkMove(int direction);

  int getMap() {return map[20][25];}
private:
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
