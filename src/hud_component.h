#ifndef HUD_COMPONENT_H
#define HUD_COMPONENT_H

#include <SDL2/SDL.h>

struct HudComponent {
  SDL_Rect hearts;
  SDL_Rect rupees;

  HudComponent() {}
  HudComponent(SDL_Rect heart, SDL_Rect rupee) {
    hearts = heart;
    rupees = rupee;
  }
};

#endif
