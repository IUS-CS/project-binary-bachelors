#ifndef HUD_H
#define HUD_H

#include "../game_object.h"

struct Hud {
  GameObject LoadHud() {
    GameObject hud;
    hud.type = ObjectType::kHud;
    hud.is_active = true;
    hud.sprite = SpriteComponent(
        "item_sprite", {.x = 124, .y = 87, .w = 16, .h = 16}, 3, {0, 0});
    hud.location = LocationComponent(16, 16);
    hud.hud = HudComponent({.x = 124, .y = 87, .w = 16, .h = 16},
                           {.x = 141, .y = 4, .w = 16, .h = 15}, "item_sprite",
                           "numbers");
    return hud;
  }
};
#endif
