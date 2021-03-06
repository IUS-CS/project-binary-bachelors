#ifndef GRAPHICS_COMPONENT_H
#define GRAPHICS_COMPONENT_H

#include <SDL2/SDL.h>
#include <unordered_map>

// GraphicsComponent.h

struct GraphicsComponent {
  SDL_Window *const window;
  SDL_Renderer *const renderer;
  const std::unordered_map<std::string, SDL_Texture *> textures;

  // Returns the graphics component singleton.
  static GraphicsComponent &Get();

private:
  static GraphicsComponent *instance_;
};
#endif
