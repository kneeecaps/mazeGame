#include "SDL2/SDL.h"

class gameObject
{
public:
  gameObject(const char* textureSheet, int x, int y);
  ~gameObject();

  void update();
  void render();

  void setX(int x) {xPos = x;}
  void setY(int y) {yPos = y;}
  int getX() {return xPos;}
  int getY() {return yPos;}
private:
  int xPos;
  int yPos;

  SDL_Texture* objTexture;
  SDL_Rect srcRect, destRect;
};
