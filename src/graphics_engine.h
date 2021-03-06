#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "location_component.h"
#include "sprite_component.h"

class GraphicsEngine {
public:
  GraphicsEngine();
  ~GraphicsEngine();

  // This function displays what is in the renderer on the screen.
  void DrawNextFrame();

  // This function adds an image/sprite to the renderer.
  void AddSprite(const SpriteComponent &sprite,
                 const LocationComponent &location);
};
#endif
