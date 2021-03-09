#ifndef INPUT_ENGINE_H
#define INPUT_ENGINE_H

#include <SDL2/SDL.h>
#include <unordered_map>

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
  int Run();

  // Map that holds all of the current held keys.
  std::unordered_map<SDL_Scancode, bool> held_keys;
  // Map that holds all of the keys that were just pressed.
  std::unordered_map<SDL_Scancode, bool> pressed_keys;
  // Holds all of the keys that have been released.
  std::unordered_map<SDL_Scancode, bool> released_keys;
};
#endif
