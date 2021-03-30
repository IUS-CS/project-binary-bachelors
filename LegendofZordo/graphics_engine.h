#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include "game_object.h"

class GraphicsEngine {
public:
  GraphicsEngine();
  ~GraphicsEngine();

  // This function displays what is in the renderer on the screen.
  void DrawNextFrame();

  // This function adds an image/sprite to the renderer.
  void Run(GameObject &object);
};
#endif
