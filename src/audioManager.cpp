#include "audioManager.h"

void audioManager::playSound(const char soundPath[])
{
  PlaySound(soundPath, NULL, SND_ASYNC);
}
