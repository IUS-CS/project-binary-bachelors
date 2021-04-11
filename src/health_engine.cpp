#include "health_engine.h"

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
          object.health->health = object.health->health - 1;
          if (object.health->health == 0) { //add && enemy
            object.is_active = false;
            DropChance = rand() % 100;
            switch (type) {
            case 33 ... 65: //One Coin
                GameObject GreenRupee;
                rupee.type = ObjectType::kGreenRupee;
                rupee.is_active = true;
                rupee.sprite =
                    SpriteComponent("item_sprite", { .x = 16, .y = 16, .w = 16, .h = 16 }, 3);
                rupee.location = object.location;
                rupee.hit_box = HitBoxComponent();                
                break;
            case 66 ... 85: //Five Coins
                GameObject BlueRupee;
                rupee2.type = ObjectType::kBlueRupee;
                rupee2.is_active = true;
                rupee2.sprite =
                    SpriteComponent("item_sprite2", { .x = 16, .y = 16, .w = 16, .h = 16 }, 3);
                rupee2.location = object.location;
                rupee2.hit_box = HitBoxComponent();
                break;
            case 86 ... 99: //Heart
                GameObject heart;
                heart.type = ObjectType::kHeart;
                heart.is_active = true;
                heart.sprite =
                    SpriteComponent("item_sprite3", { .x = 16, .y = 16, .w = 16, .h = 16 }, 3);
                heart.location = object.location;
                heart.hit_box = HitBoxComponent();
                break;
            default:
                break;
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
