#ifndef INPUT_ENGINE_H
#define INPUT_ENGINE_H

#include <SDL2/SDL.h>

#include "game_object.h"

class InputEngine {
public:
  // This function clears out the pressed_keys and released_keys maps in the
  // InputComponent.
  void BeginNewFrame();
  // This function tells the engine what to do if a key was released.
  void KeyUpEvent(SDL_Event &event);
  // This function tells the engine what to do if a key was pressed.
  void KeyDownEvent(SDL_Event &event);
  // This function checks to see if there has been a KeyUp, KeyDown, or Quit
  // event.
  int CheckForInput();
  // This function will determine which key pressed has the highest priority.
  int Run(GameObject &object);
};
#endif
