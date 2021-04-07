#ifndef ANIMATION_ENGINE_H
#define ANIMATION_ENGINE_H

#include "game_object.h"

#include <vector>

class AnimationEngine {
public:
  AnimationEngine();
  ~AnimationEngine();
  void Run(GameObject &object);
  bool IsItTimeToChangeFrames(GameObject &object);
  void StartNewAnimation(GameObject &object, AnimationType type);
  void PickAnimation(GameObject &object);
};
#endif
