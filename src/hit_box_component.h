#ifndef HIT_BOX_COMPONENT_H
#define HIT_BOX_COMPONENT_H

#include <SDL2/SDL.h>
#include <vector>

enum class HitBoxType { kPlayer, kGreenRupee, kBlueRupee, kMonster, kWall, kDefault };

struct HitBoxComponent {
  HitBoxComponent() {}
  ~HitBoxComponent() {}

  bool is_invincible = false;
  int time_since_last_hit_ms;
  HitBoxType type = HitBoxType::kDefault;
  std::vector<HitBoxType> objects_hit;
};


#endif
