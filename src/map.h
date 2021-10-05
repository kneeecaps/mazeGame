#include "viewMap.h"
#include "gameplayMap.h"

class Map
{
public:
  Map(ViewMap tmpViewMap, GamePlayMap tmpGameMap);
  ~Map();

  void render();

  int move(int direction, int& money);
private:
  GamePlayMap gameMap;
  ViewMap viewMap;
};
