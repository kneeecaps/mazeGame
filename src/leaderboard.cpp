#include <sstream>

#include "leaderboard.h"

#include "textureManager.h"

Leaderboard::Leaderboard()
{
  dirt = textureManager::loadTexture("assets/dirt.png");
  dirtTop = textureManager::loadTexture("assets/dirt.top.png");
  dirtBottom = textureManager::loadTexture("assets/dirt.bottom.png");
  dirtRight = textureManager::loadTexture("assets/dirt.right.png");
  dirtLeft = textureManager::loadTexture("assets/dirt.left.png");
  dirtTopLeft = textureManager::loadTexture("assets/dirt.topLeft.png");
  dirtTopRight = textureManager::loadTexture("assets/dirt.topRight.png");
  dirtBottomLeft = textureManager::loadTexture("assets/dirt.bottomLeft.png");
  dirtBottomRight = textureManager::loadTexture("assets/dirt.bottomRight.png");

  backgroundSrcRect.x = backgroundSrcRect.y = 0;
  backgroundSrcRect.w = backgroundDestRect.w = 32;
  backgroundSrcRect.h = backgroundDestRect.h = 32;

  backgroundDestRect.x = backgroundDestRect.y = 0;
}

Leaderboard::~Leaderboard()
{

}

void Leaderboard::getLeaderboard()
{
  leaderboard.clear();

  std::ifstream leaderboardFile("data/leaderboard/leaderboard.data");

  for(std::string line; getline(leaderboardFile, line);)
  {
    std::string tmpName;
    int tmpTime;
    int tmpMoney;
    int tmpScore;

    tmpName = line.substr(0, line.find('*'));
    tmpTime = std::stoi(line.substr(line.find('*') + 1, line.find('#')));
    tmpMoney = std::stoi(line.substr(line.find('#') + 1, line.find('@')));
    tmpScore = std::stoi(line.substr(line.find('@') + 1));

    leaderboard.push_back(leaderboardPos(tmpName, tmpTime, tmpMoney, tmpScore));
  } //std::string line; getline(leaderboardFile, line);

  leaderboardFile.close();

  std::partial_sort(leaderboard.begin(), leaderboard.begin() + 5, leaderboard.end(), std::greater{});
} //getLeaderboard()

void Leaderboard::showLeaderboardBackground()
{
  int type = 0;

  for(int row = 0; row < 20; row++)
  {
    for(int column = 0; column < 25; column++)
    {
      type = leaderboardBackgroundMap[row][column];

      backgroundDestRect.x = column * 32;
      backgroundDestRect.y = row * 32;

      switch(type)
      {
      case 0:
        break;
      case 1:
        textureManager::draw(dirt, backgroundSrcRect, backgroundDestRect);
        break;
      case 2:
        textureManager::draw(dirtTop, backgroundSrcRect, backgroundDestRect);
        break;
      case 3:
        textureManager::draw(dirtBottom, backgroundSrcRect, backgroundDestRect);
        break;
      case 4:
        textureManager::draw(dirtLeft, backgroundSrcRect, backgroundDestRect);
        break;
      case 5:
        textureManager::draw(dirtRight, backgroundSrcRect, backgroundDestRect);
        break;
      case 6:
        textureManager::draw(dirtTopLeft, backgroundSrcRect, backgroundDestRect);
        break;
      case 7:
        textureManager::draw(dirtTopRight, backgroundSrcRect, backgroundDestRect);
        break;
      case 8:
        textureManager::draw(dirtBottomLeft, backgroundSrcRect, backgroundDestRect);
        break;
      case 9:
        textureManager::draw(dirtBottomRight, backgroundSrcRect, backgroundDestRect);
        break;
      default:
        break;
      } //switch(type)
    } //int column = 0; column < 25; column++
  } //int row = 0; row < 20; row++
} //showLeaderboardBackground()

