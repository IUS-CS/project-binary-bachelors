#include "audio.h"

Audio::~Audio() { Mix_FreeMusic(background_music); }

void Audio::Load(const char *filename) {}

void Audio::Play() { Mix_PlayMusic(background_music, -1); }
