#ifndef HIT_BOX_COMPONENT_H
#define HIT_BOX_COMPONENT_H

#include <SDL2/SDL.h>
#include <vector>

struct HitBoxComponent {
  HitBoxComponent() {}
  ~HitBoxComponent() {}

  SDL_Rect hit_box;
  bool is_hit = false;
  bool is_invincible = false;
  int time_since_last_hit_ms;
};

#endif
