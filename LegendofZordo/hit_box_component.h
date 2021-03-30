#ifndef HIT_BOX_COMPONENT_H
#define HIT_BOX_COMPONENT_H

#include <SDL.h>
#include <vector>

struct HitBoxComponent {
  HitBoxComponent() {}
  ~HitBoxComponent() {}

  bool is_invincible = false;
  int time_since_last_hit_ms;
};

#endif