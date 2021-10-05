#include "viewMap.h"
#include "gameplayMap.h"

class Map
{
public:
  Map(int tmpViewMap[20][25], int tmpGameMap[20][25]);
  ~Map();

  void render();

  int move(int direction, int& money);
private:
  GamePlayMap gameMap;
  ViewMap viewMap;
};
