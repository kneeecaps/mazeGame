#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Game
{
public:
  Game();
  ~Game();

  void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() {return isRunning;}

  void addMoney();

  int getTime() {return frameCount / 60;}
  int getMoney() {return totalMoney;}
  int getScore() {return (((totalMoney * 4) + (150 - getTime())));}

  static SDL_Renderer* renderer;
private:
  void levelComplete();
  void gameComplete();
  bool leaderboardShown = false;

  bool isRunning;
  int frameCount = 0;

  int totalMoney = 0;
  int money = 0;
  SDL_Rect moneySrcRect;
  SDL_Rect moneyDestRect;

  SDL_Texture* coin07;
  SDL_Texture* coin17;
  SDL_Texture* coin27;
  SDL_Texture* coin37;
  SDL_Texture* coin47;
  SDL_Texture* coin57;
  SDL_Texture* coin67;
  SDL_Texture* coin77;

  SDL_Window* window;
};
