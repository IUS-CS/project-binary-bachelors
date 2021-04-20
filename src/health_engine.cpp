#include "health_engine.h"
#include "data/blue_rupee.h"
#include "data/green_rupee.h"
#include "data/heart.h"
#include <iostream>
#include <random>

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
            hit_object->animation->is_attacking &&
            !object.hit_box->is_invincible &&
            hit_object->hit_box->is_invincible) {
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
            hit_object->animation->is_attacking &&
            hit_object->hit_box->is_invincible) {
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
          if (object.health->health < 6) {
            object.health->health += 1;
          }
          hit_object->is_active = false;
        }
        if (object.type == ObjectType::kEnemy && object.health->health == 0) {
          object.location->flip = false;
          std::random_device generator;
          std::mt19937 mt(generator());
          std::uniform_int_distribution<int> distribution(0, 99);
          int drop_chance = distribution(mt);
          if (drop_chance < 33) {
          } else if (drop_chance >= 33 && drop_chance < 66) {
            GreenRupee grupee;
            GameObject green_rupee =
                grupee.LoadGreenRupee(object.location->coordinates);
            green_rupee.location = object.location;
            green_rupee.location->coordinates.x +=
                object.sprite->sprite_rect.w * object.sprite->scale / 2 - 8;
            green_rupee.location->coordinates.y +=
                object.sprite->sprite_rect.h * object.sprite->scale - 28;

            objects_list.push_back(green_rupee);
          } else if (drop_chance >= 66 && drop_chance < 85) {
            BlueRupee brupee;
            GameObject blue_rupee =
                brupee.LoadBlueRupee(object.location->coordinates);
            blue_rupee.location->coordinates.x +=
                object.sprite->sprite_rect.w * object.sprite->scale / 2 - 8;
            blue_rupee.location->coordinates.y +=
                object.sprite->sprite_rect.h * object.sprite->scale - 28;
            blue_rupee.hit_box = HitBoxComponent();
            objects_list.push_back(blue_rupee);
          } else {
            Heart heart_data;
            GameObject heart =
                heart_data.LoadHeart(object.location->coordinates);
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
