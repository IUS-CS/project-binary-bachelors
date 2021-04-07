#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include <string>
#include <vector>

#include "animation_frame.h"

enum class AnimationType {
  kIdle,
  kWalkUp,
  kWalkDown,
  kWalkSide,
};

// A wrapper struct holding all the info we need about an animation.
struct Animation {
  Animation() {}
  Animation(AnimationType ltype, std::vector<AnimationFrame> frames, int num) {
    type = ltype;
    animation_frames = frames;
    priority = num;
  }
  ~Animation() {}

  AnimationType type;
  int current_frame_id = 0;

  // Series of images for animation and their offsets.
  std::vector<AnimationFrame> animation_frames;
  int priority;
};
#endif
