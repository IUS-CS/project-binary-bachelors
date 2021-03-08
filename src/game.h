#ifndef GAME_H
#define GAME_H

#include "game_object.h"

#include <vector>

class Game {
public:
  Game();
  ~Game();

  // This function is the game. While in this function, the game is running.
  // When you leave this function, the game is closed.
  void Run();
  void LimitFrameRate();

  int frame_start_time_ms;
};
#endif
