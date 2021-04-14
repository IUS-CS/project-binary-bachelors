#ifndef BLUE_RUPEE_ANIMATIONS_H
#define BLUE_RUPEE_ANIMATIONS_H

#include "../animation.h"
#include "../animation_frame.h"

#include <vector>

struct BlueRupeeAnimations {
  AnimationFrame frame;
  std::vector<Animation> animations;
  std::vector<AnimationFrame> frames;
  BlueRupeeAnimations() {
    frame = AnimationFrame({.x = 42, .y = 87, .w = 8, .h = 14}, Vector2(0, 0),
                           2500);
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 55, .y = 87, .w = 8, .h = 14}, Vector2(0, 0), 200);
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 68, .y = 87, .w = 8, .h = 14}, Vector2(0, 0), 200);
    frames.push_back(frame);
    Animation animation =
        Animation(AnimationType::kIdle, frames, 1, true, true);
    animations.push_back(animation);
  }
};
#endif
