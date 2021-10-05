#include "mapList.h"

MapList::MapList()
{

}
MapList::~MapList()
{

}

void MapList::renderCurrentMap()
{
  switch(lvl)
  {
    case 0:
      maps[0].render();
      break;
    case 1:
      maps[1].render();
      break;
    case 2:
      maps[2].render();
      break;
  } //switch(lvl)
} //renderCurrentMap()

int MapList::move(int direction, int& money)
{
  return maps[lvl].move(direction, money);
}
