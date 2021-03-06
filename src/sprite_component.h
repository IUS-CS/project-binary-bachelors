#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "component.h"

#include <SDL2/SDL.h>
#include <string>

class SpriteComponent : public Component {
public:
  std::string sprite_sheet_name = "lonk_sprite";
  SDL_Rect sprite_rect = {.x = 0, .y = 68, .w = 24, .h = 35};
};
#endif
