#include "audioManager.h"
#include <iostream>

void audioManager::playSound(const char soundPath[])
{
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
  {
    std::cout << "SDL_mixer failed to initialise\n";
  }

  Mix_Chunk *chunk = Mix_LoadWAV(soundPath);
  Mix_VolumeChunk(chunk, 128);
  Mix_PlayChannel(-1, chunk, 0);
}
