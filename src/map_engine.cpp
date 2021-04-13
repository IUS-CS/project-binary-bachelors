#include "map_engine.h"
#include "graphics_engine.h"

MapEngine::MapEngine() {}
MapEngine::~MapEngine() {}
void MapEngine::Run(GameObject &object, GraphicsEngine &graphics) {
  if (object.map) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 31; j++) {
        int tile_id = object.map->level[i][j];
        switch (tile_id) {
        case 0:
          object.sprite->sprite_rect.x = 16;
          object.sprite->sprite_rect.y = 16;
          break;
        case 1:
          object.sprite->sprite_rect.x = 16;
          object.sprite->sprite_rect.y = 0;
          break;
        case 2:
          object.sprite->sprite_rect.x = 0;
          object.sprite->sprite_rect.y = 16;
          break;
        case 3:
          object.sprite->sprite_rect.x = 0;
          object.sprite->sprite_rect.y = 0;
          break;
        case 4:
          object.sprite->sprite_rect.x = 16;
          object.sprite->sprite_rect.y = 32;
          break;
        case 5:
          object.sprite->sprite_rect.x = 0;
          object.sprite->sprite_rect.y = 48;
          break;
        case 6:
          object.sprite->sprite_rect.x = 16;
          object.sprite->sprite_rect.y = 48;
          break;
        case 7:
          object.sprite->sprite_rect.x = 0;
          object.sprite->sprite_rect.y = 32;
          break;
        default:
          break;
        }
        object.location->coordinates.x = j * 32;
        object.location->coordinates.y = i * 32;
        graphics.Run(object);
      }
    }
  }
}
