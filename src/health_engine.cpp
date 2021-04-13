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
            // hit_object->animation->is_attacking &&
            !object.hit_box->is_invincible) {
          if (!object.animation->is_attacking) {
            object.health->health -= 1;
            object.hit_box->is_hit = true;
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
        if (hit_object->type == ObjectType::kHeart &&
            object.type == ObjectType::kPlayer) {
          object.health->health += 1;
          hit_object->is_active = false;
        }
        if (object.type == ObjectType::kEnemy && object.health->health == 0) {
          srand(time(NULL));
          int drop_chance = rand() % 100;
          if (drop_chance < 33) {
          } else if (drop_chance >= 33 && drop_chance < 66) {
            GameObject green_rupee;
            green_rupee.type = ObjectType::kGreenRupee;
            green_rupee.is_active = true;
            green_rupee.sprite = SpriteComponent(
                "item_sprite", {.x = 5, .y = 87, .w = 8, .h = 14}, 2,
                Vector2(0, 0));
            green_rupee.location = object.location;
            green_rupee.location->coordinates.x +=
                object.sprite->sprite_rect.w * object.sprite->scale / 2 - 8;
            green_rupee.location->coordinates.y +=
                object.sprite->sprite_rect.h * object.sprite->scale - 28;
            green_rupee.hit_box = HitBoxComponent();
            objects_list.push_back(green_rupee);
          } else if (drop_chance >= 66 && drop_chance < 85) {
            GameObject blue_rupee;
            blue_rupee.type = ObjectType::kBlueRupee;
            blue_rupee.is_active = true;
            blue_rupee.sprite = SpriteComponent(
                "item_sprite", {.x = 42, .y = 87, .w = 8, .h = 14}, 2,
                Vector2(0, 0));
            blue_rupee.location = object.location;
            blue_rupee.location->coordinates.x +=
                object.sprite->sprite_rect.w * object.sprite->scale / 2 - 8;
            blue_rupee.location->coordinates.y +=
                object.sprite->sprite_rect.h * object.sprite->scale - 28;
            blue_rupee.hit_box = HitBoxComponent();
            objects_list.push_back(blue_rupee);
          } else {
            GameObject heart;
            heart.type = ObjectType::kHeart;
            heart.is_active = true;
            heart.sprite = SpriteComponent(
                "item_sprite", {.x = 124, .y = 88, .w = 14, .h = 13}, 2,
                Vector2(0, 0));
            heart.location = object.location;
            heart.location->coordinates.x +=
                object.sprite->sprite_rect.w * object.sprite->scale / 2 - 14;
            heart.location->coordinates.y +=
                object.sprite->sprite_rect.h * object.sprite->scale - 26;
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
