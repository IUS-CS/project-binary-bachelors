#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#include <vector>

#include "game_object.h"

class SpawnEngine {
public:
  SpawnEngine();
  ~SpawnEngine();
  void Run(std::vector<GameObject> &objects_to_add);

  int last_spawn_time_ms = -10000;
};
#endif
