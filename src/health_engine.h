#ifndef HEALTH_ENGINE_H
#define HEALTH_ENGINE_H
#include "game_object.h"

class HealthEngine {
public:
  HealthEngine();
  ~HealthEngine();
  void Run(GameObject &object);
  void CheckInvincibility(GameObject &object);
};
#endif