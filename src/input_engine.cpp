#include "input_engine.h"
#include "input_component.h"

void InputEngine::BeginNewFrame() {
  auto &ic = InputComponent::Get();
  ic.left = false;
  ic.right = false;
  ic.up = false;
  ic.down = false;
  pressed_keys.clear();
  released_keys.clear();
}
void InputEngine::KeyUpEvent(SDL_Event &event) {
  released_keys[event.key.keysym.scancode] = true;
  held_keys[event.key.keysym.scancode] = false;
}
void InputEngine::KeyDownEvent(SDL_Event &event) {
  pressed_keys[event.key.keysym.scancode] = true;
  held_keys[event.key.keysym.scancode] = true;
}
int InputEngine::CheckForInput() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      // If the x button on the window was clicked.
    case SDL_QUIT:
      return 1;
      break;
    case SDL_KEYDOWN:
      if (event.key.repeat == 0) {
        KeyDownEvent(event);
      }
      break;
    case SDL_KEYUP:
      KeyUpEvent(event);
      break;
    default:
      break;
    }
  }
  return 0;
}

int InputEngine::Run() {
  BeginNewFrame();
  // IF the x button on the window was clicked.
  if (CheckForInput() == 1) {
    return 1;
  }
  // If escape was clicked, it closes the window.
  if (pressed_keys[SDL_SCANCODE_ESCAPE] == true) {
    return 1;
  }
  if (pressed_keys[SDL_SCANCODE_D] == true ||
      held_keys[SDL_SCANCODE_D] == true) {
    InputComponent::Get().right = true;
  }
  if (pressed_keys[SDL_SCANCODE_A] == true ||
      held_keys[SDL_SCANCODE_A] == true) {
    InputComponent::Get().left = true;
  }
  if (pressed_keys[SDL_SCANCODE_S] == true ||
      held_keys[SDL_SCANCODE_S] == true) {
    InputComponent::Get().down = true;
  }
  if (pressed_keys[SDL_SCANCODE_W] == true ||
      held_keys[SDL_SCANCODE_W] == true) {
    InputComponent::Get().up = true;
  }
  return 0;
}
