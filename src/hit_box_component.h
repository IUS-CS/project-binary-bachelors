#ifndef HIT_BOX_COMPONENT_H
#define HIT_BOX_COMPONENT_H

#include <SDL2/SDL.h>

enum class HitBoxType { kPlayer, kGreenRupee, kBlueRupee, kWall, kDefault };

struct HitBoxComponent {
  HitBoxComponent() {}
  ~HitBoxComponent() {}

  HitBoxType type = HitBoxType::kDefault;
};
#endif
