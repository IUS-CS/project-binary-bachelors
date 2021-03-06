#ifndef GAME_H
#define GAME_H

#include "game_object.h"

#include <vector>

class Game {
public:
  Game();
  ~Game();
  void Run();
  void PreloadTextures();
};
#endif
