#ifndef AI_ENGINE_H
#define AI_ENGINE_H

#include "game_object.h"

class AIEngine {
public:
  AIEngine();
  ~AIEngine();
  void ChasePlayer(GameObject &object, GameObject &player);
  void NextMove(GameObject &object);
  void CutOffPlayer(GameObject &object, GameObject &player);
  void Run(GameObject &object, GameObject &player);
  bool TimeForNewDecision(GameObject &object);

  bool start_of_new_action = true;
};

#endif
