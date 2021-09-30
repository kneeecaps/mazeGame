#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

#include "SDL2/SDL_image.h"

struct leaderboardPos
{
  leaderboardPos(std::string name, int time, int money, int score) : name(name), time(time), money(money), score(score) {}

  bool operator > (const leaderboardPos& pos) const
  {
    return (score > pos.score);
  }

  std::string name;
  int time;
  int money;
  int score;
};

class Leaderboard
{
public:
  Leaderboard();
  ~Leaderboard();

  void getLeaderboard();
  void showLeaderboardBackground();
  void showLeaderboardText();
  void displayLeaderboard();
  void saveToLeaderboard(std::string name, int time, int money, int score);
private:
  int leaderboardBackgroundMap[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,7,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,0},
    {0,8,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,9,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };
  SDL_Rect backgroundSrcRect;
  SDL_Rect backgroundDestRect;

  SDL_Texture* dirt;
  SDL_Texture* dirtTop;
  SDL_Texture* dirtBottom;
  SDL_Texture* dirtRight;
  SDL_Texture* dirtLeft;
  SDL_Texture* dirtTopLeft;
  SDL_Texture* dirtTopRight;
  SDL_Texture* dirtBottomLeft;
  SDL_Texture* dirtBottomRight;

  SDL_Rect noLeaderboardTxtSrcRect;
  SDL_Rect noLeaderboardTxtDestRect;

  SDL_Texture* noLeaderboardText;

  std::vector<leaderboardPos> leaderboard;
};
