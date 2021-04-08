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

    Animation animation =
        Animation(AnimationType::kIdle, frames, 1, true, true);
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

    animation = Animation(AnimationType::kWalkSide, frames, 1, true, true);

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

    animation = Animation(AnimationType::kWalkUp, frames, 1, true, true);

    animations.push_back(animation);

    frames.clear();

    // Down idle
    frame = AnimationFrame({.x = 159, .y = 400, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Side idle
    frame = AnimationFrame({.x = 159, .y = 448, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Up idle
    frame = AnimationFrame({.x = 159, .y = 496, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Attack
    frame = AnimationFrame({.x = 15, .y = 258, .w = 17, .h = 18}, Vector2(1, 6),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 63, .y = 256, .w = 17, .h = 27}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 257, .w = 16, .h = 26},
                           Vector2(8, 3), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 257, .w = 15, .h = 19},
                           Vector2(8, 3), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();
  }
};
#endif
