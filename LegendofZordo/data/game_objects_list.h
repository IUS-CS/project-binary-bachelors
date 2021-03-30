#ifndef GAME_OBJECTS_LIST_H
#define GMAE_OBJECTS_LIST_H

#include "../game_object.h"

#include <vector>

struct GameObjectsList {
  // Create Objects.
  GameObject map;
  GameObject lonk;
  // GameObject rupee;
  // GameObject rupee2;
  GameObject monster;
  GameObject monster2;

  /*
  GameObject health;
  GameObject health2;
  GameObject health3;
  */

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
    map.is_active = true;

    /*
        // Rupee
        rupee.sprite =
            SpriteComponent("item_sprite", {.x = 18, .y = 87, .w = 8, .h = 14},
       2); rupee.location = LocationComponent(200, 500); rupee.hit_box =
        rupee.is_active = true;

        // Rupee2
        rupee2.sprite =
            SpriteComponent("item_sprite", {.x = 55, .y = 87, .w = 8, .h = 14},
       2); rupee2.location = LocationComponent(600, 500); rupee2.hit_box =
        rupee2.is_active = true;
    */

    // Lonk
    lonk.type = ObjectType::kPlayer;
    lonk.sprite =
        SpriteComponent("lonk_sprite", {.x = 16, .y = 16, .w = 16, .h = 16}, 3);
    lonk.location = LocationComponent(0, 100);
    lonk.hit_box = HitBoxComponent();
    lonk.is_active = true;
    lonk.health = HealthComponent();
    lonk.movement = MovementComponent(4);

    // Monster
    monster.type = ObjectType::kEnemy;
    monster.ai = AIComponent();
    monster.sprite = SpriteComponent("monster_sprite",
                                     {.x = 16, .y = 13, .w = 16, .h = 19}, 3);
    monster.location = LocationComponent(500, 100);
    monster.hit_box = HitBoxComponent();
    monster.is_active = true;
    monster.movement = MovementComponent(3);

    // Monster2
    monster2.type = ObjectType::kEnemy;
    monster2.ai = AIComponent();
    monster2.sprite = SpriteComponent("monster_sprite",
                                      {.x = 16, .y = 13, .w = 16, .h = 19}, 3);
    monster2.location = LocationComponent(300, 400);
    monster2.hit_box = HitBoxComponent();
    monster2.is_active = true;
    monster2.movement = MovementComponent(3);

    /*
    // health
    health.sprite =
        SpriteComponent("item_sprite", {.x = 118, .y = 87, .w = 24, .h = 14},
    2); health.location = LocationComponent(10, 10); health.is_active = true;

    // health2
    health2.sprite =
        SpriteComponent("item_sprite", {.x = 118, .y = 87, .w = 24, .h = 14},
    2); health2.location = LocationComponent(40, 10); health2.is_active = true;

    // health3
    health3.sprite =
        SpriteComponent("item_sprite", {.x = 118, .y = 87, .w = 24, .h = 14},
    2); health3.location = LocationComponent(70, 10); health3.is_active = true;
    */

    // Creating object vector
    objects = {map, monster, monster2, lonk};
    for (unsigned int i = 0; i < objects.size(); i++) {
      objects[i].id_num = i;
    }
  }
};
#endif