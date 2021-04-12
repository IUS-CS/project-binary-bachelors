#include "hud_engine.h"
#include <iostream>

HudEngine::HudEngine() {}
HudEngine::~HudEngine() {}
void HudEngine::Run(GameObject &object, GraphicsEngine &graphics,
                    GameObject player) {
  object.sprite->sprite_sheet_name = object.hud->heart_image;
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
    std::cout << "Hit!" << std::endl;
    int num_to_print = temp % 10;
    object.sprite->sprite_rect = { .x = num_to_print*8, .y = 0, .w = 8, .h = 10 };
    object.location->coordinates.x = 952 - 24 * count;
    object.location->coordinates.y = 15;
    temp = temp/10;
    graphics.Run(object);
    count++;
  }
}
