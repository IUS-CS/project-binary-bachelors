#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <SDL2/SDL.h>
#include <unordered_map>

struct InputComponent {
  std::unordered_map<SDL_Scancode, bool> held_keys;
  std::unordered_map<SDL_Scancode, bool> pressed_keys;
  std::unordered_map<SDL_Scancode, bool> released_keys;

  static InputComponent &Get();

private:
  static InputComponent *instance_;
};
#endif