void Leaderboard::showLeaderboardText(SDL_Renderer *renderer)
{
  TTF_Init();

  int j = 1;
  std::stringstream leaderboardContentsText;
  std::string leaderboardTitleText;
  std::string leaderboardMessageText;

  leaderboardTitleText = "---LEADERBOARD---";
  leaderboardMessageText = "Please switch to the terminal window to save your score to the leaderboard. Do not close this window if you want to save it";
  leaderboardContentsText << "Name | time | money | score\n";
  for(leaderboardPos i : leaderboard)
  {
    if(j < 6)
    {
      leaderboardContentsText << j << ". " << i.name << " | " << i.time << " | " << i.money << " | " << i.score << "    ";
      j++;
    } // j < 6
    else
    {
      break;
    }
  } //leaderboardPos i : leaderboard

  TTF_Font *font = TTF_OpenFont("assets/pressStart.ttf", 24);
  SDL_Color color = {255, 255, 255};
  Uint32 leaderboardWidth = 716;
  SDL_Surface *leaderboardContentsSurface = TTF_RenderText_Blended_Wrapped(font, leaderboardContentsText.str().c_str(), color, leaderboardWidth);
  SDL_Surface *leaderboardTitleSurface = TTF_RenderText_Blended_Wrapped(font, leaderboardTitleText.c_str(), color, leaderboardWidth);
  SDL_Surface *leaderboardMessageSurface = TTF_RenderText_Blended_Wrapped(font, leaderboardMessageText.c_str(), color, leaderboardWidth);

  SDL_Texture *leaderboardContents = SDL_CreateTextureFromSurface(renderer, leaderboardContentsSurface);
  SDL_Texture *leaderboardTitle = SDL_CreateTextureFromSurface(renderer, leaderboardTitleSurface);
  SDL_Texture *leaderboardMessage = SDL_CreateTextureFromSurface(renderer, leaderboardMessageSurface);

  int contentsW = 0;
  int contentsH = 0;
  int titleW = 0;
  int titleH = 0;
  int messageW = 0;
  int messageH = 0;
  SDL_QueryTexture(leaderboardContents, NULL, NULL, &contentsW, &contentsH);
  SDL_Rect leaderboardContentsRect = {42, 74, contentsW, contentsH};
  SDL_QueryTexture(leaderboardTitle, NULL, NULL, &titleW, &titleH);
  SDL_Rect leaderboardTitleRect = {196, 42, titleW, titleH};
  SDL_QueryTexture(leaderboardMessage, NULL, NULL, &messageW, &messageH);
  SDL_Rect leaderboardMessageRect = {42, 292, messageW, messageH};

  SDL_RenderCopy(renderer, leaderboardContents, NULL, &leaderboardContentsRect);
  SDL_RenderCopy(renderer, leaderboardTitle, NULL, &leaderboardTitleRect);
  SDL_RenderCopy(renderer, leaderboardMessage, NULL, &leaderboardMessageRect);
  SDL_RenderPresent(renderer);

  SDL_DestroyTexture(leaderboardContents);
  SDL_DestroyTexture(leaderboardTitle);
  SDL_DestroyTexture(leaderboardMessage);
  SDL_FreeSurface(leaderboardContentsSurface);
  SDL_FreeSurface(leaderboardTitleSurface);
  SDL_FreeSurface(leaderboardMessageSurface);
  TTF_CloseFont(font);
  TTF_Quit();
}

void Leaderboard::displayLeaderboard()
{
  getLeaderboard();

  std::cout << "--LEADERBOARD--\nNOTE: Some scores were recorded before current version of game\n\n";
  int j = 1;
  for(leaderboardPos i : leaderboard)
  {
    if(j < 6)
    {
      std::cout << j << ". " << "Name: " << i.name << "; Time: " << i.time << "; Money: " << i.money << "; Score: " << i.score << "\n";
      j++;
    } // j < 6
    else
    {
      break;
    }
  } //leaderboardPos i : leaderboard
} //displayLeaderboard()

void Leaderboard::saveToLeaderboard(std::string name, int time, int money, int score)
{
  leaderboardPos tmpLeaderboardPos(name, time, money, score);

  std::ofstream leaderboardFile;
  leaderboardFile.open("data/leaderboard/leaderboard.data", std::ios::app);

  leaderboardFile << tmpLeaderboardPos.name << '*' << tmpLeaderboardPos.time << '#' << tmpLeaderboardPos.money << '@' << tmpLeaderboardPos.score << "\n" ;
} //saveToLeaderboard(std::string name, int time, int money, int score)

void Leaderboard::saveToLeaderboard(leaderboardPos tmpLeaderboardPos)
{
  std::ofstream leaderboardFile;
  leaderboardFile.open("data/leaderboard/leaderboard.data", std::ios::app);

  leaderboardFile << tmpLeaderboardPos.name << '*' << tmpLeaderboardPos.time << '#' << tmpLeaderboardPos.money << '@' << tmpLeaderboardPos.score << "\n" ;

  leaderboardFile.close();
}

void Leaderboard::exportLeaderboard()
{
  getLeaderboard();

  std::ofstream leaderboardFile;
  leaderboardFile.open("data/leaderboard/leaderboard.data", std::ofstream::trunc);
  leaderboardFile.close();

  int j = 0;
  for(leaderboardPos i : leaderboard)
  {
    if(j < 5)
    {
      saveToLeaderboard(i);
      j++;
    }
    else
    {
      break;
    }
  } //leaderboardPos i : leaderboard
} //exportLeaderboard()
