#include "map.h"
#include "textureManager.h"

int map1[20][25] = {
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

Map::Map()
{
  grass = textureManager::loadTexture("assets/grass.png");
  hedge = textureManager::loadTexture("assets/hedge.png");

  loadMap(map1);

  srcRect.x = srcRect.y = 0;
  srcRect.w = destRect.w = 32;
  srcRect.h = destRect.h = 32;

  destRect.x = destRect.y = 0;
} //Map()
Map::~Map()
{

}

void Map::loadMap(int arr[20][25])
{
  for(int row = 0; row < 20; row++)
  {
    for(int column = 0; column < 25; column++)
    {
      map[row][column] = arr[row][column];
    } //int column = 0; column < 25; column++
  } //int row = 0; row < 20; row++
} //loadMap(int arr[20][25])

void Map::drawMap()
{
  int type = 0;

  for(int row = 0; row < 20; row++)
  {
    for(int column = 0; column < 25; column++)
    {
      type = map[row][column];

      destRect.x = column * 32;
      destRect.y = row * 32;

      switch(type)
      {
      case 0:
        textureManager::draw(grass, srcRect, destRect);
        break;
      case 1:
        textureManager::draw(hedge, srcRect, destRect);
        break;
      default:
        break;
      } //switch(type)
    } //int column = 0; column < 25; column++
  } //int row = 0; row < 20; row++
} //drawMap()
