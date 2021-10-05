#include <iostream>

#include "GamePlayMap.h"
#include "textureManager.h"
#include "audioManager.h"

#include "game.h"

GamePlayMap::GamePlayMap()
{
  player = textureManager::loadTexture("assets/player.png");
  enemy = textureManager::loadTexture("assets/enemy.png");
  startFlag = textureManager::loadTexture("assets/startFlag.png");
  endFlag = textureManager::loadTexture("assets/endFlag.png");
  coin = textureManager::loadTexture("assets/coin.png");

  srcRect.x = srcRect.y = 0;
  srcRect.w = destRect.w = 32;
  srcRect.h = destRect.h = 32;

  destRect.x = destRect.y = 0;
} //GamePlayMap()
GamePlayMap::~GamePlayMap()
{

}

void GamePlayMap::loadMap(int arr[20][25])
{
  arr[playerY][playerX] = 5;

  for(int row = 0; row < 20; row++)
  {
    for(int column = 0; column < 25; column++)
    {
      map[row][column] = arr[row][column];
    } //int column = 0; column < 25; column++
  } //int row = 0; row < 20; row++
} //loadMap(int arr[20][25])

void GamePlayMap::drawMap()
{
  loadMap(map);

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

void GamePlayMap::checkEnemy(int& money)
{
  if(money >= 3)
  {
    money = money - 3;
    removeEnemy();
  }
  else
  {
    std::cout << "You need to pay 3 coins to pass\n";
  }
}

void GamePlayMap::removeEnemy()
{
  map[9][11] = 0;
}

int GamePlayMap::move(int direction, int& money)
{
  map[playerY][playerX] = 0;

  int checkedMove = 0;
  bool moved = false;

  switch(direction)
  {
  case 0:
    checkedMove = checkMove(0);
    if(checkedMove != 1 && checkedMove != 6)
    {
      playerY--;
      moved = true;
    }
    else if(checkedMove == 6)
    {
      checkEnemy(money);
    }
    break;
  case 1:
    checkedMove = checkMove(1);
    if(checkedMove != 1 && checkedMove != 6)
    {
      playerY++;
      moved = true;
    }
    else if(checkedMove == 6)
    {
      checkEnemy(money);
    }
    break;
  case 2:
    checkedMove = checkMove(2);
    if(checkedMove != 1 && checkedMove != 6)
    {
      playerX++;
      moved = true;
    }
    else if(checkedMove == 6)
    {
      checkEnemy(money);
    }
    break;
  case 3:
    checkedMove = checkMove(3);
    if(checkedMove != 1 && checkedMove != 6 && checkedMove != 2)
    {
      playerX--;
      moved = true;
    }
    else if(checkedMove == 6)
    {
      checkEnemy(money);
    }
    break;
  default:
    break;
  } //switch(direction)
  if(moved)
  {
    audioManager::playSound("assets/dirtStep.wav");
  }
  return checkedMove;
} //move(int direction)

int GamePlayMap::checkMove(int direction)
{
  switch(direction)
  {
  case 0:
    if(playerY - 1 < 0)
    {
      return 1;
    }
    return map[playerY - 1][playerX];
  case 1:
    if(playerY + 1 > 19)
    {
      return 1;
    }
    return map[playerY + 1][playerX];
  case 2:
    if(playerX + 1 > 24)
    {
      return 1;
    }
    return map[playerY][playerX + 1];
  case 3:
    if(playerX - 1 < 0)
    {
      return 1;
    }
    return map[playerY][playerX - 1];
  default:
    break;
  } //switch(direction)
  return 1;
} //checkMove(int direction)
