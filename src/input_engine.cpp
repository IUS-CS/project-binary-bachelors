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
int InputEngine::Update(LocationComponent &location) {
  BeginNewFrame();
  if (CheckForInput() == 1) {
    return 1;
  }
  if (InputComponent::Get().pressed_keys[SDL_SCANCODE_ESCAPE] == true) {
    return 1;
  }
  if (InputComponent::Get().pressed_keys[SDL_SCANCODE_D] == true ||
      InputComponent::Get().held_keys[SDL_SCANCODE_D] == true) {
    location.location.x += 4;
  } else if (InputComponent::Get().pressed_keys[SDL_SCANCODE_A] == true ||
             InputComponent::Get().held_keys[SDL_SCANCODE_A] == true) {
    location.location.x -= 4;
  } else if (InputComponent::Get().pressed_keys[SDL_SCANCODE_S] == true ||
             InputComponent::Get().held_keys[SDL_SCANCODE_S] == true) {
    location.location.y += 4;
  } else if (InputComponent::Get().pressed_keys[SDL_SCANCODE_W] == true ||
             InputComponent::Get().held_keys[SDL_SCANCODE_W] == true) {
    location.location.y -= 4;
  }
  return 0;
}
