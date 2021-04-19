#ifndef GREEN_RUPEE_H
#define GREEN_RUPEE_H

#include "../game_object.h"
#include "green_rupee_animations.h"

struct GreenRupee {
  GameObject LoadGreenRupee(Vector2 location) {

    GameObject green_rupee;
    green_rupee.type = ObjectType::kGreenRupee;
    green_rupee.is_active = true;
    GreenRupeeAnimations a_grupee = GreenRupeeAnimations();
    green_rupee.location = LocationComponent(location.x, location.y);
    green_rupee.sprite = SpriteComponent(
        "item_sprite", {.x = 5, .y = 87, .w = 8, .h = 14}, 2, Vector2(0, 0));
    green_rupee.animation = AnimationComponent(a_grupee.animations);
    green_rupee.hit_box = HitBoxComponent();

    return green_rupee;
  }
};
#endif
