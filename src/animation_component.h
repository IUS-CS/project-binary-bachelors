#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include "animation.h"
#include <vector>

struct AnimationComponent {
  std::vector<Animation> animation_list;
  int current_animation_id = 3;
  int start_of_last_animation_frame_ms = 0;

  AnimationComponent() {}
  AnimationComponent(std::vector<Animation> list) { animation_list = list; }
};
#endif
