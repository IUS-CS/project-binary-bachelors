#include "hud_engine.h"
#include <iostream>

HudEngine::HudEngine() {}
HudEngine::~HudEngine() {}
void HudEngine::Run(GameObject &object, GraphicsEngine &graphics,
                    GameObject player) {
  object.sprite->sprite_sheet_name = object.hud->heart_image;
  object.sprite->scale = 3;
  object.location->coordinates.y = 16;
  object.location->coordinates.x = -40;
  object.sprite->sprite_rect = object.hud->hearts;
  for (int i = 0; i < player.health->health; i++) {
    object.location->coordinates.x += 54;
    graphics.Run(object);
  }
 
  object.sprite->sprite_sheet_name = object.hud->number_image;
  object.sprite->scale = 3;
  int count = 0;
  int temp = player.wallet->rupees;
  while (temp != 0) {
    int num_to_print = temp % 10;
    object.sprite->sprite_rect = { .x = num_to_print*7, .y = 0, .w = 7, .h = 8 };
    object.location->coordinates.x = 952 - 20 * count;
    temp = temp/10;
    graphics.Run(object);
    count++;
  }

  object.sprite->sprite_sheet_name = object.hud->heart_image;
  object.sprite->sprite_rect = object.hud->wallet_image;
  object.location->coordinates.x = 952 - 24 * count - 10;
  object.location->coordinates.y -= 3;
  object.sprite->scale = 2;
  graphics.Run(object);
}
