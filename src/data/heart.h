#ifndef HEART_H
#define HEART_H

#include "../game_object.h"

struct Heart {
  GameObject LoadHeart(Vector2 location) {
    GameObject heart;
    heart.type = ObjectType::kHeart;
    heart.is_active = true;
    heart.sprite = SpriteComponent(
        "item_sprite", {.x = 124, .y = 88, .w = 14, .h = 13}, 2, Vector2(0, 0));
    heart.location = LocationComponent(location.x, location.y);

    return heart;
  }
};
#endif
