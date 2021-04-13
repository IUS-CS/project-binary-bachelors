#include "input_component.h"

InputComponent *InputComponent::instance_ = nullptr;

InputComponent &InputComponent::Get() {
  // If the singleton has not been created yet
  if (!instance_) {
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool pause = false;
    bool quit = false;
    instance_ = new InputComponent{left, right, up, down, pause, quit};
  }
  return *instance_;
}
