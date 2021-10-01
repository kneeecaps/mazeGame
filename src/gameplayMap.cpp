#include "gameplayMap.h"
#include "textureManager.h"

gameplayMap::gameplayMap()
{
  player = textureManager::loadTexture("assets/player.png");
  enemy = textureManager::loadTexture("assets/enemy.png");
  startFlag = textureManager::loadTexture("assets/startFlag.png");
  endFlag = textureManager::loadTexture("assets/endFlag.png");
  coin = textureManager::loadTexture("assets/coin.png");

  loadMap(gameplayMap1);

  srcRect.x = srcRect.y = 0;
  srcRect.w = destRect.w = 32;
  srcRect.h = destRect.h = 32;

  destRect.x = destRect.y = 0;
} //gameplayMap()
gameplayMap::~gameplayMap()
{

}

void gameplayMap::loadMap(int arr[20][25])
{
  gameplayMap1[playerY][playerX] = 5;

  for(int row = 0; row < 20; row++)
  {
    for(int column = 0; column < 25; column++)
    {
      map[row][column] = arr[row][column];
    } //int column = 0; column < 25; column++
  } //int row = 0; row < 20; row++
} //loadMap(int arr[20][25])
void gameplayMap::drawMap()
{
  loadMap(gameplayMap1);
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
        break;
      case 1:
        break;
      case 2:
        textureManager::draw(startFlag, srcRect, destRect);
        break;
      case 3:
        textureManager::draw(endFlag, srcRect, destRect);
        break;
      case 4:
        textureManager::draw(coin, srcRect, destRect);
        break;
      case 5:
        textureManager::draw(player, srcRect, destRect);
        break;
      case 6:
        textureManager::draw(enemy, srcRect, destRect);
        break;
      default:
        break;
      } //switch(type)
    } //int column = 0; column < 25; column++
  } //int row = 0; row < 20; row++
} //drawMap()

void gameplayMap::removeEnemy()
{
  gameplayMap1[9][11] = 0;
}

int gameplayMap::move(int direction)
{
  gameplayMap1[playerY][playerX] = 0;

  int checkedMove = 0;

  switch(direction)
  {
  case 0:
    checkedMove = checkMove(0);
    if(checkMove(0) != 1 && checkMove(0) != 6)
    {
      playerY--;
    }
    break;
  case 1:
    checkedMove = checkMove(1);
    if(checkMove(1) != 1 && checkMove(1) != 6)
    {
      playerY++;
    }
    break;
  case 2:
    checkedMove = checkMove(2);
    if(checkMove(2) != 1 && checkMove(2) != 6)
    {
      playerX++;
    }
    break;
  case 3:
    checkedMove = checkMove(3);
    if(checkMove(3) != 1 && checkMove(3) != 6 && checkMove(3) != 2)
    {
      playerX--;
    }
    break;
  default:
    break;
  } //switch(direction)
  return checkedMove;
} //move(int direction)

int gameplayMap::checkMove(int direction)
{
  switch(direction)
  {
  case 0:
    if(playerY - 1 < 0)
    {
      return 1;
    }
    return gameplayMap1[playerY - 1][playerX];
  case 1:
    if(playerY + 1 > 19)
    {
      return 1;
    }
    return gameplayMap1[playerY + 1][playerX];
  case 2:
    if(playerX + 1 > 24)
    {
      return 1;
    }
    return gameplayMap1[playerY][playerX + 1];
  case 3:
    if(playerX - 1 < 0)
    {
      return 1;
    }
    return gameplayMap1[playerY][playerX - 1];
  default:
    break;
  } //switch(direction)
  return 1;
} //checkMove(int direction)
