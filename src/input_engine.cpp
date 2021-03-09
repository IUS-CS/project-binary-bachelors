#include "input_engine.h"
#include "input_component.h"

void InputEngine::BeginNewFrame() {
  InputComponent::Get().pressed_keys.clear();
  InputComponent::Get().released_keys.clear();
}
void InputEngine::KeyUpEvent(SDL_Event &event) {
  InputComponent::Get().released_keys[event.key.keysym.scancode] = true;
  InputComponent::Get().held_keys[event.key.keysym.scancode] = false;
}
void InputEngine::KeyDownEvent(SDL_Event &event) {
  InputComponent::Get().pressed_keys[event.key.keysym.scancode] = true;
  InputComponent::Get().held_keys[event.key.keysym.scancode] = true;
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

int InputEngine::Run(GameObject &object) {
  BeginNewFrame();
  // IF the x button on the window was clicked.
  if (CheckForInput() == 1) {
    return 1;
  }
  // If escape was clicked, it closes the window.
  if (InputComponent::Get().pressed_keys[SDL_SCANCODE_ESCAPE] == true) {
    return 1;
  }
  if (InputComponent::Get().pressed_keys[SDL_SCANCODE_D] == true ||
      InputComponent::Get().held_keys[SDL_SCANCODE_D] == true) {
    object.location->coordinates.x += 4;
  } else if (InputComponent::Get().pressed_keys[SDL_SCANCODE_A] == true ||
             InputComponent::Get().held_keys[SDL_SCANCODE_A] == true) {
    object.location->coordinates.x -= 4;
  } else if (InputComponent::Get().pressed_keys[SDL_SCANCODE_S] == true ||
             InputComponent::Get().held_keys[SDL_SCANCODE_S] == true) {
    object.location->coordinates.y += 4;
  } else if (InputComponent::Get().pressed_keys[SDL_SCANCODE_W] == true ||
             InputComponent::Get().held_keys[SDL_SCANCODE_W] == true) {
    object.location->coordinates.y -= 4;
  }
  return 0;
}
