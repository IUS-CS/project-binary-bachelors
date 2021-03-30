#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include <SDL.h>
#include <unordered_map>

// IMPORTANT: InputComponent is a singleton!
struct InputComponent {
  // Get the instance of this singleton.
  static InputComponent &Get();
  bool left;
  bool right;
  bool up;
  bool down;
  bool quit;

private:
  // This is the one instance of this object.
  static InputComponent *instance_;
};
#endif
