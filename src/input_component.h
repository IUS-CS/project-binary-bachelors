#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <SDL2/SDL.h>
#include <unordered_map>

// IMPORTANT: InputComponent is a singleton!
struct InputComponent {
  // Map that holds all of the current held keys.
  std::unordered_map<SDL_Scancode, bool> held_keys;
  // Map that holds all of the keys that were just pressed.
  std::unordered_map<SDL_Scancode, bool> pressed_keys;
  // Holds all of the keys that have been released.
  std::unordered_map<SDL_Scancode, bool> released_keys;

  // Get the instance of this singleton.
  static InputComponent &Get();

private:
  // This is the one instance of this object.
  static InputComponent *instance_;
};
#endif
