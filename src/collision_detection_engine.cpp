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
  object.objects_hit.clear();
  if (object.location && object.hit_box) {
    if (object.type == ObjectType::kPlayer) {
      if (!object.location->flip) {
        object.hit_box->hit_box.x = object.location->coordinates.x;
        object.hit_box->hit_box.y = object.location->coordinates.y;
        object.hit_box->hit_box.w = 16 * object.sprite->scale;
        object.hit_box->hit_box.h = 16 * object.sprite->scale;
      } else {
        object.hit_box->hit_box.x =
            object.location->coordinates.x +
            object.sprite->sprite_rect.w * object.sprite->scale -
            object.hit_box->hit_box.w;
        object.hit_box->hit_box.y = object.location->coordinates.y;
        object.hit_box->hit_box.w = 16 * object.sprite->scale;
        object.hit_box->hit_box.h = 16 * object.sprite->scale;
      }
    } else {
      object.hit_box->hit_box.x = object.location->coordinates.x;
      object.hit_box->hit_box.y = object.location->coordinates.y;
      object.hit_box->hit_box.w = object.sprite->sprite_rect.w;
      object.hit_box->hit_box.h = object.sprite->sprite_rect.h;
    }
    HitBox object_hb = GetHitBox(object);
    for (auto &obstacle : objects_list) {
      if (obstacle.is_active && obstacle.location && obstacle.hit_box) {
        if (object.id_num != obstacle.id_num) {
          BoundingBox obstacle_bb = GetBoundingBox(obstacle);
          // If the hit boxes overlap.
          if ((object_hb.left < obstacle_bb.right) &&
              (object_hb.right > obstacle_bb.left) &&
              (object_hb.top < obstacle_bb.bottom) &&
              (object_hb.bottom > obstacle_bb.top)) {
            GameObject *hit_object = &obstacle;
            object.objects_hit.push_back(hit_object);
          }
        }
      }
    }
  }
}
