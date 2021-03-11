#include "hit_box_engine.h"

#include <iostream>

HitBoxEngine::HitBoxEngine() {}

HitBoxEngine::~HitBoxEngine() {}

void HitBoxEngine::Run(GameObject object,
                       std::vector<GameObject> &objects_list) {
  for (auto &obstacle : objects_list) {
    if (obstacle.type != ObjectType::kPlayer) {
      if (object.location && object.hit_box) {
        // std::cout << "Testing hitbox" << std::endl;
        if ((object.location->coordinates.x <
             obstacle.location->coordinates.x +
                 obstacle.sprite->sprite_rect.w * obstacle.sprite->scale) &&
            (object.location->coordinates.x +
                 object.sprite->sprite_rect.x * object.sprite->scale >
             obstacle.location->coordinates.x) &&
            (object.location->coordinates.y <
             obstacle.location->coordinates.y +
                 obstacle.sprite->sprite_rect.h * obstacle.sprite->scale) &&
            (object.location->coordinates.y +
                 object.sprite->sprite_rect.y * object.sprite->scale >
             obstacle.location->coordinates.y)) {
          if (obstacle.hit_box->type == HitBoxType::kRupee) {
            std::cout << "Hit Rupee!" << std::endl;
          }
          if (obstacle.hit_box->type == HitBoxType::kDefault) {
            std::cout << "Hit!" << std::endl;
          }
        }
      }
    }
  }
}
