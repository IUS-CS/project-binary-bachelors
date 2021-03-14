#include "collision_detection_engine.h"
#include "utils.h"

#include <iostream>

CollisionDetectionEngine::CollisionDetectionEngine() {}

CollisionDetectionEngine::~CollisionDetectionEngine() {}

void CollisionDetectionEngine::Run(GameObject &object,
                                   std::vector<GameObject> &objects_list) {
  // A BoundingBox is a struct that holds the values of the edges of a box.
  // GetBoundingBox is a helper function to return these values. I added this to
  // make the hit box detection if statement a lot easier to read..
  if (object.location && object.hit_box) {
    BoundingBox object_bb = GetBoundingBox(object);
    for (auto &obstacle : objects_list) {
      if (obstacle.is_active && obstacle.location && obstacle.hit_box) {
        if (object.id_num != obstacle.id_num) {
          BoundingBox obstacle_bb = GetBoundingBox(obstacle);
          // If the hit boxes overlap.
          if ((object_bb.left < obstacle_bb.right) &&
              (object_bb.right > obstacle_bb.left) &&
              (object_bb.top < obstacle_bb.bottom) &&
              (object_bb.bottom > obstacle_bb.top)) {
            object.hit_box->objects_hit.push_back(obstacle.hit_box->type);
          }
        }
      }
    }
  }
}
