#ifndef MOVEMENT_ENGINE_H
#define MOVEMENT_ENGINE_H

#include "game_object.h"

#include <vector>

class MovementEngine {
public:
  MovementEngine();
  ~MovementEngine();
  void Run(GameObject &object);
};
#endif
