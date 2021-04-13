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
  kAttack,
  kHit
};

// A wrapper struct holding all the info we need about an animation.
struct Animation {
  Animation() {}
  Animation(AnimationType ltype, std::vector<AnimationFrame> frames, int num,
            bool loopable, bool cancel_when_released) {
    type = ltype;
    animation_frames = frames;
    priority = num;
    loop = loopable;
    cancel_on_key_release = cancel_when_released;
  }
  ~Animation() {}

  bool cancel_on_key_release;
  bool loop;
  AnimationType type;
  int current_frame_id = 0;

  // Series of images for animation and their offsets.
  std::vector<AnimationFrame> animation_frames;
  int priority;
};
#endif
