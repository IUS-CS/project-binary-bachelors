#ifndef INPUT_ENGINE_H
#define INPUT_ENGINE_H

#include <SDL2/SDL.h>

#include "location_component.h"

class InputEngine {
public:
  void BeginNewFrame();
  void KeyUpEvent(SDL_Event &event);
  void KeyDownEvent(SDL_Event &event);
  void CheckForInput();
  void Update(LocationComponent &location);
};
#endif
