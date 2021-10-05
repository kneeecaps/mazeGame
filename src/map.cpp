#include "map.h"

Map::Map(ViewMap tmpViewMap, GamePlayMap tmpGameMap)
{
 gameMap = tmpGameMap;
 viewMap = tmpViewMap;
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
