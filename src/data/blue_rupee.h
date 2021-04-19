#ifndef BLUE_RUPEE_H
#define BLUE_RUPEE_H

#include "../game_object.h"
#include "blue_rupee_animations.h"

struct BlueRupee {
  GameObject LoadBlueRupee(Vector2 location) {

    GameObject blue_rupee;
    blue_rupee.type = ObjectType::kBlueRupee;
    blue_rupee.is_active = true;
    BlueRupeeAnimations a_grupee = BlueRupeeAnimations();
    blue_rupee.location = LocationComponent(location.x, location.y);
    blue_rupee.sprite = SpriteComponent(
        "item_sprite", {.x = 5, .y = 87, .w = 8, .h = 14}, 2, Vector2(0, 0));
    blue_rupee.animation = AnimationComponent(a_grupee.animations);
    blue_rupee.hit_box = HitBoxComponent();

    return blue_rupee;
  }
};
#endif
