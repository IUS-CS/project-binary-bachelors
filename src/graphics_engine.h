#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "location_component.h"
#include "sprite_component.h"

class GraphicsEngine {
public:
  GraphicsEngine();
  ~GraphicsEngine();

  void CreateWindow();

  void DrawNextFrame();

  void AddSprite(const SpriteComponent &sprite,
                 const LocationComponent &location);
};
#endif
