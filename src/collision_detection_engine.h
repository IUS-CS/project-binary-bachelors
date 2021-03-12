#ifndef COLLISION_DETECTION_ENGINE_H
#define COLLISION_DETECTION_ENGINE_H

#include "game_object.h"

#include <vector>

// This engine will detect if 2 hitboxes collide.
class CollisionDetectionEngine {
public:
  CollisionDetectionEngine();
  ~CollisionDetectionEngine();
  void Run(GameObject object, std::vector<GameObject> &objects_list);
};
#endif
