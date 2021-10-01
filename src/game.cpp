#include <iostream>

#include "game.h"
#include "textureManager.h"
#include "map.h"
#include "gameplayMap.h"
#include "leaderboard.h"

Map* map;
gameplayMap* gameMap;
Leaderboard* leaderboard;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
  int flags = 0;
  if(fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsystems Initialised...\n";

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window)
    {
      std::cout << "Window created...\n";
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer created...\n";
    } //renderer

    leaderboard = new Leaderboard();

    moneySrcRect.h = 32;
    moneySrcRect.w = 32;
    moneySrcRect.y = 0;
    moneySrcRect.x = 0;
    moneyDestRect.h = 32;
    moneyDestRect.w = 32;
    moneyDestRect.y = 0;
    moneyDestRect.x = 0;

    coin07 = textureManager::loadTexture("assets/coin0.7.png");
    coin17 = textureManager::loadTexture("assets/coin1.7.png");
    coin27 = textureManager::loadTexture("assets/coin2.7.png");
    coin37 = textureManager::loadTexture("assets/coin3.7.png");
    coin47 = textureManager::loadTexture("assets/coin4.7.png");
    coin57 = textureManager::loadTexture("assets/coin5.7.png");
    coin67 = textureManager::loadTexture("assets/coin6.7.png");
    coin77 = textureManager::loadTexture("assets/coin7.7.png");

    isRunning = true;
  } //SDL_Init(SDL_INIT_EVERYTHING) == 0
  else
  {
    isRunning = false;
  }

  map = new Map();
  gameMap = new gameplayMap();
} //init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)

void Game::gameComplete()
{
  std::cout << "\nYour time: " << getTime() << "\n";
  std::cout << "Your score: " << getScore() << "\n\n";

  char saveYN;

  leaderboardShown = true;
  render();

  std::cout << "\nDo you want to save your time? (y/n): ";
  std::cin >> saveYN;
  if(saveYN == 'y' || saveYN == 'Y')
  {
    std::string tmpUsername;
    std::cout << "\n\nYour username for leaderboard(can't have '*', '#' or '@' in it): ";
    std::cin >> tmpUsername;

    leaderboard->saveToLeaderboard(tmpUsername, getTime(), getMoney(), getScore());
  } //saveYN == 'y' || saveYN == 'Y'
  system("pause");

  isRunning = false;
} //gameComplete()

void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_KEYDOWN:
    switch(event.key.keysym.sym)
    {
    case SDLK_UP:
      if(gameMap->move(0) == 4)
      {
        addMoney();
      }
      break;
    case SDLK_DOWN:
      if(gameMap->move(1) == 4)
      {
        addMoney();
      }
      break;
    case SDLK_RIGHT:
      switch(gameMap->move(2))
      {
      case 3:
        gameComplete();
      case 4:
        addMoney();
        break;
      }
      break;
    case SDLK_LEFT:
      if(gameMap->move(3) == 4)
      {
        addMoney();
      }
      break;
    default:
      break;
    } //switch(event.key.keysym.sym)
  } //switch(event.type)
} //handleEvents()
void Game::update()
{
  frameCount++;

  if(money == 7)
  {
    gameMap->removeEnemy();
  }
} //update()
void Game::render()
{
  SDL_RenderClear(renderer);
  map->drawMap();
  gameMap->drawMap();
  switch(money)
  {
  case 0:
    textureManager::draw(coin07, moneySrcRect, moneyDestRect);
    break;
  case 1:
    textureManager::draw(coin17, moneySrcRect, moneyDestRect);
    break;
  case 2:
    textureManager::draw(coin27, moneySrcRect, moneyDestRect);
    break;
  case 3:
    textureManager::draw(coin37, moneySrcRect, moneyDestRect);
    break;
  case 4:
    textureManager::draw(coin47, moneySrcRect, moneyDestRect);
    break;
  case 5:
    textureManager::draw(coin57, moneySrcRect, moneyDestRect);
    break;
  case 6:
    textureManager::draw(coin67, moneySrcRect, moneyDestRect);
    break;
  case 7:
    textureManager::draw(coin77, moneySrcRect, moneyDestRect);
    break;
  default:
    break;
  } //switch(money)

  if(leaderboardShown)
  {
    leaderboard->displayLeaderboard();
    leaderboard->showLeaderboardBackground();
    leaderboard->showLeaderboardText();
  }

  SDL_RenderPresent(renderer);
} //render()
void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game cleaned...\n";
} //clean()
