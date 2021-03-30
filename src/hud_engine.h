#ifndef HUD_ENGINE_H
#define HUD_ENGINE_H
#include "game_object.h"
#include "graphics_engine.h"

class HudEngine {
public:
  HudEngine();
  ~HudEngine();
  void Run(GameObject &object, GraphicsEngine &graphics, GameObject player);
};

#endif
