#ifndef HUD_COMPONENT_H
#define HUD_COMPONENT_H

#include <string>
#include <SDL2/SDL.h>

struct HudComponent {
  SDL_Rect hearts;
  SDL_Rect wallet_image;
  std::string number_image;
  std::string heart_image;

  HudComponent() {}
  HudComponent(SDL_Rect heart, SDL_Rect wallet, std::string heart_sheet, std::string number_sheet) {
    wallet_image = wallet;
    hearts = heart;
    heart_image = heart_sheet;
    number_image = number_sheet;
  }
};

#endif
