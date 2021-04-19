#ifndef LONK_H
#define LONK_H

#include "../game_object.h"
#include "lonk_animations.h"

struct Lonk {
  GameObject LoadLonk() {

    GameObject lonk;
    lonk.type = ObjectType::kPlayer;
    lonk.sprite = SpriteComponent(
        "lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
    lonk.location = LocationComponent(300, 100);
    lonk.hit_box = HitBoxComponent();
    lonk.is_active = true;
    lonk.health = HealthComponent(6);
    lonk.wallet = WalletComponent();
    lonk.movement = MovementComponent(4);
    LonkAnimations a_lonk;
    lonk.animation = AnimationComponent(a_lonk.animations);

    return lonk;
  }
};
#endif
