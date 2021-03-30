#ifndef HEALTH_ENGINE_H
#define HEALTH_ENGINE_H
#include "game_object.h"

// This engine will determine object's remaining hit points.
class HealthEngine {
public:
  HealthEngine();
  ~HealthEngine();
  void Run(GameObject &object);

  // This CheckInvincibility function is required; otherwise, an unintended
  // amount of health will be immediately depleted upon collision.
  void CheckInvincibility(GameObject &object);
};
#endif
