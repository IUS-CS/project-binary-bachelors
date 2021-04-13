#ifndef ANIMATIONFRAME
#define ANIMATIONFRAME
#include "vector2.h"
#include <SDL2/SDL.h>

struct AnimationFrame {
  SDL_Rect source;
  Vector2 offset;
  int time_before_next_frame;

  AnimationFrame() {}
  AnimationFrame(SDL_Rect frame, Vector2 xyoffset, int time) {
    source = frame;
    offset = xyoffset;
    time_before_next_frame = time;
  }
};
#endif
