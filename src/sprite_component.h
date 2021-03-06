#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "component.h"

#include <SDL2/SDL.h>
#include <string>

// A SpriteComponent is the image of a GameObject. Ex: The SpriteComponent for
// Lonk (the knockoff of Link) will be the picture of his character.
class SpriteComponent : public Component {
public:
  // This is the string of the name of the spritesheet where this image exists.
  // These spritesheets are stored in the assets/ folder.
  std::string sprite_sheet_name = "lonk_sprite";
  // An SDL_Rect is just some information to create a rectangle. This particular
  // rectangle is the rectangle where the image exists in this sprite's
  // spritesheet. x and y establish where the top left corner of the rectangle
  // is located, and then the width and height help establish where the rest of
  // the corners are.
  SDL_Rect sprite_rect = {.x = 0, .y = 68, .w = 24, .h = 35};
};
#endif
