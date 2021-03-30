#ifndef MAP_ENGINE_H
#define MAP_ENGINE_H

#include "game_object.h"
#include "graphics_engine.h"

class MapEngine {
public:
  MapEngine();
  ~MapEngine();
  void Run(GameObject &object, GraphicsEngine &graphics_engine);
};
#endif
