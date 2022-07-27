#include "map.h"

Map::Map(int tmpViewMap[20][25], int tmpGameMap[20][25])
{
 gameMap.loadMap(tmpGameMap);
 viewMap.loadMap(tmpViewMap);
}
Map::~Map()
{

}

void Map::render()
{
  viewMap.drawMap();
  gameMap.drawMap();
}

int Map::move(int direction, int& money)
{
  return gameMap.move(direction, money);
}
