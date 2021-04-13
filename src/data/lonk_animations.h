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
                           Vector2(2, 0), 150);
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 112, .w = 17, .h = 18},
                           Vector2(2, 0), 150);
    frames.push_back(frame);

    Animation animation =
        Animation(AnimationType::kWalkDown, frames, 1, true, true);
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
                           Vector2(0, 0), 1000);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Side idle
    frame = AnimationFrame({.x = 159, .y = 448, .w = 17, .h = 18},
                           Vector2(0, 0), 1000);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Up idle
    frame = AnimationFrame({.x = 159, .y = 496, .w = 17, .h = 18},
                           Vector2(0, 0), 1000);
    frames.push_back(frame);

    animation = Animation(AnimationType::kIdle, frames, 0, true, true);

    animations.push_back(animation);

    frames.clear();

    // Attack Down
    frame = AnimationFrame({.x = 15, .y = 258, .w = 17, .h = 18},
                           Vector2(-3, 6), 200); // 200
    frames.push_back(frame);
    frame = AnimationFrame({.x = 63, .y = 256, .w = 17, .h = 27},
                           Vector2(-3, 0), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 257, .w = 16, .h = 26},
                           Vector2(3, 3), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 257, .w = 15, .h = 19},
                           Vector2(3, 3), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kAttack, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Down flipped
    frame = AnimationFrame({.x = 15, .y = 258, .w = 17, .h = 18}, Vector2(3, 6),
                           200); // 200
    frames.push_back(frame);
    frame = AnimationFrame({.x = 63, .y = 256, .w = 17, .h = 27}, Vector2(3, 0),
                           150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 257, .w = 16, .h = 26},
                           Vector2(0, 3), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 257, .w = 15, .h = 19},
                           Vector2(3, 3), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kAttack, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack right
    frame = AnimationFrame({.x = 16, .y = 306, .w = 13, .h = 14}, Vector2(3, 6),
                           200); // 200
    frames.push_back(frame);
    frame = AnimationFrame({.x = 66, .y = 304, .w = 27, .h = 16}, Vector2(9, 0),
                           150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 114, .y = 304, .w = 27, .h = 16},
                           Vector2(9, 0), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 162, .y = 304, .w = 18, .h = 16},
                           Vector2(9, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kAttack, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack left
    frame = AnimationFrame({.x = 16, .y = 306, .w = 13, .h = 14}, Vector2(9, 6),
                           200); // 200
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 66, .y = 304, .w = 27, .h = 16}, Vector2(-39, 0),
                       150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 114, .y = 304, .w = 27, .h = 16},
                           Vector2(-39, 0), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 162, .y = 304, .w = 18, .h = 16},
                           Vector2(-12, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kAttack, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Up
    frame = AnimationFrame({.x = 18, .y = 354, .w = 15, .h = 14}, Vector2(9, 6),
                           200); // 200
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 63, .y = 341, .w = 18, .h = 27}, Vector2(0, -33),
                       150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 110, .y = 341, .w = 16, .h = 27},
                           Vector2(-3, -33), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 159, .y = 350, .w = 15, .h = 18},
                           Vector2(0, -6), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kAttack, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();

    // Attack Up flipped
    frame =
        AnimationFrame({.x = 18, .y = 354, .w = 15, .h = 14}, Vector2(-3, 6),
                       200); // 200
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 63, .y = 341, .w = 18, .h = 27}, Vector2(-3, -33),
                       150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 110, .y = 341, .w = 16, .h = 27},
                           Vector2(6, -33), 150); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 159, .y = 350, .w = 15, .h = 18},
                           Vector2(6, -6), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kAttack, frames, 2, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Down
    frame = AnimationFrame({.x = 16, .y = 402, .w = 16, .h = 14}, Vector2(3, 3),
                           100); // 100
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 65, .y = 391, .w = 17, .h = 20}, Vector2(3, -12),
                       90); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 393, .w = 17, .h = 18},
                           Vector2(3, -6), 90); // 150
    frames.push_back(frame);

    frame =
        AnimationFrame({.x = 65, .y = 391, .w = 17, .h = 20}, Vector2(3, -12),
                       90); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 393, .w = 17, .h = 18},
                           Vector2(3, -6), 90); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 400, .w = 16, .h = 16},
                           Vector2(3, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kHit, frames, 3, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Down flipped
    frame = AnimationFrame({.x = 16, .y = 402, .w = 16, .h = 14}, Vector2(0, 3),
                           100); // 100
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 65, .y = 391, .w = 17, .h = 20}, Vector2(-6, -12),
                       90); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 393, .w = 17, .h = 18},
                           Vector2(-6, -6), 90); // 150
    frames.push_back(frame);

    frame =
        AnimationFrame({.x = 65, .y = 391, .w = 17, .h = 20}, Vector2(-6, -12),
                       90); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 113, .y = 393, .w = 17, .h = 18},
                           Vector2(-6, -6), 90); // 150
    frames.push_back(frame);

    frame = AnimationFrame({.x = 160, .y = 400, .w = 16, .h = 16},
                           Vector2(0, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kHit, frames, 3, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Right
    frame = AnimationFrame({.x = 18, .y = 450, .w = 14, .h = 14}, Vector2(9, 6),
                           100); // 100
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 56, .y = 447, .w = 17, .h = 17}, Vector2(-6, -3),
                       90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 107, .y = 448, .w = 16, .h = 16},
                           Vector2(3, 0), 90); // 90
    frames.push_back(frame);

    frame =
        AnimationFrame({.x = 56, .y = 447, .w = 17, .h = 17}, Vector2(-6, -3),
                       90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 107, .y = 448, .w = 16, .h = 16},
                           Vector2(3, 0), 90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 448, .w = 14, .h = 16},
                           Vector2(6, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kHit, frames, 3, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Left
    frame = AnimationFrame({.x = 18, .y = 450, .w = 14, .h = 14}, Vector2(0, 6),
                           100); // 100
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 56, .y = 447, .w = 17, .h = 17}, Vector2(6, -3),
                       90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 107, .y = 448, .w = 16, .h = 16},
                           Vector2(0, 0), 90); // 90
    frames.push_back(frame);

    frame =
        AnimationFrame({.x = 56, .y = 447, .w = 17, .h = 17}, Vector2(6, -3),
                       90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 107, .y = 448, .w = 16, .h = 16},
                           Vector2(0, 0), 90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 161, .y = 448, .w = 14, .h = 16},
                           Vector2(3, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kHit, frames, 3, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Up
    frame =
        AnimationFrame({.x = 15, .y = 495, .w = 15, .h = 17}, Vector2(0, -3),
                       100); // 100
    frames.push_back(frame);
    frame =
        AnimationFrame({.x = 60, .y = 503, .w = 19, .h = 14}, Vector2(-9, 6),
                       90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 108, .y = 502, .w = 19, .h = 15},
                           Vector2(-9, 3), 90); // 90
    frames.push_back(frame);

    frame =
        AnimationFrame({.x = 60, .y = 503, .w = 19, .h = 14}, Vector2(-9, 6),
                       90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 108, .y = 502, .w = 19, .h = 15},
                           Vector2(-9, 3), 90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 159, .y = 496, .w = 15, .h = 16},
                           Vector2(0, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kHit, frames, 3, false, false);

    animations.push_back(animation);

    frames.clear();

    // Hit Up Flipped
    frame =
        AnimationFrame({.x = 15, .y = 495, .w = 15, .h = 17}, Vector2(6, -3),
                       100); // 100
    frames.push_back(frame);
    frame = AnimationFrame({.x = 60, .y = 503, .w = 19, .h = 14}, Vector2(3, 6),
                           90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 108, .y = 502, .w = 19, .h = 15},
                           Vector2(3, 3), 90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 60, .y = 503, .w = 19, .h = 14}, Vector2(3, 6),
                           90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 108, .y = 502, .w = 19, .h = 15},
                           Vector2(3, 3), 90); // 90
    frames.push_back(frame);

    frame = AnimationFrame({.x = 159, .y = 496, .w = 15, .h = 16},
                           Vector2(6, 0), 100); // 100
    frames.push_back(frame);

    animation = Animation(AnimationType::kHit, frames, 3, false, false);

    animations.push_back(animation);

    frames.clear();
  }
};
#endif
