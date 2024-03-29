#include <iostream>

#include "game.h"
#include "textureManager.h"
#include "audioManager.h"
#include "mapList.h"
#include "leaderboard.h"

MapList* mapList = nullptr;
Leaderboard* leaderboard = nullptr;

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

  mapList = new MapList();
} //init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)

void Game::levelComplete()
{
  totalMoney += money;
  if(mapList->getLevel() == 2)
  {
    audioManager::playSound("assets/levelComplete.wav");
    gameComplete();
  }
  else
  {
    audioManager::playSound("assets/levelComplete.wav");
    money = 0;
    mapList->addLevel();
  }
} //levelComplete()

void Game::gameComplete()
{
  std::cout << "\nYour time: " << getTime() << "\n";
  std::cout << "Your score: " << getScore() << "\n\n";

  char saveYN;

  leaderboardShown = true;
  render();

  std::cout << "\nDo you want to save your score? (y/n): ";
  std::cin >> saveYN;
  if(saveYN == 'y' || saveYN == 'Y')
  {
    std::string tmpUsername;
    std::cout << "\n\nYour username for leaderboard(can't have '*', '#' or '@' in it): ";
    std::cin >> tmpUsername;

    leaderboard->saveToLeaderboard(tmpUsername, getTime(), getMoney(), getScore());
  } //saveYN == 'y' || saveYN == 'Y'

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
      if(mapList->move(0, money) == 4)
      {
        addMoney();
      }
      break;
    case SDLK_DOWN:
      if(mapList->move(1, money) == 4)
      {
        addMoney();
      }
      break;
    case SDLK_RIGHT:
      switch(mapList->move(2, money))
      {
      case 3:
        levelComplete();
        break;
      case 4:
        addMoney();
        break;
      }
      break;
    case SDLK_LEFT:
      if(mapList->move(3, money) == 4)
      {
        addMoney();
      }
      break;
    default:
      break;
    } //switch(event.key.keysym.sym)
  } //switch(event.type)
} //handleEvents()

void Game::addMoney()
{
  money++;
  audioManager::playSound("assets/coinPickup.wav");
} //addMoney()

void Game::update()
{
  frameCount++;
} //update()

void Game::render()
{
  SDL_RenderClear(renderer);
  mapList->renderCurrentMap();
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
    leaderboard->showLeaderboardText(renderer);
  }

  SDL_RenderPresent(renderer);
} //render()

void Game::clean()
{
  leaderboard->exportLeaderboard();

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  std::cout << "Game cleaned...\n";
} //clean()
