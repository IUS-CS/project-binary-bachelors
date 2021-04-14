#ifndef GREEN_RUPEE_ANIMATIONS_H
#define GREEN_RUPEE_ANIMATIONS_H

#include "../animation.h"
#include "../animation_frame.h"

#include <vector>

struct GreenRupeeAnimations {
  AnimationFrame frame;
  std::vector<Animation> animations;
  std::vector<AnimationFrame> frames;
  GreenRupeeAnimations() {
    frame =
        AnimationFrame({.x = 5, .y = 87, .w = 8, .h = 14}, Vector2(0, 0), 2500);
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 18, .y = 87, .w = 8, .h = 14}, Vector2(0, 0), 200);
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 31, .y = 87, .w = 8, .h = 14}, Vector2(0, 0), 200);
    frames.push_back(frame);
    Animation animation =
        Animation(AnimationType::kIdle, frames, 1, true, true);
    animations.push_back(animation);
  }
};
#endif
