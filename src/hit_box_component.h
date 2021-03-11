#ifndef HIT_BOX_COMPONENT_H
#define HIT_BOX_COMPONENT_H

#include <SDL2/SDL.h>

enum class HitBoxType { kPlayer, kRupee, kWall, kDefault };

struct HitBoxComponent {
  HitBoxComponent() {}
  ~HitBoxComponent() {}

  HitBoxType type = HitBoxType::kDefault;
};
#endif
