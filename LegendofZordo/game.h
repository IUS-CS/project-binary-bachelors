#ifndef GAME_H
#define GAME_H

#include "data/game_objects_list.h"

class Game {
public:
  Game();
  ~Game();

  // This function is the game. While in this function, the game is running.
  // When you leave this function, the game is closed.
  void Run();
  // This function limits the frame rate to about 60 frames per second. The
  // frame rate must be limited or else the game fluctuates in performance..
  void LimitFrameRate();

  // This variable helps limit the frame rate.
  int frame_start_time_ms;

  GameObjectsList list = GameObjectsList();
  std::vector<GameObject> object_list = list.objects;
};
#endif
