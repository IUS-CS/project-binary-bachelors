#include "input_component.h"

InputComponent *InputComponent::instance_ = nullptr;

InputComponent &InputComponent::Get() {
  if (!instance_) {
    std::unordered_map<SDL_Scancode, bool> pressed_keys;
    std::unordered_map<SDL_Scancode, bool> held_keys;
    std::unordered_map<SDL_Scancode, bool> released_keys;
    instance_ = new InputComponent{pressed_keys, held_keys, released_keys};
  }
  return *instance_;
}
