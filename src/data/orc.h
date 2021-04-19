#ifndef ORC_H
#define ORC_H

#include "../game_object.h"
#include "orc_animations.h"

struct Orc {
  GameObject LoadOrc(Vector2 location) {

    GameObject orc;
    orc.type = ObjectType::kEnemy;
    orc.ai = AIComponent();
    orc.ai->time_of_last_decision_ms = -6000;
    orc.sprite = SpriteComponent(
        "orc_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3, {0, 0});
    orc.location = LocationComponent(location.x, location.y);
    orc.hit_box = HitBoxComponent();
    orc.is_active = true;
    orc.health = HealthComponent(3);
    orc.movement = MovementComponent(2);
    OrcAnimations a_orc;
    orc.animation = AnimationComponent(a_orc.animations);

    return orc;
  }
};
#endif
