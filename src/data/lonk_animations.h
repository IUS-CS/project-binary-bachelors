#ifndef LONK_ANIMATIONS_H
#define LONK_ANIMATIONS_H

#include "../animation.h"
#include "../animation_frame.h"

#include <vector>

struct LonkAnimations {
  AnimationFrame frame;
  std::vector<Animation> animations;
  std::vector<AnimationFrame> frames;
  LonkAnimations() {
    // Move Down
    frame = AnimationFrame({.x = 16, .y = 112, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 112, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 112, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 112, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    Animation animation = Animation(AnimationType::kIdle, frames, 0);
    animations.push_back(animation);

    frames.clear();

    // Move sideways
    frame = AnimationFrame({.x = 16, .y = 160, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 160, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 160, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 160, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkSide, frames, 0);

    animations.push_back(animation);

    frames.clear();

    // Move up
    frame = AnimationFrame({.x = 14, .y = 208, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 62, .y = 208, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 110, .y = 208, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 158, .y = 208, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 0);

    animations.push_back(animation);

    frames.clear();

    // Down idle
    frame = AnimationFrame({.x = 159, .y = 400, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0);

    animations.push_back(animation);

    frames.clear();

    // Side idle
    frame = AnimationFrame({.x = 159, .y = 448, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0);

    animations.push_back(animation);

    frames.clear();

    // Up idle
    frame = AnimationFrame({.x = 159, .y = 496, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0);

    animations.push_back(animation);

    frames.clear();
  }
};
#endif
