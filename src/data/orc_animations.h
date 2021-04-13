#ifndef ORC_ANIMATIONS_H
#define ORC_ANIMATIONS_H

#include "../animation.h"
#include "../animation_frame.h"

struct OrcAnimations {
  Animation animation;
  AnimationFrame frame;
  std::vector<AnimationFrame> frames;
  std::vector<Animation> animations;
  OrcAnimations() {
    // Move Down
    frame = AnimationFrame({.x = 16, .y = 110, .w = 16, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 110, .w = 16, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 110, .w = 16, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 110, .w = 16, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    Animation animation =
        Animation(AnimationType::kWalkDown, frames, 1, true, true);
    animations.push_back(animation);

    frames.clear();

    // Move sideways
    frame = AnimationFrame({.x = 16, .y = 158, .w = 16, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 158, .w = 16, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 158, .w = 16, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 158, .w = 16, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkSide, frames, 1, true, true);

    animations.push_back(animation);

    frames.clear();

    // Move up
    frame = AnimationFrame({.x = 15, .y = 206, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 63, .y = 206, .w = 17, .h = 18}, Vector2(0, 0),
                           150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 111, .y = 206, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 159, .y = 206, .w = 17, .h = 18},
                           Vector2(0, 0), 150);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, true, true);

    animations.push_back(animation);

    frames.clear();

    // Down idle
    frame = AnimationFrame({.x = 160, .y = 398, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Side idle
    frame = AnimationFrame({.x = 160, .y = 446, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Up idle
    frame = AnimationFrame({.x = 160, .y = 494, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();
  }
};
#endif
