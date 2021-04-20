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

    // Attack Down
    frame = AnimationFrame({.x = 16, .y = 249, .w = 18, .h = 23},
                           Vector2(3, -15), 250);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 250, .w = 17, .h = 34},
                           Vector2(3, -12), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 259, .w = 17, .h = 26},
                           Vector2(3, 15), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 258, .w = 17, .h = 22},
                           Vector2(3, 12), 250);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Down Flipped
    frame = AnimationFrame({.x = 16, .y = 249, .w = 18, .h = 23},
                           Vector2(-9, -15), 250);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 250, .w = 17, .h = 34},
                           Vector2(-6, -12), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 259, .w = 17, .h = 26},
                           Vector2(-6, 15), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 258, .w = 17, .h = 22},
                           Vector2(-6, 12), 250);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Right
    frame = AnimationFrame({.x = 11, .y = 299, .w = 20, .h = 21},
                           Vector2(-15, -9), 250);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 65, .y = 297, .w = 26, .h = 23},
                           Vector2(0, -15), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 305, .w = 26, .h = 15},
                           Vector2(0, 9), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 304, .w = 26, .h = 16},
                           Vector2(0, 6), 250);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Left
    frame = AnimationFrame({.x = 11, .y = 299, .w = 20, .h = 21},
                           Vector2(3, -9), 250);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 65, .y = 297, .w = 26, .h = 23},
                           Vector2(-30, -15), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 305, .w = 26, .h = 15},
                           Vector2(-30, 9), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 304, .w = 26, .h = 16},
                           Vector2(-30, 6), 250);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Up
    frame = AnimationFrame({.x = 16, .y = 355, .w = 16, .h = 16},
                           Vector2(3, 15), 250);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 343, .w = 15, .h = 30},
                           Vector2(3, -21), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 343, .w = 15, .h = 25},
                           Vector2(3, -21), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 345, .w = 15, .h = 23},
                           Vector2(3, -15), 250);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Up Flipped
    frame = AnimationFrame({.x = 16, .y = 355, .w = 16, .h = 16},
                           Vector2(0, 15), 250);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 343, .w = 15, .h = 30},
                           Vector2(3, -21), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 343, .w = 15, .h = 25},
                           Vector2(3, -21), 200);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 345, .w = 15, .h = 23},
                           Vector2(3, -15), 250);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Down
    frame = AnimationFrame({.x = 16, .y = 400, .w = 15, .h = 16}, Vector2(0, 0),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 397, .w = 19, .h = 18}, Vector2(0, 0),
                           90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 398, .w = 18, .h = 18},
                           Vector2(0, 0), 90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 398, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Down Flipped
    frame = AnimationFrame({.x = 16, .y = 400, .w = 15, .h = 16}, Vector2(0, 0),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 64, .y = 397, .w = 19, .h = 18}, Vector2(0, 0),
                           90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 112, .y = 398, .w = 18, .h = 18},
                           Vector2(0, 0), 90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 398, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Right
    frame = AnimationFrame({.x = 16, .y = 447, .w = 16, .h = 17}, Vector2(0, 0),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 62, .y = 445, .w = 16, .h = 19}, Vector2(0, 0),
                           90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 111, .y = 445, .w = 16, .h = 19},
                           Vector2(0, 0), 90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 446, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Left
    frame = AnimationFrame({.x = 16, .y = 447, .w = 16, .h = 17}, Vector2(0, 0),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 62, .y = 445, .w = 16, .h = 19}, Vector2(0, 0),
                           90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 111, .y = 445, .w = 16, .h = 19},
                           Vector2(0, 0), 90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 446, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Up
    frame = AnimationFrame({.x = 16, .y = 494, .w = 16, .h = 18}, Vector2(0, 0),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 62, .y = 499, .w = 17, .h = 14}, Vector2(0, 0),
                           90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 110, .y = 498, .w = 17, .h = 14},
                           Vector2(0, 0), 90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 494, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Up Flipped
    frame = AnimationFrame({.x = 16, .y = 494, .w = 16, .h = 18}, Vector2(0, 0),
                           100);
    frames.push_back(frame);
    frame = AnimationFrame({.x = 62, .y = 499, .w = 17, .h = 14}, Vector2(0, 0),
                           90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 110, .y = 498, .w = 17, .h = 14},
                           Vector2(0, 0), 90);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 494, .w = 16, .h = 18},
                           Vector2(0, 0), 100);
    frames.push_back(frame);

    animation = Animation(AnimationType::kWalkUp, frames, 1, false, false);

    animations.push_back(animation);

    frames.clear();
  }
};
#endif
