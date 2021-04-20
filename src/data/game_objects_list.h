#ifndef GAME_OBJECTS_LIST_H
#define GAME_OBJECTS_LIST_H

#include "hud.h"
#include "lonk.h"
#include "map.h"
#include "orc.h"
#include <vector>

struct GameObjectsList {
  // Create Data Structs.
  Lonk lonk_data;
  Orc orc_data;
  Hud hud_data;
  Map map_data;

  // Create Game Objects.
  GameObject map = map_data.LoadMap();
  GameObject lonk = lonk_data.LoadLonk({300, 100});
  GameObject orc1 = orc_data.LoadOrc({500, 100});
  //  GameObject orc2 = orc_data.LoadOrc({300, 400});
  GameObject hud = hud_data.LoadHud();

  // Vector that will hold all of the objects.
  std::vector<GameObject> objects;

  GameObjectsList() {
    // Creating object list.
    // objects = {map, orc1, orc2, lonk, hud};
    objects = {map, orc1, lonk, hud};
    for (unsigned int i = 0; i < objects.size(); i++) {
      objects[i].id_num = i;
    }
  }
};
#endif
