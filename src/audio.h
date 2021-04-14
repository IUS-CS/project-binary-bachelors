#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL_mixer.h>
#include <string>

class Audio {
public:
  ~Audio();
  void Load(const char *filename);
  void Play();

  Mix_Music *background_music = Mix_LoadMUS("Storm.mp3");
};
#endif
