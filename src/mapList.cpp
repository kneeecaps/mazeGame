#include "mapList.h"

MapList::MapList()
{

}
MapList::~MapList()
{

}

void MapList::renderCurrentMap()
{
    maps[lvl].render();
} //renderCurrentMap()

int MapList::move(int direction, int& money)
{
  return maps[lvl].move(direction, money);
}
