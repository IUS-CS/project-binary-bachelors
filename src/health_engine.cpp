#include "health_engine.h"
#include <iostream>

HealthEngine::HealthEngine() {}

HealthEngine::~HealthEngine() {}

void HealthEngine::Run(GameObject &object) {
  if (object.health) {
    for (auto &hit_object : object.objects_hit) {
      if (object.is_active) {
        CheckInvincibility(object);
        // Checks that player is alive and not invincible on monster collision.
        if (hit_object->type == ObjectType::kEnemy &&
            object.type == ObjectType::kPlayer &&
            !object.hit_box->is_invincible) {
          if (!object.animation->is_attacking) {
            object.health->health -= 1;
            if (object.health->health == 0) {
              object.is_active = false;
            } else {
              object.hit_box->is_invincible = true;
              object.hit_box->time_since_last_hit_ms = SDL_GetTicks();
            }
          }
        }
        if (hit_object->type == ObjectType::kPlayer &&
            object.type == ObjectType::kEnemy &&
            !object.hit_box->is_invincible &&
            hit_object->animation->is_attacking) {
          object.health->health -= 1;
          std::cout << "Monster Hit!!!!" << std::endl;
          if (object.health->health == 0) {
            object.is_active = false;
          } else {
            object.hit_box->is_invincible = true;
            object.hit_box->time_since_last_hit_ms = SDL_GetTicks();
          }
        }
      }
    }
  }
}

void HealthEngine::CheckInvincibility(GameObject &object) {
  int current_time_ms = SDL_GetTicks();
  int elapsed_time_ms =
      current_time_ms - object.hit_box->time_since_last_hit_ms;
  if (elapsed_time_ms >= 2000)
    object.hit_box->is_invincible = false;
}
