#include "health_engine.h"
#include <iostream>

HealthEngine::HealthEngine() {}

HealthEngine::~HealthEngine() {}

void HealthEngine::Run(GameObject &object,
                       std::vector<GameObject> &objects_list) {
  if (object.health) {
    for (auto &hit_object : object.objects_hit) {
      if (object.is_active) {
        CheckInvincibility(object);
        // Checks that player is alive and not invincible on monster collision.
        if (hit_object->type == ObjectType::kEnemy &&
            object.type == ObjectType::kPlayer &&
            !object.hit_box->is_invincible) {
          object.health->health = object.health->health - 1;
          object.hit_box->is_invincible = true;
          object.hit_box->time_since_last_hit_ms = SDL_GetTicks();
          if (object.health->health == 0) { // add && object == enemy
            object.is_active = false;
          }
        }
        if (object.type == ObjectType::kEnemy) {
          object.health->health = 0;
          object.is_active = false;
          srand(time(NULL));
          int drop_chance = rand() % 100;
          if (drop_chance < 33) {
          } else if (drop_chance >= 33 && drop_chance < 66) {
            GameObject green_rupee;
            green_rupee.type = ObjectType::kGreenRupee;
            green_rupee.is_active = true;
            green_rupee.sprite = SpriteComponent(
                "item_sprite", {.x = 5, .y = 87, .w = 8, .h = 14}, 2);
            green_rupee.location = object.location;
            green_rupee.hit_box = HitBoxComponent();
            objects_list.push_back(green_rupee);
          } else if (drop_chance >= 66 && drop_chance < 85) {
            GameObject blue_rupee;
            blue_rupee.type = ObjectType::kBlueRupee;
            blue_rupee.is_active = true;
            blue_rupee.sprite = SpriteComponent(
                "item_sprite", {.x = 42, .y = 87, .w = 8, .h = 14}, 2);
            blue_rupee.location = object.location;
            blue_rupee.hit_box = HitBoxComponent();
            objects_list.push_back(blue_rupee);
          } else {
            GameObject heart;
            heart.type = ObjectType::kHeart;
            heart.is_active = true;
            heart.sprite = SpriteComponent(
                "item_sprite", {.x = 124, .y = 88, .w = 14, .h = 13}, 2);
            heart.location = object.location;
            heart.hit_box = HitBoxComponent();
            objects_list.push_back(heart);
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
  if (elapsed_time_ms >= 2000) {
    object.hit_box->is_invincible = false;
  }
}
