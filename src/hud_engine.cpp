#include "hud_engine.h"

HudEngine::HudEngine() {}
HudEngine::~HudEngine() {}
void HudEngine::Run(GameObject &object, GraphicsEngine &graphics,
                    GameObject player) {
  object.location->coordinates.x = -40;
  object.sprite->sprite_rect = object.hud->hearts;
  for (int i = 0; i < player.health->health; i++) {
    object.location->coordinates.x += 54;
    graphics.Run(object);
  }
}
