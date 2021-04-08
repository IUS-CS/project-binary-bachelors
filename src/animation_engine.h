#ifndef ANIMATION_ENGINE_H
#define ANIMATION_ENGINE_H
#include "game_object.h"

class AnimationEngine {
public:
  AnimationEngine();
  ~AnimationEngine();
  void Run(GameObject &object);
};
#endif
