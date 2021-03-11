#ifndef HIT_BOX_ENGINE_H
#define HIT_BOX_ENGINE_H

#include "game_object.h"

#include <vector>

class HitBoxEngine {
public:
  HitBoxEngine();
  ~HitBoxEngine();
  void Run(GameObject object, std::vector<GameObject> &objects_list);
};
#endif
