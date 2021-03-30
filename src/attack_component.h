#ifndef ATTACK_COMPONENT_H
#define ATTACK_COMPONENT_H

#include "vector2.h"
#include <SDL2/SDL.h>

struct AttackComponent {
  AttackComponent() {}
  AttackComponent(SDL_Rect rect, Vector2 os) {
    attack = rect;
    offset = os;
  }
  ~AttackComponent() {}
  SDL_Rect attack;
  Vector2 offset;
};

#endif
