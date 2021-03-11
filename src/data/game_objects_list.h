#ifndef GAME_OBJECTS_LIST_H
#define GMAE_OBJECTS_LIST_H

#include "../game_object.h"

#include <vector>

struct GameObjectsList {
  // Create Objects.
  GameObject map;
  GameObject lonk;
  GameObject rupee;
  GameObject rupee2;

  // Vector that will hold all of the objects.
  std::vector<GameObject> objects;
  // Intialize Objects.
  // Map
  GameObjectsList() {
    map.type = ObjectType::kMap;
    map.sprite =
        SpriteComponent("tile_map", {.x = 0, .y = 0, .w = 16, .h = 16}, 2);
    map.location = LocationComponent(0, 0);
    int lvl1[20][31] = {{0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                         2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                        {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                         3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                        {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                         3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                        {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                         0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                        {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                         2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                        {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                         3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                        {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                         3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                        {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                         0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                        {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 6, 5, 4, 0, 1,
                         2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                        {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 7, 4, 6, 2, 4, 1,
                         3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                        {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 4, 6, 7, 0,
                         3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                        {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                         0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                        {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                         2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                        {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                         3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                        {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                         3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                        {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                         0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1},
                        {0, 3, 1, 2, 0, 2, 3, 1, 0, 0, 2, 1, 0, 3, 0, 1,
                         2, 3, 1, 3, 2, 0, 2, 0, 3, 0, 1, 2, 1, 0, 3},
                        {3, 2, 3, 0, 1, 3, 3, 2, 0, 1, 3, 1, 0, 2, 0, 1,
                         3, 1, 2, 1, 0, 3, 2, 1, 2, 3, 0, 1, 3, 0, 2},
                        {2, 1, 1, 3, 0, 2, 1, 3, 2, 0, 1, 0, 3, 1, 2, 0,
                         3, 1, 0, 0, 2, 3, 0, 1, 0, 2, 1, 3, 0, 2, 3},
                        {2, 1, 0, 2, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3,
                         0, 2, 2, 0, 1, 3, 2, 1, 2, 0, 1, 3, 0, 0, 1}};
    map.map = MapComponent(lvl1);

    // Rupee
    rupee.sprite =
        SpriteComponent("item_sprite", {.x = 18, .y = 87, .w = 8, .h = 14}, 2);
    rupee.location = LocationComponent(200, 500);
    rupee.hit_box = HitBoxComponent();
    rupee.hit_box->type = HitBoxType::kRupee;

    // Rupee2
    rupee2.sprite =
        SpriteComponent("item_sprite", {.x = 18, .y = 87, .w = 8, .h = 14}, 2);
    rupee2.location = LocationComponent(600, 500);
    rupee2.hit_box = HitBoxComponent();

    // Lonk
    lonk.type = ObjectType::kPlayer;
    lonk.sprite =
        SpriteComponent("lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3);
    lonk.location = LocationComponent(0, 100);
    lonk.hit_box = HitBoxComponent();

    // Creating object vector
    objects = {map, rupee, rupee2, lonk};
  }
};
#endif
