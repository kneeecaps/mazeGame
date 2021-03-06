#include "map.h"

class MapList
{
public:
  MapList();
  ~MapList();

  int move(int direction, int& money);

  void renderCurrentMap();

  void addLevel() {lvl++;}
  int getLevel() {return lvl;}
private:
  int gameMap[20][25] = {
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

  int viewMap[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,0,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,1,0,1,1,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1},
    {1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,1,0,1,0,1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

  int gameMap1[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,3},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,4,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,0,0,4,1,1,0,1},
    {1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,4,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1},
    {1,4,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1,0,1},
    {1,4,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,4,0,0,1,1,0,1,0,1,0,0,1,0,1,0,1,4,0,0,1,6,1},
    {1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };

  int viewMap1[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,0,0,0,1,1,0,1},
    {1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,1,1,1,1,1,0,1,0,1,1,1,1,0,0,1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,1,1,1,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,1,1,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };

  int gameMap2[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,3},
    {1,0,4,1,1,1,1,4,0,0,0,0,0,0,4,1,1,4,0,0,0,0,6,0,1},
    {1,0,1,1,0,4,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,4,1,1,0,0,0,0,0,1},
    {1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1},
    {1,0,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,0,1,1,1,1,1,4,1,1,1,1,1,1,1,0,1,1,0,0,0,1},
    {1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1},
    {1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {2,5,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };

  int viewMap2[20][25] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
    {1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1},
    {1,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1},
    {1,0,1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1},
    {1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1},
    {1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1},
    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  };

  int lvl = 0;

  Map maps[3] = {Map(viewMap, gameMap), Map(viewMap1, gameMap1), Map(viewMap2, gameMap2)};
};
